#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

void my_read_line(char str[], int n);

int main(void)
{
    char smallest_word[MAX_LEN+1], largest_word[MAX_LEN+1];
    char word[MAX_LEN+1];

    printf("Enter word: ");
    my_read_line(word, MAX_LEN);
    strcpy(smallest_word, strcpy(largest_word, word));
  
    while (strlen(word) != 4) {
	printf("Enter word: ");
	my_read_line(word, MAX_LEN);
    	if (strcmp(word, smallest_word) < 0)
	    strcpy(smallest_word, word);
	if (strcmp(word, largest_word) > 0)
	    strcpy(largest_word, word);
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    
    return 0;
}

void my_read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
	if (i < n)
	    str[i++] = ch;
    str[i] = '\0';
}
