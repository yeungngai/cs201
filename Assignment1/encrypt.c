/***
CMPUT 201 Student Submission License Version 2.0

Copyright 2021 <Yi Yang, Samuel Iwelu>

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
* Name: Samuel Iwelu
* Student ID: 1574395
* CCID: iwelu
* Lecture section: B2 Nadi, Sarah
* Lab section: H04

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

    decryptstr[inputLength] = '\0';
    fprintf(stdout, "%s\n", decryptstr);
}

int main(int argc, char *argv[])
{
    if (argc != 7){
		fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>\n");
		exit(7);
	}
	
	int numline = 0;
	char mappingFilename[50] = "\0";
	char inputFilename[50] = "\0";
	int encryptionMode = -1;

	for (int i = 0; i<7; i++){
		char letter  = argv[i][1];
		switch( letter ){
			case 't':
				 strcpy(mappingFilename, argv[i+1]);
				break;
			case 'm':;
				char val = argv[i+1][0];
				if (val == '1'){
					encryptionMode = 1;
					break;
				} else if (val == '2'){
					encryptionMode = 2;
					break;
				} else {
					fprintf(stderr, "You entered %s. Sorry, your mode must be 1 for encryption or 2 for decryption\n", argv[i+1]);
					exit(6);
				}
				
			case 'i':
				strcpy(inputFilename, argv[i+1]);
				break;
		}
	}

	if ( (strcmp(mappingFilename, "\0") == 0) || (strcmp(inputFilename, "\0") == 0) || (encryptionMode == -1) ){
		fprintf(stderr, "Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>\n");
		exit(7);
	}

	FILE* mfilepath = fopen(mappingFilename, "r");
	FILE* ifilepath = fopen(inputFilename, "r");
	
	if (mfilepath == NULL) {
		fprintf(stderr,"Error: Mapping file %s does not exist\n", mappingFilename);
		exit(3);
	}

	// checking the format of mapping file
	int ciphertext[26] = {0};
	int plaintext[26] = {0};
	char currentChar;

	while( feof(mfilepath) == 0){  //&& (numline<26)
		currentChar = fgetc(mfilepath);
		int i = 0;
		while (currentChar != '\n'){
			int ordValue = currentChar;
			if (i == 1) {
				if ((ordValue != 44)) {  // must be lowercase or a comma
					fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
					exit(4);
					
				}
			} else if ( (i == 0 || i == 2) && (ordValue > 0) ) {
				if (!(ordValue >= 97 && ordValue <= 122)) {  // must be lowercase or a comma
					fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
					exit(4);
				}
			}

			if (ordValue > 0){
				if (i == 0) {
					int index;
					index = ordValue - 97;  // offsetting the char by its asii value
					plaintext[index] += 1;
				} else if (i == 2) {
					int index;
					index = ordValue - 97;  // offsetting the char by its asii value
					ciphertext[index] += 1;
				} else {
					if (ordValue != 44){ // is not a comma
						fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
						exit(4);
					}
				}
			}

			if (i > 3){
				fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
				exit(4);
			} else {
				i++;
			}

			currentChar = fgetc(mfilepath);
			if ( feof(mfilepath)){
				break;
			}
		}
		numline++;
		if ( feof(mfilepath)){
			break;
		}
	}

	// checking for alphabet restrictions in the mapping file alphhabets
	for (int j = 0; j<26; j++){
		if ((plaintext[j] != 1) || (ciphertext[j] != 1) ) {
			fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
			exit(4);
		}
	}
	if (numline != 26) {
		fprintf(stderr, "Error: The format of mapping file %s is incorrect\n", mappingFilename);
		exit(4);
	}

	// checking inputfile
	if (ifilepath == NULL) {
		fprintf(stderr,"Error: Input word file %s does not exist\n", inputFilename);
		exit(5);
	}

	// main portion of code
	rewind(mfilepath);

	int mappingArray[26][2] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, 
    {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, 
    {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};
    
    char lineFromMappingFile[1000];
    int row = 0;
    while (feof(mfilepath) == 0)
    {
        fgets(lineFromMappingFile, 5, mfilepath);
        mappingArray[row][1] = lineFromMappingFile[2];
        row = row + 1;
    }

	char lineFromTextFile [1000];
	
    while (feof(ifilepath) == 0)
    {
        fgets(lineFromTextFile, 21, ifilepath);
        int strlength = strlen(lineFromTextFile);

        if (lineFromTextFile[strlength-1] == '\n')
        {
            lineFromTextFile[strlength-1] = '\0';
        }

        strlength = strlen(lineFromTextFile);
        
        if (encryptionMode == 1)
        {
            encrypt(lineFromTextFile, strlength, mappingArray);
        }
        if (encryptionMode == 2)
        {
            decrypt(lineFromTextFile, strlength, mappingArray);
        }
    }

    fclose(mfilepath);
    fclose(ifilepath);
    return 0;
}
