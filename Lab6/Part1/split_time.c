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
Lab 6

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


void split_time (long total_sec, int *hr, int *min, int *sec)
{
    *hr = 0;
    *min = 0;
    *sec = 0;

    if (total_sec < 60)
    {
        *sec = total_sec;
        printf("Converted time = %02d:%02d:%02d\n", *hr, *min, *sec);
    }
    else
    {
        while (total_sec >= 60)
        {
            total_sec = total_sec - 60;
            (*min)++;
        }
        if (*min < 60)
        {
            *sec = total_sec;
            printf("Converted time = %02d:%02d:%02d\n", *hr, *min, *sec);
        }
        else
        {
            while (*min >= 60)
            {
                *min = *min - 60;
                (*hr)++;
            }
            *sec = total_sec;
            printf("Converted time = %02d:%02d:%02d\n", *hr, *min, *sec);
        }
    }
}


int main(int argc, char *argv[])
{
    long user_input;
    int hr, min, sec;
    user_input = atoi(argv[1]);

    if (user_input > 86399)
    {
        fprintf(stderr, "Total time limit exceded.\n");
        exit(EXIT_FAILURE);
    }

    split_time(user_input, &hr, &min, &sec);

    return 0;
}

