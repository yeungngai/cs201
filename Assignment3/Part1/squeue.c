/*
   CMPUT 201 Student Submission License Version 2.0

   Copyright 2021 <Yi Yang, En Chee>

   Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

   This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

   Copying any part of this solution without including this copyright notice is illegal.

   If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

   This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email address:

   nadi@ualberta.ca
   ildar@ualberta.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "squeue.h"

void initSqueue(Squeue **squeue)
{
	// this function initializes the squeue 
	// points first and last to NULL
	(*squeue) = (Squeue *)malloc(sizeof(Squeue) * 1);
	if ((*squeue) == NULL)
	{
		printf("Could not allocate any space for the queue\n");
		exit(4);
	}

	(*squeue)->first = NULL;
	(*squeue)->last = NULL; 
}

bool isEmpty (const Squeue *squeue)
{
	// checks to see if the squeue is empty
	//return (squeue->first == NULL);
	return squeue->first == NULL; 
}

void addFront(Squeue *squeue, char* val)
{
	// adds a node to the front of the squeue
	// create new pointer for the node to add
	// dynamically allocate it 
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Could not allocate room from new node\n");
		exit(4);
	}
	// enter value into the new node
	int lengthString = strlen(val); 
	newNode->val = malloc(lengthString + 1);
	strcpy(newNode->val, val);

	newNode->prev = NULL; 

	if (squeue->first == NULL)
	{
		squeue->first = newNode;
		squeue->last = newNode; 
		newNode->next = NULL;
	}
	else
	{
		// point the new node's next to be the squeueue's first
		newNode->next = squeue->first;

		// point the squeue's first to be the newNode
		squeue->first = newNode; 
		newNode->next->prev = newNode; 

	}
}


void addBack (Squeue *squeue, char *val)
{
	// adds a node to the back of the squeue
	// create new pointer for the node to add
	// dynamically allocate it 
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Could not allocate room from new node\n");
		exit(4);
	}
	// enter value into the new node
	int lengthString = strlen(val); 
	newNode->val = malloc(lengthString + 1);
	strcpy(newNode->val, val);

	//add the node to the last element of the squeueue
	//if the squeue is empty 
	if (squeue->first == NULL)
	{
		squeue->first = newNode;
		squeue->last = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}

	else
	{
		// point new node's next to be null 
		newNode->next = NULL;

		//point new node's previous to be squeue's lsast
		newNode->prev = squeue->last;

		//point squeue's last's next to be new node
		squeue->last->next = newNode;

		//point squeue's last to be new nodes
		squeue->last = newNode; 
	}
	//printf("squeue->last->next = %s\n", squeue->last->next->val); 
}

void leaveFront(Squeue *squeue)
{
	// deletes the node from the front 
	//check that the squeue is not empty 
	assert(!isEmpty(squeue));
	//will continue if the squeue is not empty 

	//temp node points to the squeue first
	struct Node *temp = squeue->first; 
	//point squeue's first to be the firsts next
	squeue->first = squeue->first->next; 
	//point first's previous to be NULL
	squeue->first->prev = NULL;

	//free temp's value
	free(temp->val);
	temp->val = NULL;
	free(temp);
	temp = NULL;
}

void leaveBack (Squeue *squeue)
{
	// deletes the last node of the squeue
	assert(!isEmpty(squeue));
	// temp node points to the last item in squeue
	struct Node *temp = squeue->last;

	//point squeue's last to the last's previous
	squeue->last = squeue->last->prev;

	// point squeue's last next to NULL
	squeue->last->next = NULL;

	// point temp's previous to be NULL
	temp->prev = NULL;

	//free temp 
	free(temp->val);
	temp->val = NULL;
	free(temp); 
	temp = NULL; 
}

char *peekFront(const Squeue *squeue)
{
	// returns the first item in the squeue
	assert(!isEmpty(squeue)); 
	return squeue->first->val; 
}

char *peekBack(const Squeue *squeue)
{
	// checks the last item in the squeue and returns it 
	assert(!isEmpty(squeue));
	return squeue->last->val; 
}

void nuke (Squeue *squeue)
{
	// deletes all internal nodes
	struct Node *temp; 
	temp = squeue->first; 
	while(temp !=NULL)
	{
		squeue->first = temp->next;
		free(temp->val);
		free(temp);
		temp = squeue->first; 
	}
	// set to be NULL
	squeue->first = NULL;
	squeue->last = NULL; 

}

void reverse(Squeue* squeue)
{
	// reverses the squeue
	struct Node *temp = NULL;
	struct Node *current = squeue->first; 


	squeue->first = squeue->last;
	squeue->last = current; 

	while (current!=NULL)
	{
		temp = current->prev; 
		//printf("temp = %s; ", temp->val);
		current->prev = current->next;
		//printf("cur->prev = %s; ", current->prev->val); 
		current->next = temp; 
		//printf("current->next= %s; ", current->next->next->val);
		current = current->prev; 
	}


}

void destroySqueue(Squeue **squeue)
{
	// delete internal nodes first
	nuke(*squeue); 
	//delete the actual squeue
	free(*squeue);
	*squeue = NULL; 

}

void mergeFront(Squeue* squeue, char direction)
{
	// combines the first two nodes or the last two nodes depending on the direction
	assert(!(squeue->first == NULL));
	assert(!(squeue->first->next == NULL));


	if(direction == 'f')
	{
		struct Node *temp = squeue->first->next;
		int L1 = strlen(squeue->first->val); 
		int L2 = strlen(squeue->first->next->val); 
		int LengthString = L1 + L2 + 1;  

		char *p = malloc(LengthString + 1);
		strcpy(p,squeue->first->val);
		strcat(p,squeue->first->next->val); 
		free(squeue->first->val);
		squeue->first->val = p; 

		if (temp->next != NULL)
		{
			squeue->first->next = temp->next;
			temp->next->prev = squeue->first;
		}
		else
		{
			squeue->first->next = NULL;
			squeue->last = squeue->first;
		}

		free(temp->val);
		free(temp); 
	}

	else if(direction == 'r')
	{
		struct Node *temp = squeue->last->prev;
		int L1 = strlen(squeue->last->val);
		int L2 = strlen(temp->val);
		int LengthString = L1 + L2 + 1;

		char *p = malloc(LengthString+1);
		strcpy(p, temp->val);
		strcat(p,squeue->last->val);
		free(squeue->last->val);
		squeue->last->val = p;

		if (temp->prev != NULL)
		{
			temp->prev->next = squeue->last;
			squeue->last->prev = temp->prev;
		}
		else
		{
			squeue->first = squeue->last;
			squeue->last->prev=NULL;
		}

		free(temp->val);
		free(temp); 

	}

	else
	{
		fprintf(stderr, "Error, illegal direction %c\n", direction);
	}
}

void mergeBack(Squeue* squeue, char direction)
{
	// combines the first two nodes or the last two nodes depending on direction
	assert(!(squeue->first == NULL));
	assert(!(squeue->first->next == NULL));

	if (direction == 'f')
	{
		struct Node *temp = squeue->first->next;
		int L1 = strlen(squeue->first->val); 
		int L2 = strlen(squeue->first->next->val); 
		int LengthString = L1 + L2 + 1;

		char *p = malloc(LengthString + 1);
		strcpy(p, temp->val);
		strcat(p, squeue->first->val);
		free(squeue->first->val);
		squeue->first->val = p; 

		if (temp->next!=NULL)
		{
			squeue->first->next = temp->next;
			temp->next->prev = squeue->first; 
		}
		else
		{
			squeue->first->next = NULL;
			squeue->last = squeue->first;
		}
		free(temp->val);
		free(temp);
	}

	else if (direction == 'r')
	{
		struct Node *temp = squeue->last->prev;
		int L1 = strlen(squeue->last->val);
		int L2 = strlen(temp->val);
		int LengthString = L1 + L2 + 1;

		char *p = malloc(LengthString+1);
		strcpy(p, squeue->last->val);
		strcat(p, temp->val);
		free(squeue->last->val);
		squeue->last->val = p;

		if (temp->prev != NULL)
		{
			temp->prev->next = squeue->last;
			squeue->last->prev = temp->prev;
		}
		else
		{
			squeue->first = squeue->last;
			squeue->last->prev = NULL;
		}

		free(temp->val);
		free(temp);
	}

	else
	{
		fprintf(stderr, "Error, illegal direction %c\n", direction);
	}
}

void print(const Squeue *squeue, char direction)
{
	// prints the squeue in a certain direction (forwrd or reverse)

	if (direction == 'f') // print forward
	{
		struct Node *temp = squeue->first;
		printf("squeue is:\n");

		while (temp != NULL)
		{
			printf("	%s\n", temp->val);
			temp = temp->next;
		}
		//printf("  %s\n", temp->val);
	}

	else if (direction == 'r')
	{
		struct Node *temp = squeue->last;
		printf("squeue is:\n");
		while (temp != NULL)
		{
			printf("	%s\n", temp->val);
			temp = temp->prev;
		}
		//printf("  %s\n", temp->val);
	}

	else
	{
		fprintf(stderr, "Error, illegal direction %c\n", direction);

	}
}
