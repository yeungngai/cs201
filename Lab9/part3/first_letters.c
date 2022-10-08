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
Lab 9 part 3

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
#include <string.h>
#define WORDLENGTH 20


int main()
{   
    char *wordArray[100];
    char word[WORDLENGTH], ch;
    int numOfWords = 0;

    for (;;)
    {
        printf("Enter Word: ");
        if ((ch = getchar()) == '\n')
        {
            break;
        }
        else
        {
            word[0] = ch;
            int counter = 1;
            while ((ch = getchar()) != '\n')
            {
                // int counter = 0;
                if (counter < WORDLENGTH)
                {
                    word[counter++] = ch;
                }
                word[counter] = '\0';
            }

            wordArray[numOfWords] = malloc(strlen(word) + 1);
            if (wordArray[numOfWords] == NULL)
            {
                break;
            }
            strcpy(wordArray[numOfWords], word);
        }
        numOfWords++;
    }

    printf("\nFirst letters: ");
    for (int i = 0; i < numOfWords; i++)
    {
        printf("%c", wordArray[i][0]);
    }
    printf("\n");

    for (int i = 0; i < numOfWords; i++)
    {
        free(wordArray[i]);
    }

    return 0;
}

