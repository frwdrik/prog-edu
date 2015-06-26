#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

char digits[4][MAX_DIGITS * 4];
const int segments[10][7] = {{1,1,1,1,1,1,0},
			     {0,1,1,0,0,0,0},
			     {1,1,0,1,1,0,1},
			     {1,1,1,1,0,0,1},
			     {0,1,1,0,0,1,1},
			     {1,0,1,1,0,1,1},
			     {1,0,1,1,1,1,1},
			     {1,1,1,0,0,0,0},
			     {1,1,1,1,1,1,1},
			     {1,1,1,1,0,1,1}};

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);
int char_to_int(char ch);

int main(void)
{
    char input_digit;
    int i = 0;
    
    clear_digits_array();

    while (i < MAX_DIGITS) {
	scanf("%c", &input_digit);

	if (input_digit >= '0' && input_digit <= '9') {
	    process_digit(char_to_int(input_digit), i);
	    i++;
	} else if (input_digit == '\n')
	    break;
     }

    print_digits_array();   
    
    return 0;
}

void clear_digits_array(void)
{
    int row, column;

    for (row = 0; row < 4; row++)
	for (column = 0; column < MAX_DIGITS * 4; column++)
	    digits[row][column] = ' ';
}

void process_digit(int digit, int position)
{
    if (segments[digit][0])
	digits[0][(4 * position) + 1] = '_';
    if (segments[digit][1])
	digits[1][(4 * position) + 2] = '|';
    if (segments[digit][2])
	digits[2][(4 * position) + 2] = '|';
    if (segments[digit][3])
	digits[2][(4 * position) + 1] = '_' ;
    if (segments[digit][4])
	digits[2][(4 * position)] = '|';
    if (segments[digit][5])
	digits[1][(4 * position)] =  '|';
    if (segments[digit][6])
	digits[1][(4 * position) + 1] = '_';
} 

void print_digits_array(void)
{
    int row, column;

    for (row = 0; row < 4; row++) {
	printf("\n");
	for (column = 0; column < MAX_DIGITS * 4; column++)
	    printf("%c ", digits[row][column]);
    }

    printf("\n");
}


int char_to_int(char ch)
{
    return ch - '0';
}
