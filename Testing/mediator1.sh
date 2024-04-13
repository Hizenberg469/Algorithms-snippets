#set -e
#g++ code.cpp -o code
#g++ gen.cpp -o gen
#g++ brute.cpp -o brute
for((i = 1;i <= 60 ; ++i)); do
    ./generator.exe $i > input_file.txt
    #./solution < input_file.txt > myAnswer.txt
    #./brute_force < input_file.txt > correctAnswer.txt
    #diff -Z myAnswer.txt correctAnswer.txt > /dev/null || break
	echo "test case: "  $i
    cat input_file.txt
    #cat myAnswer.txt
done
#echo "WA on the following test:"
#cat input_file.txt
#echo "Your answer is:"
#cat myAnswer.txt
#echo "Correct answer is:"
#cat correctAnswer.txt
