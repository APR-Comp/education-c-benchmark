import os
import shutil
import subprocess

labs = [x for x in os.listdir() if not os.path.isfile(x) and "Lab" in x]

def execute_command(command: str, show_output=True, env=dict(), directory=None):
    # Print executed command and execute it in console
    command = command.encode().decode("ascii", "ignore")
    if not directory:
        directory = os.getcwd()
        print_command = command
    else:
        print_command = "[{}] {}".format(directory, command)
    print(print_command)
    command = "{{ {} ;}} 2> {}".format(command, "oof.log")
    if not show_output:
        command += " > /dev/null"
    # print(command)
    new_env = os.environ.copy()
    new_env.update(env)
    process = subprocess.Popen(
        [command], stdout=subprocess.PIPE, shell=True, env=new_env, cwd=directory
    )
    (output, error) = process.communicate()
    #print(output)
    #print(error)
    # out is the output of the command, and err is the exit value
    return int(process.returncode)

def identity_op(lab,problem, bug_id):
    execute_command(
        f"cp {lab}/{problem}/{bug_id}_buggy.c outputs/id_wrong_{lab}_{problem}_{bug_id}.py", True
    )


def syntactic_mutation(lab,problem, bug_id):
    execute_command(
        f"bash -c 'java -jar transformer.java {lab}/{problem}/{bug_id}_buggy.c syntax > outputs/syn_wrong_{lab}_{problem}_{bug_id}.c'", True
    )
    execute_command(f"cp outputs/syn_wrong_{lab}_{problem}_{bug_id}.c {lab}/{problem}/{bug_id}_buggy.c ",True)

def semantic_mutation(lab,problem, bug_id):
    execute_command(
        f"bash -c 'java -jar transformer.java {lab}/{problem}/{bug_id}_buggy.c semantics > outputs/sem_wrong_{lab}_{problem}_{bug_id}.c'", True
    )
    execute_command(f"cp outputs/sem_wrong_{lab}_{problem}_{bug_id}.c {lab}/{problem}/{bug_id}_buggy.c ",True)


def semantic_mutation_correct(lab,problem, bug_id):
    pass
    execute_command(f"bash -c 'java -jar transformer.java {lab}/{problem}/Main.c semantics > outputs/wc_{lab}_{problem}_{bug_id}.c'",True)
    execute_command(f"cp outputs/wc_{lab}_{problem}_{bug_id}.c {lab}/{problem}/{bug_id}_buggy.c ",True)


file = open("meta-data.candidate.json", "w")
file.write("[")
id = 0
tests = sorted(os.listdir(os.path.join("base","test")))
root = os.getcwd()

def write_entry(file, id, tests, lab, problem_id):
    problem_id,name = problem_id.split("-")
    bug_id = name

    problem_tests = list(
        filter(lambda x: x.startswith(f'in.{problem_id}'), tests))

    test_input_list = list(f'"test/{x}"'
                        for x in os.listdir(os.path.join("base", "test"))
                        if problem_id in x and "in" in x)

    test_list = list(map(lambda x: f'"{x.split(".")[2]}"', problem_tests))

    dst = os.path.join(lab, "{}-{}".format(problem_id, name))

    os.chdir(dst)
    os.system("./build_subject") 
    
    passing_test_identifiers =[]
    failing_test_identifiers =[]
    
    for test in test_list:
        x = os.system("./run_test {}".format(test))
        #print("Response is {}".format(x))
        if x == 0:
            passing_test_identifiers.append(test)
        else:
            failing_test_identifiers.append(test)
    os.system("rm {}".format(name))
            
    os.chdir(root)

    #Setup the proper scripts
    shutil.copy("build_subject", dst)
    shutil.copy("run_test", dst)

    #print(failing_test_identifiers,passing_test_identifiers)
    data = """
    {{
        "id":{id},
        "subject":"{lab}",
        "bug_id":"{problem_id}-{name}",
        "source_file": "{bug_id}_buggy.c",
        "reference_file": "Main.c",
        "line_numbers": [],
        "failing_test_identifiers": [{failing_test_identifiers}],
        "passing_test_identifiers": [{passing_test_identifiers}],
        "count_neg": {failing_test_identifiers_count},
        "count_pos": {passing_test_identifiers_count},
        "binary_path": "",
        "binary_args": "",
        "exploit_file_list": [{inputs}],
        "test_timeout": 5,
        "bug_type": "Test Failure",
        "language": "c",
        "config_script": "config_subject",
        "build_script": "build_subject",
        "test_script": "run_test"
    }},
    """.format(
        id=id,
        lab=lab,
        name=name,
        problem_id=problem_id,
        bug_id=bug_id,
        correct_file=name+"_correct.c",
        inputs=",".join(test_input_list),
        passing_test_identifiers_count=len(passing_test_identifiers),
        failing_test_identifiers_count=len(failing_test_identifiers),
        failing_test_identifiers=','.join(failing_test_identifiers),
        passing_test_identifiers=','.join(passing_test_identifiers),
        tests=','.join(test_list)
    )
    #print(data)
    file.write(data)

for lab in labs:
    problems = sorted(os.listdir(lab))
    filtered_problems = []
    for problem in problems:
        if "-" not in problem:
            shutil.rmtree(os.path.join(lab,problem))
        else:
            filtered_problems.append(problem)

    selected_problems = []
    for index,problem_id in enumerate(filtered_problems):
        if len(selected_problems) == 10 or index % 3 != 1:
            shutil.rmtree(os.path.join(lab,problem_id))
            continue
        
        selected_problems.append(problem_id)
    

    original, syntax, mutate_broken, mutate_original = selected_problems[0:3], selected_problems[3:6],selected_problems[6:8],selected_problems[8:]
    
    for (mutation,problem_set) in zip([identity_op,syntactic_mutation,semantic_mutation,semantic_mutation_correct],[original, syntax, mutate_original, mutate_broken]) :
        for problem_id in problem_set:
            id = id + 1
            mutation(lab,problem_id,problem_id.split('-')[1])
            #if mutation != identity_op:
            #    input()
            write_entry(file, id, tests, lab, problem_id)

    
file.write("]")
file.close()
