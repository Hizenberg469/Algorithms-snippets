#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Provide the limit of stress testing"
    echo "$0 'test case limit'"
    echo "$0 -1 (for unlimited)"
    exit 1
fi

#Required tools
SOLUTION=build/solution
GENERATOR=build/generator
BRUTEFORCE=build/bruteForce

#Build necessary things
make all

#Files
TESTCASE_FILE=IOFiles/testcase.txt
OUTPUT_FILE=IOFiles/output.txt
CORRECT_ANSWER_FILE=IOFiles/correct_answer.txt

pass_count=0

while (( 1 ))
do
    ./generator > $TESTCASE_FILE
    ./SOLUTION < $TESTCASE_FILE > $OUTPUT_FILE
    ./BRUTEFORCE < $TESTCASE_FILE > $CORRECT_ANSWER_FILE

    if diff -q -Z $OUTPUT_FILE $CORRECT_ANSWER_FILE >> /dev/null; then
        echo -e "\033[0;31mTest #$(($pass_count+1)): FAIL\033[0m"
        echo "Test case:"
        cat $TESTCASE_FILE
        echo "Your output:"
        cat $OUTPUT_FILE
        echo "Correct output:"
        cat $CORRECT_ANSWER_FILE
        break
    fi

    echo -e "\033[0;32mPassed test: #$(($pass_count+1))\033[0m"

    if [ $1 -ne -1 ] || [ $pass_count -lt $1 ]; then
        break
    fi 
done
