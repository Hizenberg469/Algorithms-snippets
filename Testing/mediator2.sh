#set -e
#g++ code.cpp -o code
#g++ gen.cpp -o gen
#g++ brute.cpp -o brute
#g++ checker.cpp -o checker
for((i = 1; ; ++i)); do
    ./generator $i > input_file.txt
    ./solution < input_file.txt > myAnswer.txt
    ./brute_force < input_file.txt > correctAnswer.txt
    ./checker > checker_log.txt
    ret=$?
    cat checker_log.txt
    
    if [ $ret -eq 2 ];
    then
    break
    fi
    echo "Passed test: "  $i
done
echo "WA on following test case:"
cat input_file.txt
echo "Your answer is:"
cat myAnswer.txt
echo "Correct answer is:"
cat correctAnswer.txt
echo "Error Message:"
cat checker_log.txt
