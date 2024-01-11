#!/bin/bash
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
benchmark_name=$(echo $script_dir | rev | cut -d "/" -f 3 | rev)
project_name=$(echo $script_dir | rev | cut -d "/" -f 2 | rev)
bug_id=$(echo $script_dir | rev | cut -d "/" -f 1 | rev)
dir_name=~/$benchmark_name/$project_name/$bug_id
subject_name=$(echo $bug_id | cut -d "-" -f 2)
problem_name=$(echo $bug_id | cut -d "-" -f 1)
dir_test=~/$benchmark_name/base/private_tests
TEST_ID=$1

EXIT_CODE=0
export ASAN_OPTIONS=detect_leaks=0

exists() {
    [ -e "$1" ]
}

if ! exists $dir_test/in.${problem_name}.*.txt; then
    echo "No private tests found. Skipping..."
    exit 0
fi

if [ -z "$TEST_ID" ];
then
    for x in $dir_test/in.${problem_name}.*.txt;
    do
        TEST_ID=$(echo $x | rev | cut -d "/" -f 1 | rev | cut -d "." -f 3)
        TEST_CASE=$dir_test/in.${problem_name}.${TEST_ID}.txt

        timeout -k 2s 2s ${dir_name}/Main < $TEST_CASE > /tmp/reference-${problem_name}.txt
        EXIT_CODE=$?
        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL REFERENCE"
            exit 2;
        fi;

        cd $dir_test

        timeout -k 2s 2s ${dir_name}/${subject_name} < $TEST_CASE > /tmp/submission-${problem_name}.txt
        EXIT_CODE=$?
        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL"
            exit 3;
        fi;
        
	diff -u /tmp/reference-${problem_name}.txt /tmp/submission-${problem_name}.txt
        EXIT_CODE=$?
        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL"
            break;
        fi;
    done
else
    TEST_CASE=$dir_test/in.${problem_name}.${TEST_ID}.txt
    TEST_OUTPUT=$dir_test/out.${problem_name}.${TEST_ID}.txt

    timeout -k 2s 2s ${dir_name}/Main < $TEST_CASE > /tmp/reference-${problem_name}.txt
        EXIT_CODE=$?
        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL REFERENCE"
            exit 2;
        fi;

    timeout -k 2s 2s ${dir_name}/${subject_name} < $TEST_CASE > /tmp/submission-${problem_name}.txt
        EXIT_CODE=$?
        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL"
            exit 3;
        fi;

    diff -u /tmp/reference-${problem_name}.txt /tmp/submission-${problem_name}.txt > /dev/null
    EXIT_CODE=$?

        if [[ EXIT_CODE -ne 0 ]]
        then
            echo "FAIL"
            exit 3;
        fi;

    for exec in $(seq 1 5);
    do
        echo "PRIVATE CONSISTENCY CHECK $exec"
        timeout -k 2s 2s ${dir_name}/${subject_name} < $TEST_CASE > /tmp/submission-consistencty-${problem_name}.txt
        
        diff -u /tmp/output-${problem_name}.txt /tmp/submission-consistencty-${problem_name}.txt > /dev/null
        EXIT_CODE_CONSISTENCY=$?
        if [[ EXIT_CODE_CONSISTENCY -ne 0 ]]
        then
            echo "FAIL PRIVATE CONSISTENCY CHECK";
            exit 2
        fi;
    done;
fi

echo "EXITING WITH $EXIT_CODE"
exit $EXIT_CODE
