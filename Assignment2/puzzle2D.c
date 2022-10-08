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
* Name: Nicholas Duong
* Student ID: 1574003
* CCID: nduong
* Lecture section: B1
* Lab section: H03

***/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define D 256
#define P 7079


// An implementation of Rabin-karp algorithm, the function returns the index of the matching character in the inputText.
int rabinKarp(char inputText[], char word[], int wordLength)
{
    int h = 1, index, wordHashValue = 0;
    int textLength = strlen(inputText);

    // Compute the rehashing coefficient h
    int n = wordLength -1;
    for (int i = 0; i < n; i++) 
    {
        h = (h * D) % P;
    }

    // Compute the hash value of the word
    for (int i = 0; i < wordLength; i++)
    {
        wordHashValue = (D * wordHashValue + word[i]) % P;
    }

    // Comput the first substring of the text with the same length as the word
    int textHashValue = 0;
    for (int i = 0; i < wordLength; i++)
    {
        textHashValue = (D * textHashValue + inputText[i]) % P;
    }
    if (textHashValue == wordHashValue)
    {
        return 0;
    }

    // Compare the hash value of the word and hash value of a substring from the input text with the same length
    for (index = 0; index <= textLength - wordLength; index++)
    {
        textHashValue = (D * (textHashValue - inputText[index]*h) + inputText[index+wordLength]) % P;
        
        if (textHashValue < 0)
        {
            textHashValue = P + textHashValue;
        }

        if (textHashValue == wordHashValue)
        {
            return index + 1;
        }
    }

    // if not found, the function returns -1
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
        // Reverse the string
        strcpy(text, table[*row]);
        char reversed[MAX_SIZE];
        int textIndex = tableLength -1;
        for (int i = 0; i < tableLength; i++)
        {
            reversed[i] = text[textIndex];
            textIndex--;
        }

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


int direction3(char word[] , char table[MAX_SIZE][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];

    for (int i = 0; i < tableLength; i++)
	{
		*col = i;
		for (int j = 0; j < tableLength; j++)
			text[j] = table[j][i];
		
		*row = rabinKarp(text, word, wordLength);

		if (rabinKarp(text, word, wordLength) != -1)
		{
			direction = 3;
			return direction;
		}
	}

    *row = 0, *col = 0, direction = 0;
    return direction;
}


int direction4(char word[] , char table[MAX_SIZE][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];
    for (int i = 0; i < tableLength; i++)
	{
		*col = i;
		for (int j = tableLength - 1, k = 0; j > -1; j--, k++)
		{	
			text[k] = table[j][i];
		}	
		
		*row = (tableLength - 1) - rabinKarp(text, word, wordLength);

		if (rabinKarp(text, word, wordLength) != -1)
		{
			direction = 4;
			return direction;
		}
	}

    *row = 0, *col = 0, direction = 0;
    return direction;
}


int direction5(char word[] , char table[MAX_SIZE][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];
	char emptyString[MAX_SIZE] = "";

	for (int i = 1; i <= tableLength + tableLength - 1; i++)
	{
		for (int col_index= 0; col_index < i; col_index++) 
		{
			int j = i - col_index;
			int row_index = tableLength - j;
			if (row_index >= 0 && row_index < tableLength && col_index < tableLength)
			{
				char string[MAX_SIZE] = "";
				strncat(string, &table[row_index][col_index], 1);
				strncat(text, string, strlen(string));
			}
		}
	
	if (i > tableLength)
	{
		*row = rabinKarp(text, word, wordLength);
		if (*row == 0)
			*col = i - tableLength;
		else
			*col = (i - tableLength) + *row;
	}


	else if (i == tableLength)
	{
		*col = rabinKarp(text, word, wordLength);
		*row = *col;
	}

	else
	{
		*col = rabinKarp(text, word, wordLength);
		*row = tableLength - (i - *col);
		//printf("text: %s || word: %s\n *col: %d || tableLength: %d || i: %d\n", text, word, *col, tableLength, i);
	};

	if (rabinKarp(text, word, wordLength) != -1)
	{
		direction = 5;
		return direction;
	}


	strcpy(text, emptyString);
	}

    *row = 0, *col = 0, direction = 0;
    return direction;
	
}


int direction6(char word[] , char table[MAX_SIZE][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = 0, *col = 0, direction = 0;
    char text[MAX_SIZE];
	char emptyString[MAX_SIZE] = "";

     // Reverse word[]
    char reversedWord[MAX_SIZE];
    int textIndex = wordLength -1;
    for (int i = 0; i < wordLength; i++)
    {
        reversedWord[i] = word[textIndex];
        textIndex--;
    }


	for (int i = 1; i <= tableLength + tableLength - 1; i++)
	{
		for (int col_index= 0; col_index < i; col_index++) 
		{
			int j = i - col_index;
			int row_index = tableLength - j;
			if (row_index >= 0 && row_index < tableLength && col_index < tableLength)
			{
				char string[MAX_SIZE] = "";
				strncat(string, &table[row_index][col_index], 1);
				strncat(text, string, strlen(string));
			}
		}
	
	if (i > tableLength)
	{
		*row = rabinKarp(text, reversedWord, wordLength);
		if (*row == 0)
			*col = i - tableLength + (wordLength - 1);
		else
			*col = (i - tableLength) + 1 + (wordLength - 1);

		*row += (wordLength - 1);
	}


	else if (i == tableLength)
	{
		*col = rabinKarp(text, reversedWord, wordLength) + (wordLength - 1);
		*row = *col;
	}


	else
	{
		*col = rabinKarp(text, reversedWord, wordLength) + (wordLength - 1);
		*row = tableLength - i + (wordLength - 1) + rabinKarp(text, reversedWord, wordLength);
		//printf("rabinKarp: %d\ni: %d || wordLength: %d || tableLength: %d\n*row: %d || *col: %d\n", rabinKarp(text, reversedWord, wordLength), i, wordLength, tableLength, *row, *col);

	};
	
	if (rabinKarp(text, reversedWord, wordLength) != -1)
	{
		direction = 6;
		return direction;
	}

	strcpy(text, emptyString);
	}	
    *row = 0, *col = 0, direction = 0;
    return direction;
	
}


int direction7(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = wordLength -1, direction = 0;
    char text[150] = "";
    int temp;
   
    while (*row < tableLength)
    {
        temp = *row;
        *col = 0;
        for (; *row >= 0; (*row)--)
        {
            strncat(text, &(table[*row][*col]), 1);
            (*col)++;
        }
        
        *col = rabinKarp(text, word, wordLength);
        *row = temp - *col;
        if (*col != -1)
        {
            direction = 7;
            return direction;
        }

        text[0] = '\0';
        *row = temp + 1;
    }
    
    *col = 1;
    while (*col <= tableLength - wordLength)
    {
        temp = *col;
        *row = tableLength -1;
        int total = *row + *col;
        for (; *row >= 0; (*row)--)
        {
            strncat(text, &(table[*row][*col]), 1);
            (*col)++;
        }

        *col = rabinKarp(text, word, wordLength);
        *row = tableLength - *col - 1;
        if (*col != -1)
        {
            *col = total - *row;
            direction = 7;
            return direction;
        }

        text[0] = '\0';
        *col = temp + 1;
    }

    *row = 0, *col = 0, direction = 0;
    return direction;
}


int direction8(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength)
{
    *row = wordLength -1, direction = 0;
    char text[150] = "";
    int temp;
   
    while (*row < tableLength)
    {
        temp = *row;
        *col = 0;
        int total = *col + *row;
        for (; *row >= 0; (*row)--)
        {
            strncat(text, &(table[*row][*col]), 1);
            (*col)++;
        }

        // Reverse the string
        char reversed[MAX_SIZE] = "";
        int textIndex = strlen(text) -1;
        for (int i = 0; i < strlen(text); i++)
        {
            reversed[i] = text[textIndex];
            textIndex--;
        }
        
        *col = rabinKarp(reversed, word, wordLength);
        *row = *col;
        if (*col != -1)
        {   
            *col = total - *col;
            direction = 8;
            return direction;
        }

        text[0] = '\0';
        *row = temp + 1;
    }

    *col = 1;
    while (*col <= tableLength - wordLength)
    {
        *row = tableLength -1;
        temp = *col;
        int total = *col + *row;

        for (; *row >= 0; (*row)--)
        {
            strncat(text, &(table[*row][*col]), 1);
            (*col)++;
        }

        // Reverse the string
        char reversed[MAX_SIZE] = "";
        int textIndex = strlen(text) -1;
        for (int i = 0; i < strlen(text); i++)
        {
            reversed[i] = text[textIndex];
            textIndex--;
        }

        *col = rabinKarp(reversed, word, wordLength);
        if (*col != -1)
        {   
            *col = (tableLength-1) - *col;
            *row = total - *col;
            direction = 8;
            return direction;
        }

        text[0] = '\0';
        *col = temp + 1;
    }

    *row = 0, *col = 0, direction = 0;
    return direction;
}


void printOutput(char wordlist[][MAX_SIZE], int wordlistLength, char table[][MAX_SIZE], int tableLength, int wordLength, FILE* outputFile)
{
    int row, col, direction = 0;
    char resultWord[MAX_SIZE];

    for (int i = 0; i < wordlistLength; i++)
    {
        strcpy(resultWord, wordlist[i]);

        direction = direction1(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 1)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

        direction = direction2(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 2)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

		direction = direction3(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 3)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

		direction = direction4(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 4)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

		direction = direction5(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 5)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

		direction = direction6(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 6)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

        direction = direction7(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 7)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

        direction = direction8(resultWord, table, &row, &col, direction, wordlistLength, tableLength, wordLength);
        if (direction == 8)
        {
            fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
            continue;
        }

        fprintf(outputFile, "%s;(%d,%d);%d\n", resultWord, row, col, direction);
    }
    return;
}

