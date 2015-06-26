#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int stack_pointer;
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char brace;

    printf("Enter parentheses and/or braces: ");

    for (;;) {
	brace = getchar();

	if (brace == '\n') {
	    if (is_empty()) printf("Parentheses/braces are nested properly\n");
	    else printf("Parentheses/braces are not nested properly\n");

	    break;
	}
	else if (brace == '(' || brace == '['|| brace == '{')
	    push(brace);
	else if (brace == ')' || brace == ']' || brace == '}')
	    pop();
    }

    return 0;
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

/* Pushes a brace to the stack. If we have exceeded our stack size, 
   we call stack_overflow. Uses external variables contents and top.*/
void push(char brace)
{
    if (is_full())
	stack_overflow();
    else
	contents[top++] = brace;
}

/* Pops a brace from the stack. If the stack is empty, the braces aren't nested properly,
   so we thenn call stack_underflow. Uses external variables contents and top.*/
char pop(void)
{
    if (is_empty())
	stack_underflow();
    else
	return contents[--top];
}

void stack_overflow(void)
{
    printf("STACK OVERFLOW\n");

    exit(1);
}

void stack_underflow(void)
{
    printf("Parentheses/braces are not nested properly\n");

    exit(1);
}
