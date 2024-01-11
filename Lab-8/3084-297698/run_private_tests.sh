#!/bin/bash
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
benchmark_name=$(echo $script_dir | rev | cut -d "/" -f 3 | rev)
project_name=$(echo $script_dir | rev | cut -d "/" -f 2 | rev)
bug_id=$(echo $script_dir | rev | cut -d "/" -f 1 | rev)
dir_name=/experiment/$benchmark_name/$project_name/$bug_id
subject_name=$(echo $bug_id | cut -d "-" -f 2)
problem_name=$(echo $bug_id | cut -d "-" -f 1)
dir_test=$dir_name/base/private_tests

EXIT_CODE=0

export ASAN_OPTIONS=detect_leaks=0

exists() {
    [ -e "$1" ]
}

if ! exists $dir_test/in.${problem_name}.*.txt; then
    echo "No private tests found. Skipping..."
    exit 0
fi

for x in $dir_test/in.${problem_name}.*.txt;
do
    TEST_ID=$(echo $x | rev | cut -d "/" -f 1 | rev | cut -d "." -f 3)
    TEST_OUTPUT=$dir_test/out.${problem_name}.${TEST_ID}.txt
    TEST_CASE=$dir_test/in.${problem_name}.${TEST_ID}.txt
    cd $dir_test

    gcc ${dir_name}/src/Main.c -o ${dir_name}/src/Main -lm

    timeout -k 5s 20s ${dir_name}/src/Main < $TEST_CASE > /tmp/reference-${subject_name}-${problem_name}.txt

    timeout -k 5s 10s ${dir_name}/src/${subject_name} < $TEST_CASE > /tmp/out-${subject_name}-${problem_name}.txt

    diff -u /tmp/reference-${subject_name}-${problem_name}.txt /tmp/out-${subject_name}-${problem_name}.txt
    EXIT_CODE=$?
    if [[ EXIT_CODE -ne 0 ]]
    then
        echo "FAIL"
        break;
    fi;
done



exit $EXIT_CODE