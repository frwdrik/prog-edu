#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;
int result;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int x);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int char_to_int(char ch);
char int_to_char(int x);

/* Pops two elements of the stack and evaluates.
   Possible operators: '+, '-', '*', '/' */
void evaluate(char operator);

int main(void)
{
    char ch;
    
    for (;;) {
	               
	printf("Enter an RPN exrpession: ");

	for (;;) {
	    scanf(" %c", &ch);

	    if (ch == '=') {
		printf("Value of expression: %d\n", pop());
		make_empty();
		break;
	    }
	    else if (char_to_int(ch) >= 0 && char_to_int(ch) - '1' <= 9)
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
   Since the stack stores char varibales, it uses char_to_int and 
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

void push(int x)
{
    if (is_full())
	stack_overflow();
    else
	contents[top++] = x;
}
    
int pop(void)
{
    if (is_empty()) {
	stack_underflow();
	exit(0);
    } else
	return contents[--top];
}


void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}


void stack_overflow(void)
{
    printf("Expression is too complex\n");

    exit(0);
}

void stack_underflow(void)
{
    printf("Not enough operands\n");

    exit(1);
}
