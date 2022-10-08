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
Lab 9 part 1

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


typedef struct {
int days;
int hours;
int minutes;
int seconds;
} time;


int main()
{
    time time1;
    long totalTime;
    printf("Enter time as seconds since midnight: ");
    scanf("%ld", &totalTime);


    time1.days = 0;
    time1.hours = 0;
    time1.minutes = 0;
    time1.seconds = 0;

    if (totalTime < 60)
    {
        time1.seconds = totalTime;
        printf("Days: %d\nHours: %d\nMinutes: %d\nSecpnds: %d\n", time1.days, time1.hours, time1.minutes, time1.seconds);
    }
    else
    {
        while (totalTime >= 60)
        {
            totalTime = totalTime - 60;
            time1.minutes++;
        }
        if (time1.minutes < 60)
        {
            time1.seconds = totalTime;
            printf("Days: %d\nHours: %d\nMinutes: %d\nSecpnds: %d\n", time1.days, time1.hours, time1.minutes, time1.seconds);
        }
        else
        {
            while (time1.minutes >= 60)
            {
                time1.minutes = time1.minutes - 60;
                time1.hours++;
            }
            if (time1.hours < 24)
            {
                time1.seconds = totalTime;
                printf("Days: %d\nHours: %d\nMinutes: %d\nSecpnds: %d\n", time1.days, time1.hours, time1.minutes, time1.seconds);
            }
            else
            {
                while (time1.hours >= 24)
                {
                    time1.hours = time1.hours - 24;
                    time1.days++;
                }
                time1.seconds = totalTime;
                printf("Days: %d\nHours: %d\nMinutes: %d\nSecpnds: %d\n", time1.days, time1.hours, time1.minutes, time1.seconds);               
            }
        }
    }

    return 0;
}