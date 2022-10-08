/***
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 Nicholas Duong, Yi Yang

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

Student 1:
* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture section: B2 Nadi, Sarah
* Lab section: H02

Student 2:
* Name:
* Student ID:
* CCID:
* Lecture section:
* Lab section: 

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzle2D.h"

#define MAX_SIZE 100
#define D 256
#define P 7079


// An implementation of Rabin-karp algorithm, the function returns the index of the matching character in the inputText.
int rabinKarp(char inputText[], char word[], int wordLength)
{
    int wordHashValue = 0, index;
    int textLength = strlen(inputText);

    // Compute the hash value of the word
    for (int i = 0; i < wordLength; i++)
    {
        wordHashValue = (D * wordHashValue + word[i]) % P;
    }

    // Compare the hash value of the word and hash value of a substring from the input text with the same length
    for (index = 0; index <= textLength - wordLength; index++)
    {
        // comput the hash value of the substring with the same length as the word
        int textHashValue = 0;
        for (int i = 0; i < wordLength; i++)
        {
            textHashValue = (D * textHashValue + inputText[index + i]) % P;
        }

        if (textHashValue == wordHashValue)
        {
            return index;
        }
    }

    return -1;
}






int direction1(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];

    for (; *row < tableLength; (*row)++)
    {
        strcpy(text, table[*row]);
        *col = rabinKarp(text, word, wordLength);
        if (*col != -1)
        {
            direction = 1;
            return direction;
        }
    }

    *row = 0, *col = 0, direction = 0;
    return direction;
}



int direction2(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];

    for (; *row < tableLength; (*row)++)
    {
        strcpy(text, table[*row]);
        char reversed[MAX_SIZE];
        int textIndex = tableLength -1;
        for (int i = 0; i < tableLength; i++)
        {
            reversed[i] = text[textIndex];
            textIndex--;
        }

        // printf("TEXT: %s  REVERSED: %s\n", text, reversed);

        *col = rabinKarp(reversed, word, wordLength);
        if (*col != -1)
        {   
            *col = (tableLength-1) - *col;
            direction = 2;
            return direction;
        }
    }

    *row = 0, *col = 0, direction = 0;
    return direction;
}





int main(int argc, char *argv[])
{

    FILE* wordlistFile = fopen("student_1_wordlist.txt", "r");
    FILE* tableFile = fopen("student_1_table.txt", "r");

    char wordlist[MAX_SIZE][MAX_SIZE], table[MAX_SIZE][MAX_SIZE];
    char lineFromWordlist[MAX_SIZE], lineFromTable[MAX_SIZE];
    int wordlistLength = 0, tableLength = 0;

    // Read line by line from wordlist.txt to an array
    while (fgets(lineFromWordlist, sizeof(lineFromWordlist), wordlistFile) != NULL)
    {
        int strlength = strlen(lineFromWordlist);
        if (lineFromWordlist[strlength-1] == '\n')
        {
            lineFromWordlist[strlength-1] = '\0';
        }

        strcpy(wordlist[wordlistLength], lineFromWordlist);
        wordlistLength++;
    }

    // Read line by line from table.txt to an array
    while (fgets(lineFromTable, sizeof(lineFromTable), tableFile) != NULL)
    {
        int strlength = strlen(lineFromTable);
        if (lineFromTable[strlength-1] == '\n')
        {
            lineFromTable[strlength-1] = '\0';
        }

        strcpy(table[tableLength], lineFromTable);
        tableLength++;
    }


    // For debugging use, prints out the content of wordlist array and table array
    // for (int i = 0; i < wordlistLength; i ++)
    // {
    //     printf("%s\n", wordlist[i]);
    // }

    // printf("\n");

    // for (int i = 0; i < tableLength; i ++)
    // {
    //     printf("%s\n", table[i]);
    // }    




    int row, col, direction = 0;
    char resultWord[MAX_SIZE];

    // wordLength will be provided in input arguments, this will be done later.
    // int wordLength = strlen(wordlist[0]);

    // for (int i = 0; i < wordlistLength; i++)
    // {
    //     strcpy(resultWord, wordlist[i]);

    //     direction = direction1(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
    //     if (direction == 1)
    //     {
    //         printf("%s;(%d,%d);%d\n", resultWord, row, col, direction);
    //         continue;
    //     }

    //     direction = direction2(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
    //     if (direction == 2)
    //     {
    //         printf("%s;(%d,%d);%d\n", resultWord, row, col, direction);
    //         continue;
    //     }


    //     printf("%s;(%d,%d);%d\n", resultWord, row, col, direction);
    // }
    

    
    // For testing the implementation of Rabin-Karp algorithm, the answer for this case is 20, if the answer is -1 then word is not found
    char word[] = "star";
    char text[] = "twinkletwinklelittlestarhowIwonderwhatyouare";

    int wordLength = strlen(word);
    
    int answer = rabinKarp(text, word, wordLength);
    printf("Answer: %d\n", answer);


    return 0;
}





