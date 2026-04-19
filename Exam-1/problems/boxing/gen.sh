set -e

g++ -Wall -Wextra -g -fsanitize=undefined,address ./author/$1.cpp -o fast
g++ -Wall -Wextra -g -fsanitize=undefined,address gen.cpp -o gen
cnt=7
str="0"

echo "complied"

while [ "$cnt" -le 9 ]
do
	if [ "$cnt" -eq 10 ]; then
		str=""
	fi 
	echo -n g
	echo "$cnt" | ./gen > ./tests/$1.${str}${cnt}.in
	echo -n f
	./fast < ./tests/$1.${str}${cnt}.in > ./tests/$1.${str}${cnt}.sol
	cnt=$((cnt + 1))
done
