#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5

int main(void)
{
    int grades[NUM_STUDENTS][NUM_QUIZZES];
    int high, low, quiz, student, total, score;
    
    for (student = 0; student < NUM_STUDENTS; student++) {
	printf("Enter grades for student %d: ", student + 1);
	for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
	    scanf("%d", &grades[student][quiz]);
    }

    printf("\nStudent  Total  Average\n");
    for (student  = 0; student < NUM_STUDENTS; student++) {
	printf("%4d    ", student +1);
	total = 0;
	for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
	    total += grades[student][quiz];
	printf("%3d\t%3d\n", total, total / NUM_QUIZZES);
    }

    printf("\nQuiz  Average  High score  Low score\n");
    for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
	printf("%4d    ", quiz + 1);
	total= 0;
    	low  = 0;
	high = 0;
    	for (student  = 0; student < NUM_STUDENTS; student++) {
    	    score = grades[student][quiz];
	    total += score;
	    if (score < low)
		low = score;
	    if (score > high)
		high = score;
	}
	printf("%3d\t  %3d\t  %3d\n", total / NUM_STUDENTS, high, low);
    }
    return 0;
}

    
    
    
