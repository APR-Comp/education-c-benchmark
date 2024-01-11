import os
import sys
import shutil
import subprocess
import re
from random import randint

max_extra_tests = 40
labs = sorted([x for x in os.listdir() if not os.path.isfile(x) and "Lab" in x])
id = 0
root = os.getcwd()

#os.system("bash -c 'rm -rf testcases/*'")
radamsa_call = "radamsa -m num=100,lrs,lis,ls,lp,lr2,lr,li,bei,bed,bp,br,bd,sr,sd {input_file} > {output_file}"

if len(sys.argv) < 2:
    print("Select public or private tests")
    exit(1)

choice = sys.argv[1]

number_of_outputs = {
    "private": 100,
    "public": 20,
}

os.system("rm -rf testcases")

for lab in labs:
    bug_ids = sorted(os.listdir(lab))
    try:
        bug_ids.remove("base")
    except:
        pass
    problem_map = {bug_id.split("-")[0]: bug_id for bug_id in bug_ids}
    problems = sorted(list(set(map(lambda x: x.split("-")[0], bug_ids))))

    for problem in problems:
        print("Preparing tests for problem {}".format(problem))
        max_test_value = (
            max(
                list(
                    int(x.split(".")[2])
                    for x in os.listdir(os.path.join("base", "test"))
                    if problem in x and "in" in x and re.match("\d+",x.split(".")[2])
                )
            )
            + 1
        )
        in_format = "in.{}.{}.txt"
        out_format = "out.{}.{}.txt"
        print(problem, problem_map[problem])
        os.makedirs(f"testcases/{problem}", exist_ok=True)

        shutil.copy(
            f"{lab}/{problem_map[problem]}/Main.c", f"testcases/{problem}/Main.c"
        )

        shutil.rmtree(f"testcases/{problem}/inputs", ignore_errors=True)
        os.mkdir(f"testcases/{problem}/inputs")

        os.system(
            f"bash -c 'cp base/test/in.{problem}.*.txt testcases/{problem}/inputs/' "
        )

        os.chdir(os.path.join("testcases", problem))
        os.makedirs("new_inputs",exist_ok=True)
        os.makedirs("new_outputs",exist_ok=True)
        
        print(os.getcwd())
        os.system("gcc -lm Main.c -o Main")
        for input_file in os.listdir("inputs/"):
            if max_test_value == number_of_outputs[choice] + 1:
                break
            for _ in range(number_of_outputs[choice]):
                new_input = os.path.join("new_inputs",in_format.format(problem,f"{choice}_{max_test_value}"))
                new_output = os.path.join("new_outputs",out_format.format(problem,f"{choice}_{max_test_value}"))
                func = radamsa_call.format(input_file=os.path.join("inputs",input_file),output_file=new_input)
                print(func)
                os.system(func)
                
                func = f"timeout -k 5s 10s ./Main < {new_input} > {new_output} "
                print(func)
                ret_code = os.system(func)
                print("Return code is {}".format(ret_code))
                to_delete = False
                if ret_code != 0:
                    to_delete = True
                else:
                    with open(new_output) as f:
                        try:
                            if len(f.read()) == 0:
                                print("Deleting input that has no output")
                                to_delete = True
                        except:
                            to_delete = True
                    for consistency_run in range(20):
                        print("Consistency run {}".format(consistency_run))
                        ret_code = os.system(f"timeout -k 5s 10s ./Main < {new_input} > {new_output}_temp")
                        if ret_code != 0:
                            to_delete = True
                            break
                        else:
                            ret_code = os.system(f"diff {new_output} {new_output}_temp")
                            if ret_code != 0:
                                print("Input diverges")
                                to_delete = True
                                break
                if not to_delete:
                    max_test_value = max_test_value + 1
                else:
                    os.system(f"rm {new_input}")
                    os.system(f"rm {new_output}")
                    
                if max_test_value == number_of_outputs[choice] + 1:
                    break
                
            print("Finished run")
            #input()
        #os.system("AFL_NO_UI=1 timeout 1m afl-fuzz -i inputs -o outputs ./Main")


        #outputs = os.listdir(os.path.join("outputs", "default", "queue"))

        test_dir = 'test' if choice == 'public' else 'private_tests'

        os.chdir(root)
        os.makedirs(os.path.join('base',test_dir),exist_ok=True)
        os.system(f"cp {os.path.join('testcases',problem,'new_inputs','*')} {os.path.join('base',test_dir,'')}")
        os.system(f"cp {os.path.join('testcases',problem,'new_outputs','*')} {os.path.join('base',test_dir,'')}")
        print("Updated cases")
        
        # for new_test in new_tests:
        #     print(
        #         os.path.join(
        #             "testcases", problem, "outputs", "default", "queue", new_test
        #         ),
        #         os.path.join("base", "test", in_format.format(problem, max_test_value)),
        #     )
        #     shutil.copy(
        #         os.path.join(
        #             "testcases", problem, "outputs", "default", "queue", new_test
        #         ),
        #         os.path.join("base", "test", in_format.format(problem, max_test_value)),
        #     )

        #     cmd = "timeout 5s {} < {} > {} ".format(
        #         os.path.join("testcases", problem, "Main"),
        #         os.path.join("base", "test", in_format.format(problem, max_test_value)),
        #         os.path.join(
        #             "base", "test", out_format.format(problem, max_test_value)
        #         ),
        #     )

        #     ret = os.system(cmd)

        #     if ret != 0:
        #         shutil.rmtree(
        #             os.path.join(
        #                 "base", "test", in_format.format(problem, max_test_value)
        #             ),ignore_errors=True
        #         )
        #         shutil.rmtree(
        #             os.path.join(
        #                 "base", "test", out_format.format(problem, max_test_value)
        #             ),ignore_errors=True
        #         )

        #     max_test_value += 1

        # input()
