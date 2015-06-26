all: 3-fjellklatring.o djikstras.o
	gcc -g -o 3-fjellklatring 3-fjellklatring.o djikstras.o

3-fjellklatring.o: 3-fjellklatring.c djikstras.h
	gcc -g -c 3-fjellklatring.c

djikstras.o: djikstras.c djikstras.h
	gcc -g -c djikstras.c

dtest: dtest.c djikstras.h djikstras.c
	gcc -g -o dtest dtest.c djikstras.c

