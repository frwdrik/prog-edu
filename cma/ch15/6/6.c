/* A simple RPN calculator. A major constraint is that
   it only accepts single-digit inputs. Results, however,
   are limited in size only by the size int. */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "6.h"

int top, result, contents[STACK_SIZE];

int char_to_int(char ch);
char int_to_char(int x);

/* Pops two elements of the stack and evaluates.
   Possible operators: '+, '-', '*' and '/' */
void evaluate(char operator);

int main(void)
{
    char ch;

#ifndef SIX_H
    printf("Den e ikke definert");
#endif

    for (;;) {
	               
	printf("Enter an RPN exrpession: ");

	for (;;) {
	    scanf(" %c", &ch);

	    if (ch == '=') {
		printf("Value of expression: %d\n", pop());
		make_empty();
		break;
	    }
	    else if (ch >= '0' && (ch) <= '9')
		push(char_to_int(ch));
	    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		evaluate(ch);		   
	    else exit(0);
	}
    }

    return 0;
}

int char_to_int(char ch)
{
    return ch - '0';
}

char int_to_char(int x)
{
    return '0' + x;
}

/* Evaluate the two most recent elements on the stack
   according to the input operator. Stores the result on the stack.
   Since the stack stores char variables, it uses char_to_int and 
   int_to_char in order to use arithmetic operators. */
void evaluate(char operand)
{
    int x, y;
    
    x = pop();
    y = pop();

    if (operand == '+')
	result = x + y;
    else if (operand == '-')
	result = y - x;
    else if (operand == '*')
	result = x * y;
    else
	result = y / x;

    push(result);
}
