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
Lab 7 Part 1

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100

int check_palindrome(int message[], int size)
{
    int *head, *end;

    head = &message[0];
    end = &message[size-1];

    if ((size % 2) == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size / 2; i++)
        {
            if (tolower(*head) != tolower(*end))
            {
                return 0;
            }
            head++;
            end--;
        }
    }
    return 1;
}


int main(int argc, char *argv[])
{
    char ch;
    int message[MAX_SIZE];
    int size = 0, returned;
    int *pointer;
    pointer = &message[0];

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n')
    {
        if (((65 <= ch) && (ch <= 90)) || ((97 <= ch) && (ch <= 122)))
        {
            *pointer = ch;
            size++;
            pointer++;
        }
    }

    returned = check_palindrome(message, size);

    if (returned == 0)
    {
        printf("Not a palindrome\n");
    }
    else
    {
        printf("Palindrome\n");
    }

    return returned;
}
