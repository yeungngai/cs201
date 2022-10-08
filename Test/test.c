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
// #include "bucketstack.h"
// #include <assert.h>
// #include <stdlib.h>
// #include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct NodeBucket
{
    char **val;
    struct NodeBucket *next;
};

typedef struct
{
    struct NodeBucket *firstBucket;
    int topElt;
    int bucketSize;
} Stack;

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
    printf("\n IF topElt: %d\n", stack->topElt);
    // if current bucket is not full
    if ((stack->topElt) < (stack->bucketSize))
    {
        // if stack is does not have a bucket
        if (isEmpty(stack))
        {
            struct NodeBucket *newNodeBucket;

            // printf("1 Address of nodebucket: %d\n", newNodeBucket);
            // printf("2 address of val: %d\n", val);

            newNodeBucket = (struct NodeBucket *)malloc(sizeof(struct NodeBucket));

            newNodeBucket->val = malloc(sizeof(char *) * (stack->bucketSize));
            newNodeBucket->val[stack->topElt] = val;
            newNodeBucket->next = NULL;

            stack->firstBucket = newNodeBucket;

            //   newNodeBucket->next = NULL;
            // strcpy(newNodeBucket->val[stack->topElt], val);

            // printf("2 Address of nodebucket: %d\n", newNodeBucket);
            // printf("2 address of val: %d\n", val);

            // printf("Address of val: %d\n\n", newNodeBucket->val);

            // strcpy(newNodeBucket->val[stack->topElt], val);

            // Working

            printf("1 empty bucket val in bucket: %s\n", stack->firstBucket->val[stack->topElt]);
            (stack->topElt)++;

            //   printf("2 empty bucket val in bucket: %s\n\n", stack->firstBucket->val[stack->topElt]);

            // printf("val: %s\n", val);
            // strcpy(stack->firstBucket->val[stack->topElt], val);
            // printf("empty ele: %s\n", stack->firstBucket->val[stack->topElt]);

            // printf("EMPTY stack topElt: %d\n\n",stack->topElt);
            // printf("%s\n", stack->firstBucket->val[stack->topElt]);
        }

        // bucket(s) exist
        else
        {
            // printf("not empty val: %d\n", stack->firstBucket->val);
            stack->firstBucket->val[stack->topElt] = val;

            printf("1 not empty bucket val: %s\n", stack->firstBucket->val[stack->topElt]);
            (stack->topElt)++;

            //   printf("2 not empty bucket val %s\n\n", stack->firstBucket->val[stack->topElt]);
        }
    }

    // if current bucket is full
    else
    {
        printf("Previous bucket is full!\n");
        printf("Current val: %s\n", val);

        // Set top element index to 0 which would be at the new bucket
        stack->topElt = 0;
        printf("topElt: %d\n", stack->topElt);

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

        // printf("1 address of current node: %d\n", stack->firstBucket->next);
        // printf("1 new bucket val: %s\n", stack->firstBucket->next->val[stack->topElt]);

        // printf("2 address of current node: %d\n", stack->firstBucket->next);
        // printf("2 new bucket val: %s\n\n", stack->firstBucket->next->val[stack->topElt]);

        // Traverse the buckets
        // int counter = 0;
        // while (currentBucket != NULL)
        // {
        //   printf("counter: %d\n", counter);
        //   currentBucket = currentBucket->next;
        //   counter++;
        // }
    }

    // struct NodeBucket *newBucket;
    // newBucket = (struct NodeBucket*)malloc(sizeof(struct NodeBucket));
}

