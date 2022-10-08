#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct node *add_to_list(struct node *list, int n, char marker){
	struct node *new_node;
	new_node = malloc(sizeof(struct node));

	if(new_node == NULL){
		printf("Error: malloc failed in add_to_list\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;
	new_node->marker = marker;
	new_node->next = list;

	return new_node;
}

struct node *find_last (struct node *list, int n)
{
	struct node *findNode;
	struct node *new_node;
	
	for (findNode = list; findNode != NULL; findNode = findNode->next)
	{
		if (findNode->value == n)
		{
			new_node = findNode;
		}
	}

	if (new_node != NULL)
	{
		return new_node;
	}

	return NULL;
}


struct node *free_list(struct node *list)
{
	struct node *cur = list;

	while (cur != NULL)
	{
		list = cur->next;
		free(cur);
		cur = list;
	}

	return list;
}