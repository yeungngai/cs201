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
* Name: NicholasDuong
* Student ID: 1574003
* CCID: nduong
* Lecture section: B1
* Lab section: H03

***/

#ifndef PUZZLE2D_H
#define PUZZLE2D_H

#define MAX_SIZE 100
#define D 256
#define P 7079


int rabinKarp(char inputText[], char word[], int wordLength);
int direction1(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction2(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction3(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction4(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction5(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction6(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction7(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
int direction8(char word[] , char table[][MAX_SIZE], int *row, int *col, int direction, int wordlistLength, int tableLength, int wordLength);
void printOutput(char wordlist[][MAX_SIZE], int wordlistLength, char table[][MAX_SIZE], int tableLength, int wordLength, FILE* outputFile);


#endif
