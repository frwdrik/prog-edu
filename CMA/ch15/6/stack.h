#include <stdbool.h>

#ifndef STACK_H
#define STACK_H

/* Sets the top variable to 0 */
void make_empty(void);

/* Checks if the stack is empty, or full */
bool is_empty(void);
bool is_full(void);

/* Pushes an integer type onto the stack
   and increases the stack pointer */
void push(int x);

/* Pops an element from the stack
   and decreases the stack pointer */
int pop(void);

/* Exception handling */
void stack_overflow(void);
void stack_underflow(void);

#endif
