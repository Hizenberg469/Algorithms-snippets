#!/bin/bash

debug=false
if [ $# -eq 1 ]; then

    if [[ $1 != "-d" ]]; then
        echo "Invalid argument"
        echo "$0 -d for debug mode"
        exit 4
    fi

    debug=true
fi


#Creating .txt files
TESTCASE_FILE=IOFiles/testcase.txt
OUTPUT_FILE=IOFiles/output.txt
CORRECT_ANSWER_FILE=IOFiles/correct_answer.txt

if ! [ -f $TESTCASE_FILE ]; then
    echo "No $TESTCASE_FILE detected"
    exit 1
fi

if ! [ -f $OUTPUT_FILE ]; then
    echo "No $OUTPUT_FILE detected"
    exit 1
fi

if ! [ -f $CORRECT_ANSWER_FILE ]; then
    echo "No $CORRECT_ANSWER_FILE detected"
    exit 1
fi


#Executables.

SOLUTION=build/solution

make $SOLUTION

# Read and split test cases and answers based on empty lines
echo "Running test cases..."
pass_count=0
fail_count=0

# Separate test cases and expected outputs by empty lines

test_cases=()
exepected_outputs=()

test_case_block=""
while IFS= read -r line || [ -n "$line" ]; do
    if [ -z "$line" ];then
        test_cases+=("$test_case_block")
        test_case_block=""
    else
        test_case_block="${test_case_block}${line}"$'\n'
    fi
done < "$TESTCASE_FILE"
test_cases+=("$test_case_block")

output_block=""
while IFS= read -r line || [ -n "$line" ]; do
    if [ -z "$line" ]; then
        expected_outputs+=("$output_block")
        output_block=""
    else
        output_block="${output_block}${line}"$'\n'
    fi
done < "$CORRECT_ANSWER_FILE"
expected_outputs+=("$output_block")

# Ensure number of testcase is same as number of output.
if [ ${#test_cases[@]} -ne ${#expected_outputs[@]} ]; then
    echo "The TestCase and answer count should be same."
    exit 2
fi


for (( test_num = 0 ; test_num < ${#test_cases[@]} ; test_num++))
do
    test_case="${test_cases[test_num]}"
    expected_output="${expected_outputs[test_num]}"

    if ! echo -e "$test_case" | ./$SOLUTION > "$OUTPUT_FILE"; then
        echo -e "\033[0;31mTest #$(($test_num+1)): Execution failed\033[0m"
        echo "solution executable didn't executed successfully"
        let fail_count++
        continue
    fi

    test_output=$(<"$OUTPUT_FILE")

    if diff -q -Z <(echo $test_output) <(echo $expected_output) > /dev/null; then
        echo -e "\033[0;32mTest #$(($test_num+1)): PASS\033[0m"
        
        #Debug mode - in case to see the output.
        if $debug; then
            echo "Test case:"
            echo -n "$test_case"
            echo "Your output:"
            echo -n "$test_output"
            echo ""
        fi
        
        let pass_count++
    else
        echo -e "\033[0;31mTest #$(($test_num+1)): FAIL\033[0m"
        echo "Test case:"
        echo -n "$test_case"
        echo "Your output:"
        echo "$test_output"
        echo "Correct output:"
        echo -n "$expected_output"
        let fail_count++
    fi
done

#Sumary
echo -e "\033[0;32mPassed test: $pass_count\033[0m"
echo -e "\033[0;31mFailed test: $fail_count\033[0m"

# Exit with appropriate status
if [ $fail_count -eq 0 ]; then
    exit 0
else
    exit 3
fi