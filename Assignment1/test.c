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

/***
Team: Asgmt1_team25

Student 1:
* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture section: B2 Nadi, Sarah
* Lab section: H02

Student 2:


***/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encrypt (char plainText[], int inputLength, int encryptionArray[26][2])
{
    char encryptstr[inputLength];

    for (int i = inputLength - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (plainText[i] == encryptionArray[j][0])
            {
                encryptstr[inputLength - i - 1] = encryptionArray[j][1];
            }
        }
    }

    int encryplength = strlen(encryptstr);

    encryptstr[inputLength] = '\0';
    fprintf(stdout, "%s\n", encryptstr);
}



void decrypt (char cipherText[], int inputLength, int decryptionArray[26][2])
{
    char decryptstr[inputLength];

    for (int i = inputLength - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cipherText[i] == decryptionArray[j][1])
            {
                decryptstr[inputLength - i - 1] = decryptionArray[j][0];
            }
        }
    }

    int decryplength = strlen(decryptstr);

    decryptstr[inputLength] = '\0';
    fprintf(stdout, "Text: %s\n", decryptstr);
}



int main (int argc, char *argv[])
{
    
    FILE *textFile, *mappingFile, *mode;
    
    
    //open files and assign mode attribute
    if ((strcmp(argv[1], "-t") == 0) && (strcmp(argv[3], "-m") == 0) && (strcmp(argv[5], "-i") == 0))
    {
        mappingFile = fopen(argv[2], "r");
        mode = fopen(argv[4], "r");
        textFile = fopen(argv[6], "r");
    }
    if ((strcmp(argv[1], "-t") == 0) && (strcmp(argv[5], "-m") == 0) && (strcmp(argv[3], "-i") == 0))
    {
        mappingFile = fopen(argv[2], "r");
        mode = fopen(argv[6], "r");
        textFile = fopen(argv[4], "r");
    }
    if ((strcmp(argv[3], "-t") == 0) && (strcmp(argv[1], "-m") == 0) && (strcmp(argv[5], "-i") == 0))
    {
        mappingFile = fopen(argv[4], "r");
        mode = fopen(argv[2], "r");;
        textFile = fopen(argv[6], "r");
    }
    if ((strcmp(argv[3], "-t") == 0) && (strcmp(argv[1], "-m") == 0) && (strcmp(argv[3], "-i") == 0))
    {
        mappingFile = fopen(argv[6], "r");
        mode = fopen(argv[2], "r");;
        textFile = fopen(argv[4], "r");
    }
    if ((strcmp(argv[3], "-t") == 0) && (strcmp(argv[5], "-m") == 0) && (strcmp(argv[1], "-i") == 0))
    {
        mappingFile = fopen(argv[4], "r");
        mode = fopen(argv[6], "r");
        textFile = fopen(argv[2], "r");
    }
    if ((strcmp(argv[5], "-t") == 0) && (strcmp(argv[3], "-m") == 0) && (strcmp(argv[1], "-i") == 0))
    {
        mappingFile = fopen(argv[6], "r");
        mode = fopen(argv[4], "r");;
        textFile = fopen(argv[2], "r");
    }


    int mappingArray[26][2] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, 
    {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, 
    {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

    char lineFromMappingFile[1000];
    int row = 0;
    while (feof(mappingFile) == 0)
    {
        fgets(lineFromMappingFile, 5, mappingFile);
        mappingArray[row][1] = lineFromMappingFile[2];
        row = row + 1;
    }

    fclose(mappingFile);
    fclose(textFile);

    // print out mapping file as an array (encryptionArray)
     for (int row = 0; row < 26; row++)
    {
        printf("Column 1: %c  Column2: %c\n\n", mappingArray[row][0], mappingArray[row][1]);
    }


    // char lineFromTextFile [1000];

    // while (feof(textFile) == 0)
    // {
    //     fgets(lineFromTextFile, 21, textFile);
    //     int strlength = strlen(lineFromTextFile);

    //     if (lineFromTextFile[strlength-1] == '\n')
    //     {
    //         lineFromTextFile[strlength-1] = '\0';
    //     }

    //     strlength = strlen(lineFromTextFile);
    //     decrypt(lineFromTextFile, strlength, mappingArray);
    // }

    // return 0;


}

