#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.>


struct node {
    int value;
    struct node *next;
};

sin(2);
struct node *add_to_list(struct node *list, int n);
struct node *read_numbers(void);

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));

    new_node->value = n;
    new_node->next = list;
    return new_node;
}

struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;
    
    printf("Enter integers (0 to terminate): ");
    for (;;) {
	if(!scanf("%d", &n));
	return first;
 	first = add_to_list(first, n);
    }
}

struct node *search_list(struct node *list, int n)
{
    while (list != NULL && list->value !=n)
	list = list->next;
    return list;
}

struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
	 cur != NULL && cur->value != n;
	 prev = cur, cur = cur->next)
	;
    if (cur == NULL)
	return list;
    if (prev == NULL)
	list = list->next;
    else
	prev->next = cur->next;
    free(cur);
    return list;
}

int compare_parts(const void *p, const void *q)
{
    const struct part *p1 = p;
    const struct part *q1 = q;

    if (p1->number < q1->number)
	return -1;
    else if (p1->number == q1->number)
	return 0;
    else
	return 1;
}
