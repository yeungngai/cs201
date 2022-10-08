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
Lab 9 part 2

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


typedef struct{
    int departure;
    int arrival;
}schedule;


int main()
{
    schedule timeTable[6];
    schedule time1, time2, time3, time4, time5, time6;
    
    time1.departure = 480;
    time1.arrival = 616;
    time2.departure = 583;
    time2.arrival = 712;
    time3.departure = 679;
    time3.arrival = 811;
    time4.departure = 767;
    time4.arrival = 900;
    time5.departure = 980;
    time5.arrival = 1143;
    time6.departure = 1115;
    time6.arrival = 1284;

    timeTable[0] = time1;
    timeTable[1] = time2;
    timeTable[2] = time3;
    timeTable[3] = time4;
    timeTable[4] = time5;
    timeTable[5] = time6;

    int hour, minute, totalMinute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    totalMinute = hour*60 + minute;

    if ((timeTable[5].departure < totalMinute) && (totalMinute < timeTable[0].departure))
    {
        printf("Next flight is at %d:%02d, ", timeTable[0].departure/60, timeTable[0].departure%60);
        printf("arriving at %d:%02d\n", timeTable[0].arrival/60, timeTable[0].arrival%60);
    }
    else
    {
        for(int i = 0; i < 6; i++)
        {
            if (timeTable[i].departure > totalMinute)
            {
                printf("Next flight is at %d:%02d, ", timeTable[i].departure/60, timeTable[i].departure%60);
                printf("arriving at %d:%02d\n", timeTable[i].arrival/60, timeTable[i].arrival%60);
                break;
            }
        }
    }


    return 0;
}