CC = gcc -Wall -Werror
CPP = g++ -Wall -Werror 

TEST_71A: COMP_71A
	cat 71A.txt > ./71A.out

COMP_71A:
	${CC} -o 71A.out 71A.c

TEST_4A: COMP_4A
	cat 4A.txt > ./4A.out

COMP_4A:
	${CC} -o 4A.out 4A.c

clean:
	rm *.out
