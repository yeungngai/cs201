/***
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 En Chee, Yi Yang

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email addresses:

nadi@ualberta.ca
ildar@ualberta.ca
***/

/***
Team: Asgmt2_team73
***/

/***
 * CMPUT 201 Assignment License
 * Version 2.0
 *
 * Copyright 2019 Sarah Nadi and Baihong Qi
 
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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "bucketstack.h"


void initStack(int bucketSize, Stack **stack)
{
    (*stack) = (Stack *)malloc(sizeof(Stack) * 1);

    if ((*stack) == NULL)
    {
        printf("Could not allocate any space for the stack\n");
    }

    (*stack)->topElt = 0;
    (*stack)->bucketSize = bucketSize;
    (*stack)->firstBucket = NULL;
}


bool isEmpty(const Stack *stack)
{
    // return whether or not the bucket is empty
    return stack->firstBucket == NULL;
}


void push(char *val, Stack *stack)
{
    // if current bucket is not full
    if ((stack->topElt) < (stack->bucketSize))
    {
        // if stack is does not have a bucket
        if (isEmpty(stack))
        {
            struct NodeBucket *newNodeBucket;

            newNodeBucket = (struct NodeBucket *)malloc(sizeof(struct NodeBucket));

            newNodeBucket->val = malloc(sizeof(char *) * (stack->bucketSize));
            newNodeBucket->val[stack->topElt] = val;
            newNodeBucket->next = NULL;

            stack->firstBucket = newNodeBucket;
            (stack->topElt)++;
        }

        // bucket(s) exist
        else
        {
            stack->firstBucket->val[stack->topElt] = val;
            (stack->topElt)++;
        }
    }

    // if current bucket is full
    else
    {
        // Set top element index to 0 which would be at the new bucket
        stack->topElt = 0;

        struct NodeBucket *temp;
        struct NodeBucket *newBucket;

        // temp is the current first bucket
        temp = stack->firstBucket;
        stack->firstBucket = NULL;

        // create a new bucket
        newBucket = (struct NodeBucket *)malloc(sizeof(struct NodeBucket));

        // allocate sapce for the new first bucket and point next to the previous first bucket
        newBucket->val = malloc(sizeof(char *) * (stack->bucketSize));
        newBucket->val[0] = val;
        newBucket->next = temp;

        // link first bucket to the new bucket
        stack->firstBucket = newBucket;
        (stack->topElt)++;
    }
}


void pop(Stack *stack)
{
    int bucketIndex = stack->topElt -1;

    // check if stack has bucket(s) or not
    assert(!isEmpty(stack));

    // If the element is the last one in the bucket
    if (bucketIndex == 0)
    {
        struct NodeBucket *temp;
        temp = stack->firstBucket->next;
        
        free(stack->firstBucket->val);
        free(stack->firstBucket);
        stack->firstBucket = temp;
        stack->topElt = stack->bucketSize;
    }

    // If there are more than one elements in the bucket
    else
    {
        stack->firstBucket->val[bucketIndex] = NULL;
        stack->topElt--;
    }

}


int size(const Stack *stack)
{
    int counter = 0;

    struct NodeBucket *temp;
    temp = stack->firstBucket;

    int bucketIndex = stack->topElt - 1;

    while (temp != NULL)
    {
        for (; bucketIndex >= 0; bucketIndex--)
        {
            counter++;
        }

        temp = temp->next;
        bucketIndex = stack->bucketSize - 1;
    }

    return counter;
}


char *top(const Stack *stack)
{
    return stack->firstBucket->val[stack->topElt -1];
}


void swap(Stack *stack)
{
    assert(size(stack) >= 2);

    int firstBucketEle = 0;

    int bucketIndex = stack->topElt - 1;

        for (; bucketIndex >= 0; bucketIndex--)
        {
            firstBucketEle++;
        }

    char *temp;

    // If there are more than one elements in the first bucket
    if (firstBucketEle > 1)
    {
        temp = stack->firstBucket->val[stack->topElt - 2];
        stack->firstBucket->val[stack->topElt - 2] = stack->firstBucket->val[stack->topElt - 1];
        stack->firstBucket->val[stack->topElt - 1] = temp; 
    }

    // If there is only one element in the first bucket
    else
    {
        temp = stack->firstBucket->val[0];
        stack->firstBucket->val[0] = stack->firstBucket->next->val[stack->bucketSize - 1];
        stack->firstBucket->next->val[stack->bucketSize - 1] = temp;
    }
}


void print(const Stack *stack)
{
    struct NodeBucket *temp;
    temp = stack->firstBucket;

    int bucketIndex = stack->topElt -1;

    printf("stack is:\n");

    while (temp != NULL)
    {
        for (; bucketIndex >= 0; bucketIndex--)
        {
            printf("  %s\n", temp->val[bucketIndex]);
        }

        temp = temp->next;
        bucketIndex = stack->bucketSize - 1;
    }
}


void clear(Stack *stack)
{
    struct NodeBucket *temp;
    temp = stack->firstBucket;

    while (temp != NULL)
    {
        stack->firstBucket = temp->next;
        free(temp->val);
        free(temp);
        temp = stack->firstBucket;
    }
    stack->topElt = 0;
}


void destroyStack(Stack **stack)
{
    clear(*stack);
    free(*stack);
    *stack = NULL;
}