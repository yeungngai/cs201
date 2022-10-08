/* Sorts an array of integers using Quicksort algorithm */
/* Copyright K.N. King -- C programming Ch9.6 */

/***
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Yi Yang

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email addresses:

nadi@ualberta.ca
ildar@ualberta.ca
***/

/***
Lab 8 Part 2

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/

#include <stdio.h>
#include "quicksort.h"
#define N 10

int main(void){

    int a[N], i;

    int *low, *high;

    printf("Enter %d numbers to be sorted: ", N);
    for(i = 0; i < N; i++)
        scanf("%d", &a[i]);

    low = &a[0];
    high = &a[N-1];

    quicksort(a, low, high);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}