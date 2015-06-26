#include <stdio.h>
#include "stack.h"
#include "6.h"

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
