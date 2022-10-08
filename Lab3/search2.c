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

// Lab 3
// Name: Yi Yang
// Student ID: 1542688
// CCID: yyang13
// Lecture section: B2
// Instructor's name: Sarah Nadi
// Lab section: H02


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{

    FILE *fp;
    if (argc != 3)
    {
        fprintf(stderr, "Usage:  ./search <input file> <threshold>\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Error: cannot find %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char ch;
    int twoDimentionalArray[26][2] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, 
    {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, 
    {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

    fp = fopen("input.txt", "r");

    while ((ch = fgetc(fp)) != EOF)
    {
        for (int i = 0; i < 26; i++)
        {
            if (ch == twoDimentionalArray[i][0])
            {
                twoDimentionalArray[i][1] = twoDimentionalArray[i][1] + 1;
            }
        }
    }

    fclose (fp);


    int row, exist = 0, threshold = atoi(argv[2]);

    for (row = 0; row < 26; row++)
    {
        if (twoDimentionalArray[row][1] > threshold)
        {   
            exist = exist + 1;
            if (twoDimentionalArray[row][1] == 1)
            {
                printf("%c appears %d time\n", twoDimentionalArray[row][0], twoDimentionalArray[row][1]);
            }
            else
            {
                printf("%c appears %d times\n", twoDimentionalArray[row][0], twoDimentionalArray[row][1]);
            }
        }

        if (row == 25 && exist == 0)
        {
            printf("There are no letters that exceed this threshold\n");
        }
    }

    return 0;

}