void pop(Stack *stack)
{
    int bucketIndex = stack->topElt -1;

    // check if stack has bucket(s) or not
    assert(!isEmpty(stack));

    // If the element is the last one in the bucket
    if (bucketIndex == 0)
    {
        printf("1 bucketIndex: %d\n", bucketIndex);

        struct NodeBucket *temp;
        temp = stack->firstBucket->next;
        
        free(stack->firstBucket->val);
        free(stack->firstBucket);
        stack->firstBucket = temp;
        stack->topElt = stack->bucketSize;

        if (stack->firstBucket == NULL)
        {
            printf("NULL!!!\n");
        }
        else
        {
            printf("NOT NULL!!!\n");
        }

    }

    // If there are more than one elements in the bucket
    else
    {
        printf("2 bucketIndex: %d\n", bucketIndex);
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

    printf("\nHow many elements: %d\n", size(stack));

    int firstBucketEle = 0;

    int bucketIndex = stack->topElt - 1;

        for (; bucketIndex >= 0; bucketIndex--)
        {
            firstBucketEle++;
        }

    printf("\nHow many elements is the first bucket: %d\n", firstBucketEle);

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

    printf("\n\nStack is:\n");

    while (temp != NULL)
    {
        for (; bucketIndex >= 0; bucketIndex--)
        {
            printf("    %s\n", temp->val[bucketIndex]);
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
        free(stack->firstBucket->val);
        free(stack->firstBucket);
        
        temp = temp->next;
        stack->firstBucket = temp;
    }
    stack->topElt = 0;

}


void destroyStack(Stack **stack)
{
    clear(*stack);
}


int main()
{
    printf("Passed main()\n");

    Stack *s1 = NULL;
    initStack(5, &s1);

    printf("%d\n", s1->bucketSize);
    printf("Passed initStack\n\n");

    if (isEmpty(s1))
    {
        printf("Empty\n");
    }
    else
    {
        printf("Not empty\n");
    }
    printf("Passed isEmpty\n\n");

    push("alpha", s1);
    push("beta", s1);
    push("gamma", s1);
    push("delta", s1);
    push("epsilon", s1);
    push("zeta", s1);
    push("eta", s1);

    print(s1);
    printf("size is: %d\n", size(s1));

    printf("passed push\n\n");

    if (isEmpty(s1))
    {
        printf("\nEmpty\n");
    }
    else
    {
        printf("\nNot empty\n");
    }

    // pop(s1);

    print(s1);

    // pop(s1);
    // pop(s1);

    clear(s1);

    print(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // pop(s1);
    // // pop(s1);

    // print(s1);

    // if (isEmpty(s1))
    // {
    //     printf("\nEmpty\n");
    // }
    // else
    // {
    //     printf("\nNot empty\n");
    // }


    // printf("size is: %d\n", size(s1));
    // printf("Passed pop and Size\n\n");

    return 0;
}

// int main()
// {
//   //We will have two stacks
//   Stack *s1 = NULL;
//   Stack *s2 = NULL;
//   initStack(5, &s1);
//   initStack(3, &s2);
//   push("uno", s1);
//   push("dos", s1);
//   //s1 now has "dos" and "uno" in that order
//   assert(strcmp("dos", top(s1)) == 0);
//   //s2 is empty at this moment
//   assert(isEmpty(s2));
//   push("tres", s2);
//   //We just added "tres" in s2
//   assert(strcmp("tres", top(s2)) == 0);
//   assert(size(s1) == 2);
//   assert(size(s2) == 1);
//   //Time to swap "dos" and "uno"
//   swap(s1);
//   //s1 now has "uno" and "dos" in that order
//   assert(strcmp("uno", top(s1)) == 0);
//   //Let's add 3 elements to each stack
//   //after this for loop, s1 will have "hola", "hola", "hola", "uno",
//   //"dos" in that order
//   //after this for loop, s2 will have "mundo!", "mundo!", "mundo!", "tres"
//   //in that order
//   for(int i = 0; i < 3; i++) {
//     push("hola", s1);
//     push("mundo!", s2);
//   }
//   print(s1);
//   print(s2);

//   //let's add 97 elements to each stack
//   for(int i = 0; i < 97; i++) {
//     push("hola", s1);
//     push("mundo!", s2);
//   }

//   assert(size(s1) == 102);
//   assert(size(s2) == 101);
//   //s1 should have "hola" at the top
//   assert(strcmp(top(s1), "hola") == 0);
//   //s2 should have "mundo!" at the top
//   assert(strcmp(top(s2), "mundo!") == 0);

//   //at this point, s1 has 100 "hola" at the top so let's pop them
//   //at this point, s2 has 100 "mundo!" at the top so let's pop them
//   for(int i = 0; i < 100; i++) {
//     assert(strcmp(top(s1), "hola") == 0);
//     pop(s1);
//     assert(strcmp(top(s2), "mundo!") == 0);
//     pop(s2);
//   }

//   //s1 still has the uno and dos at the top and s2 still
//   //has tres at the top. Let's use clear to clear all remaining
//   //elements on each stack
//   clear(s1);
//   clear(s2);

//   //both stacks must be empty after clear
//   assert(isEmpty(s1));
//   assert(isEmpty(s2));

//   destroyStack(&s1);
//   assert(s1 == NULL);

//   destroyStack(&s2);
//   assert(s2 == NULL);
//   return 0;
// }
