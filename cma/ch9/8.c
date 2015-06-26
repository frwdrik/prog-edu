#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0, losses = 0;
    char play_again;

    srand((unsigned) time(NULL)); 
    
    for (;;) {
    	if (play_game())  wins++;
    	else losses++;
	
	printf("Play again? ");
    	scanf("%c", &play_again);
    	if (play_again == 'n') break;
    	else continue;
    }

    printf("Wins:  %d  Losses:  %d\n", wins, losses);
    
    return 0;
}

int roll_dice(void)
{
    int x, y;

    x = (rand() % 6) + 1;
    y = (rand() % 6) + 1;

    return x + y;
}

bool play_game(void)
{
    int roll, point;

    roll = roll_dice();
    printf("\nYou rolled: %d\n", roll);

    if (roll == 7 || roll == 11) {
	printf("You win!\n\n");
	return true;
    }
    else if (roll == 2 || roll == 3 || roll == 12) {
	printf("You lose!\n\n");
	return false;
    } else {
	point = roll;
	printf("Your point is %d\n", point);
    }

    for (;;) {
	roll = roll_dice();
	printf ("You rolled: %d\n", roll);

	if (roll == point) {
	    printf("You win!\n\n");
	    return true;
	}
	
	if (roll == 7 || roll == 11) {
	    printf("You lose!\n\n");
	    return false;
	}
    }
}
