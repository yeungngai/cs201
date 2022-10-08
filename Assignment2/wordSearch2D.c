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
#include "puzzle2D.h"
#define MAX_SIZE 100


int main(int argc, char *argv[])
{
	if (argc < 7 || argc > 9 || argc == 8){
		fprintf(stderr, "Usage: ./wordSearch2D -p <puzzle_file> -l <word_length> -w <wordlist_file> [-o <solution_file>]\n");
		exit(6);
	}

    int wordLength;
	char wordlistFileName[50] = "\0";
	char puzzleFileName[50] = "\0";
	char outputFileName[50] = "\0";


	if (argc == 7)
	{
		char defaultOutput[] = "output.txt";
		strcpy(outputFileName, defaultOutput);
		for (int i = 0; i<7; i++){
			char letter  = argv[i][1];
			switch( letter ){
				case 'p':
					strcpy(puzzleFileName, argv[i+1]);
					break;

				case 'w':
					strcpy(wordlistFileName, argv[i+1]);
					break;

				case 'l':
					wordLength = atoi(argv[i+1]);
					break;
			}
		}
	}

	else if (argc == 9)
	{
		for (int i = 0; i<8; i++){
			char letter  = argv[i][1];
			switch( letter ){
				case 'p':
					strcpy(puzzleFileName, argv[i+1]);
					break;

				case 'w':
					strcpy(wordlistFileName, argv[i+1]);
					break;

				case 'l':
					wordLength = atoi(argv[i+1]);
					break;
				case 'o':
					strcpy(outputFileName, argv[i+1]);
					break;
			}
		}
	}


    FILE* wordlistFile = fopen(wordlistFileName, "r");
    FILE* tableFile = fopen(puzzleFileName, "r");
	FILE* outputFile = fopen(outputFileName, "w");


    if (wordlistFile == NULL)
    {
        fprintf(stderr, "Error: Wordlist file <%s> does not exist\n", wordlistFileName);
        exit(5);
    }
    if (tableFile == NULL)
    {
        fprintf(stderr, "Error: Puzzle file <%s> does not exist\n", puzzleFileName);
        exit(4);
    }

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

    if (wordLength != strlen(wordlist[0]))
    {
        fprintf(stderr, "Encountered error");
        exit(7);
    }

    // Check Ascii code
    for (int i = 0; i < wordlistLength; i ++)
    {
        for (int j = 0; j < strlen(wordlist[0]); j++)
        {
            if ((32 > wordlist[i][j]) || (126 < wordlist[i][j]))
            {
                fprintf(stderr, "Encountered error\n");
                exit(7);
            }
        }
    }
    for (int i = 0; i < tableLength; i ++)
    {
        for (int j = 0; j < strlen(table[0]); j++)
        {
            if ((32 > table[i][j]) || (126 < table[i][j]))
            {
                fprintf(stderr, "Encountered error\n");
                exit(7);
            }
        }
    }    

    char checkDuplicate[MAX_SIZE] = "";
    for (int i = 0; i < wordlistLength; i++)
    {
        strcpy(checkDuplicate, wordlist[i]);
        for (int j = i + 1; j < wordlistLength; j++)
        {
            if ((strcmp(checkDuplicate, wordlist[j])) == 0)
            {
                fprintf(stderr, "Encountered error");
                exit(7);
            }
        }
    }

    printOutput(wordlist, wordlistLength, table, tableLength, wordLength, outputFile);

    return 0;
}

