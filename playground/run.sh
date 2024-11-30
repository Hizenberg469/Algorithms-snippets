#!/bin/bash

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
mapfile -t test_cases < <(awk -v RS= '1' "$TESTCASE_FILE")
mapfile -t expected_outputs < <(awk -v RS= '1' "$CORRECT_ANSWER_FILE")

# Ensure number of testcase is same as number of output.
if [ ${#test_cases[@]} -ne ${#expected_outputs[@]} ]; then
    echo "The TestCase and answer count should be same."
    exit 2
fi

for (( test_num = 0 ; test_num < ${#test_cases[@]} ; test_num++))
do
    test_case=${test_cases[test_num]}
    expected_output=${expected_outputs[test_num]}

    if ! echo "$test_case" | ./$SOLUTION > "$OUTPUT_FILE"; then
        echo -e "\033[0;31mTest #$(($test_num+1)): Execution failed\033[0m"
        echo "solution executable didn't executed successfully"
        let fail_count++
        continue
    fi

    test_output=$(<"$OUTPUT_FILE")

    if diff -q -Z <(echo "$test_output") <(echo "$expected_output") > /dev/null; then
        echo -e "\033[0;32mTest #$(($test_num+1)): PASS\033[0m"
        let pass_count++
    else
        echo -e "\033[0;31mTest #$(($test_num+1)): FAIL\033[0m"
        echo "Test case:"
        echo $test_case
        echo "Your output:"
        echo $test_output
        echo "Correct output:"
        echo $expected_output
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