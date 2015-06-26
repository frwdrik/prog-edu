6: 6.o stack.o
	gcc -o 6 6.o stack.o

6.o: 6.c 6.h stack.h
	gcc -c 6.c

stack.o: stack.c 6.h stack.h
	gcc -c stack.c
