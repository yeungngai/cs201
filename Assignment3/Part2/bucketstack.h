/***
* CMPUT 201 Assignment License
* Version 1.0
* 
* Copyright 2018 Sarah Nadi

* Unauthorized redistribution is forbidden under all circumstances. Use of this
* software without explicit authorization from the author **and** the CMPUT 201
* Instructor is prohibited.

* This software was produced as part of an assignment in the course
* CMPUT 201 - Practical Programming Methodology at the University of
* Alberta, Canada. This code is confidential and remains confidential 
* after it is submitted for grading. The course staff has the right to 
* run plagiarism-detection tools on any code developed under this license, 
* even beyond the duration of the course.
* 
* Copying any part of this code without including this copyright notice
* is illegal.
* 
* If any portion of this software is included in a solution submitted for
* grading at an educational institution, the submitter will be subject to
* the plagiarism sanctions at that institution.
* 
* This software cannot be publicly posted under any circumstances, whether by
* the original student or by a third party.
* If this software is found in any public website or public repository, the
* person finding it is kindly requested to immediately report, including 
* the URL or other repository locating information, to the following email
* address:
* 
*          nadi@ualberta.ca
***/

#ifndef bucketstack_h
#define bucketstack_h

#include <stdbool.h>

struct NodeBucket {
    char** val;
    struct NodeBucket* next;
};

typedef struct {
    struct NodeBucket* firstBucket;
    int topElt;
    int bucketSize;
} Stack;

void initStack (int bucketSize, Stack **stack);
bool isEmpty (const Stack *stack);
void push (char* val, Stack *stack);
void pop(Stack *stack);
int size (const Stack *stack);
char* top (const Stack *stack);
void swap (Stack *stack);
void print (const Stack *stack);
void clear(Stack *stack);
void destroyStack(Stack **stack);
#endif /* bucketstack_h */
