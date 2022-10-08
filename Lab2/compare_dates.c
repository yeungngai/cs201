/***
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 <Yi Yang>

Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection tools on any code developed under this license, even beyond the duration of the course.

Copying any part of this solution without including this copyright notice is illegal.

If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to the following email addresses:

nadi@ualberta.ca
ildar@ualberta.ca
***/

// Lab 2
// Name: Yi Yang
// Student ID: 1542688
// CCID: yyang13
// Lecture section: B2
// Instructor's name: Sarah Nadi
// Lab section: H02


#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
    FILE *fp;
    if (argc != 2)
    {
        printf("Cannot open filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int month, day, year, mm, dd, yy;

    while (fscanf(fp, "%d/%d/%d", &month, &day, &year) != 3)
    {
        //read error
        if (ferror(fp))
        {
            fclose(fp);
            fprintf(stderr, "A read error has occurred. Program exited\n");
            exit(EXIT_FAILURE);
        }

        fscanf(fp, "%*[^\n]");
    }

    fclose(fp);


    printf("Enter date to compare to (mm/dd/yy): ");
    scanf("%d/%d/%d", &mm, &dd, &yy);

    //check date format
    if (mm < 1 || mm > 12)
    {
        fprintf(stderr, "Wrong date format\n");
        exit(4);
    }

    if (((mm == 1) || (mm == 3) || (mm == 5) || (mm == 7) || (mm == 8) || (mm == 10) || (mm == 12)) && (dd > 31))
    {
        fprintf(stderr, "Wrong date format\n");
        exit(4);
    }

    if (((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11)) && (dd > 30))
    {
        fprintf(stderr, "Wrong date format\n");
        exit(4);
    }

    if ((mm == 2) && (dd > 28))
    {
        fprintf(stderr, "Wrong date format\n");
        exit(4);
    }

    if ((yy < 1) || yy > 99)
    {
        fprintf(stderr, "Wrong date format\n");
        exit(4);
    }

    //comapre dates
    if (year > yy)
    {
        printf("%d/%d/%02d is later than %d/%d/%02d\n", month, day, year, mm, dd, yy);
    }
    else if ((year == yy) && (month > mm))
    {
       printf("%d/%d/%02d is later than %d/%d/%02d\n", month, day, year, mm, dd, yy);
    }
    else if ((year == yy) && (month == mm) && (day > dd))
    {
        printf("%d/%d/%02d is later than %d/%d/%02d\n", month, day, year, mm, dd, yy);
    }
    else
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", month, day, year, mm, dd, yy);
    }

    return 0;

}

