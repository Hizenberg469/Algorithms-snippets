#!/bin/bash

# if [ $# -ne 1 ]; then
#     echo "Provide the limit of stress testing"
#     echo "$0 'test case limit'"
#     echo "$0 -1 (for unlimited)"
#     echo "OPTIONAL: $0 -n (for running with bruteforce)"
#     exit 1
# fi

limit=0
flag=true
while getopts l:nh param; do
    case $param in                                                     
    l)
        limit=$OPTARG                
        ;;
    n)
        flag=false              
        ;;
    h)
        echo "Provide the limit of stress testing"
        echo "$0 'test case limit'"
        echo "$0 -1 (for unlimited)"
        echo "OPTIONAL: $0 -n (for running with bruteforce)"
        exit 0
        ;;
    esac
done

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

normalize() {
    awk '{$1=$1};1' "$1" | tr -d '\r'
}

while (( 1 ))
do
    ./$GENERATOR $(($pass_count+1)) > $TESTCASE_FILE
    ./$SOLUTION < $TESTCASE_FILE > $OUTPUT_FILE

    if $flag ; then
        ./$BRUTEFORCE < $TESTCASE_FILE > $CORRECT_ANSWER_FILE

        # cat $OUTPUT_FILE
        # cat $CORRECT_ANSWER_FILE

        #Use cat for diff...
        if ! diff -q <(cat "$OUTPUT_FILE") <(cat "$CORRECT_ANSWER_FILE") > /dev/null; then
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
    else
        echo -e "Test #$(($pass_count+1)):"
        echo "Test case:"
        cat $TESTCASE_FILE
        echo "Your output:"
        cat $OUTPUT_FILE
    fi

    let pass_count++
    if [ $limit -ne -1 ] && [ $pass_count -ge $limit ]; then
        break
    fi 
done
