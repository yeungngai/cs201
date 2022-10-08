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
Lab 7 Part 3

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/


#include <stdio.h>

#define LEN 10

int sum_two_dimensional_array(int a[][LEN], int n){
	
	int *i, sum = 0;
	i = &a[0][0];
	
	for (int j = 0; j < n*LEN; j++)
	{
		sum = sum + *i;
		i++;
	}
			
	return sum;
}

int main(){
	int numbers[2][LEN] = {{1,2,3,4,5,6,7,8,9,10},
				{2,3,4,5,6,7,8,9,10,11}};

	printf("The sum of all elements of the array is: %d\n", sum_two_dimensional_array(numbers, 2));

	return 0;
}