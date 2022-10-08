/***
* CMPUT 201 Student Submission License
* Version 2.0
* 
* Copyright 2019 Sarah Nadi and \<Yi Yang, En Chee>

* Unauthorized redistribution is forbidden under all circumstances. Use of this
* software without explicit authorization from the author **and** the CMPUT 201
* Instructor is prohibited.

* This software was produced as a solution for an assignment or lab in the course
* CMPUT 201 - Practical Programming Methodology at the University of
* Alberta, Canada. This solution is confidential and remains confidential 
* after it is submitted for grading. The course staff has the right to 
* run plagiarism-detection tools on any code developed under this license, 
* even beyond the duration of the course.

* Copying any part of this solution without including this copyright notice
* is illegal.

* If any portion of this software is included in a solution submitted for
* grading at an educational institution, the submitter will be subject to
* the plagiarism sanctions at that institution.

* This software cannot be publicly posted under any circumstances, whether by
* the original student or by a third party.
* If this software is found in any public website or public repository, the
* person finding it is kindly requested to immediately report, including 
* the URL or other repository locating information, to the following email
* address:
* 
*           nadi@ualberta.ca


***/
#ifndef __SQUEUE_H__
#define __SQUEUE_H__

#include <stdbool.h>

struct Node{
    char* val;
    struct Node* next;
    struct Node* prev;
};

typedef struct{
    struct Node* first;
    struct Node* last;
} Squeue;

void initSqueue (Squeue ** squeue);
bool isEmpty (const Squeue *squeue);
void addFront (Squeue *squeue, char* val);
void addBack (Squeue *squeue, char* val);
void leaveFront (Squeue *squeue);
char* peekBack (const Squeue *squeue);
void leaveBack (Squeue *squeue);
char* peekFront (const Squeue *squeue);
void print (const Squeue *squeue, char direction);
void nuke (Squeue *squeue);
void mergeFront(Squeue *squeue, char direction );
void mergeBack(Squeue *squeue, char direction);
void reverse(Squeue *squeue);
void destroySqueue(Squeue **squeue);
#endif
