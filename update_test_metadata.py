import os
import shutil
import subprocess

labs = [x for x in os.listdir() if not os.path.isfile(x) and "Lab" in x]
file = open("meta-data.candidate.json", "w")
file.write("[")
id = 0
tests = sorted(os.listdir(os.path.join("base","test")))
private_tests = sorted(os.listdir(os.path.join("base","private_tests")))
root = os.getcwd()

deletion_list = set()

def write_entry(file, id, tests, lab, problem_id):
    problem_id,name = problem_id.split("-")
    bug_id = name

    problem_tests = list(
        filter(lambda x: x.startswith(f'in.{problem_id}'), tests))
    
    private_problem_tests = list(
        filter(lambda x: x.startswith(f'in.{problem_id}'), private_tests))
    

    test_input_list = list(f'"test/{x}"'
                        for x in os.listdir(os.path.join("base", "test"))
                        if problem_id in x and "in" in x)

    private_test_input_list = list(f'"private_tests/{x}"'
                        for x in os.listdir(os.path.join("base", "private_tests"))
                        if problem_id in x and "in" in x)

    test_list = list(map(lambda x: f'"{x.split(".")[2]}"', problem_tests))
    private_test_list = list(map(lambda x: f'"{x.split(".")[2]}"', private_problem_tests))

    dst = os.path.join(lab, "{}-{}".format(problem_id, name))

    #Setup the local scripts to get test metadata
    shutil.copy("build_subject_local", os.path.join(dst,"build_subject"))
    shutil.copy("run_test_local", os.path.join(dst,"run_test"))
    shutil.copy("run_private_tests_local.sh", os.path.join(dst,"run_private_tests"))
    
    os.chdir(dst)
    os.system("./build_subject") 
    
    passing_test_identifiers =[]
    failing_test_identifiers =[]

    filtered_tests = []
    
    for (test,test_file) in zip(test_list,problem_tests):
        x = os.system("./run_test {}".format(test))
        print("Response is {}".format(x))
        if x == 0:
            passing_test_identifiers.append(test)
            filtered_tests.append(test_file)
        elif x == 0x300:
            failing_test_identifiers.append(test)
            filtered_tests.append(test_file)
        elif x == 0x200:
            print("Gotta remove test {}.{}".format(problem_id,test))
            deletion_list.add((problem_id,test))
        else:
            print("UNKNOWN ERROR")
            input()

    for test in private_test_list:
        x = os.system("./run_private_tests {}".format(test))
        print("Private test Response is {}".format(x))
        if x == 0 or x == 0x100 or x == 0x300:
            pass
        elif x == 0x200:
            print("Gotta remove test {}.{}".format(problem_id,test))
            deletion_list.add((problem_id,test))
            #input()
        else:
            print("Return code {}".format(x))
            input()

    os.system("rm {}".format(name))
    os.system("rm Main")
            
    os.chdir(root)

    #Setup the proper scripts
    shutil.copy("build_subject", dst)
    shutil.copy("run_test", dst)
    shutil.copy("run_private_tests.sh", dst)
    #input()

    #print(failing_test_identifiers,passing_test_identifiers)
    data = """
    {{
        "id":{id},
        "subject":"{lab}",
        "bug_id":"{problem_id}-{name}",
        "binary_path": "{bug_id}",
        "source_file": "{bug_id}_buggy.c",
        "reference_file": "Main.c",
        "line_numbers": [],
        "failing_test_identifiers": [{failing_test_identifiers}],
        "passing_test_identifiers": [{passing_test_identifiers}],
        "count_neg": {failing_test_identifiers_count},
        "count_pos": {passing_test_identifiers_count},
        "binary_args": "",
        "exploit_file_list": [{inputs}],
        "test_timeout": 5,
        "bug_type": "Test Failure",
        "language": "c",
        "config_script": "config_subject",
        "build_script": "build_subject",
        "test_script": "run_test",
        "pvt_test_script": "run_private_tests.sh"
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
        tests=','.join(filtered_tests)
    )
    #print(data)
    file.write(data)
    

for lab in labs:
    problems = sorted(os.listdir(lab))
    for problem_id in problems:
        if problem_id in ['.aux','base']:
            continue
        id = id + 1
        if id < 20:
            continue
        write_entry(file, id, tests, lab, problem_id)

print("TIME TO DELETEE!!")
input()
for (problem_id,test) in deletion_list:
    os.system("cd {} && find . | grep .{}.{}.txt | xargs rm ".format(root,problem_id,test))
    
file.write("]")
file.close()
