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
Lab 4

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void print_array (int n, int m, char walk[n][m]) 
{
     for (int row = 0; row < n; row++)
     {
         for (int col = 0; col < m; col++)
         {
             printf("%c ", walk[row][col]);
         }
         printf("\n");
     }
}


void generate_random_walk (int n, int m, char walk[n][m]) 
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            walk[row][col] = '.';
        }
    }

    char endCh = 'Z';
    
    int  rowNum = 0, colNum = 0, tempRow, tempCol, index;
    char ch;
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    walk[rowNum][colNum] = letters[0];

    for (index = 1; index < 26; index++)
    {
        ch = letters[index];
        int count = 0, randNum = rand() % 4;
        int countList[4] = {-1, -1, -1, -1};

        switch (randNum)
        {
            // move up
            case 0:
                tempRow = rowNum - 1;
                tempCol = colNum;
                break;

            // move left
            case 1:
                tempRow = rowNum;
                tempCol = colNum - 1;
                break;

            // move down
            case 2:
                tempRow = rowNum + 1;
                tempCol = colNum;
                break;

            // move right
            case 3:
                tempRow = rowNum;
                tempCol = colNum + 1;
                break;
        }

        // check if the next move is within the array and not visited. If either one is not satisfied, enter the loop.
        while ((tempRow < 0) || (tempRow >= n) || (tempCol < 0) || (tempCol >= m) || (walk[tempRow][tempCol] != '.'))
        {
            // check if the new random number has been previously tested.
            if (countList[randNum] != randNum)
            {
                countList[randNum] = randNum;
                count = count + 1;
            }

            // if the count variable is 4, then all directions will not work for the next move and will exit the loop.
            if (count == 4)
            {
                printf("Walked until letter %c\n", letters[index-1]);
                print_array (n, m, walk);
                exit(EXIT_FAILURE);
            }

            // reassign tempRow and tempCol for testing
            randNum = rand() % 4;
            switch (randNum)
            {
                // move up
                case 0:
                    tempRow = rowNum - 1;
                    tempCol = colNum;
                    break;

                // move left
                case 1:
                    tempRow = rowNum;
                    tempCol = colNum - 1;
                    break;

                // move down
                case 2:
                    tempRow = rowNum + 1;
                    tempCol = colNum;
                    break;

                // move right
                case 3:
                    tempRow = rowNum;
                    tempCol = colNum + 1;
                    break;
            }
        }

        rowNum = tempRow;
        colNum = tempCol;

        // update walk array 
        walk[rowNum][colNum] = ch;

        if (ch == endCh)
        {
            break;
        }
    }

    // print out the array
    printf("Walked until letter Z\n");
    print_array (n, m, walk);
}


int main() 
{
    int row, col;
    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of col: ");
    scanf("%d", &col);

    char walkArray[row][col];
    generate_random_walk(row, col, walkArray);

    return 0;
}

