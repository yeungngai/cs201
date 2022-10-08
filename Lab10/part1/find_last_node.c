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
Lab 10 part 1

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/


#include <stdio.h>
#include "linked_list.h"


int main(){
	
	struct node *linked_list = NULL;

	linked_list = add_to_list(linked_list, 5, 'a');
	linked_list = add_to_list(linked_list, 10, 'b');
	linked_list = add_to_list(linked_list, 4, 'c');
	linked_list = add_to_list(linked_list, 10, 'd');
	linked_list = add_to_list(linked_list, 5, 'e');
	linked_list = add_to_list(linked_list, 7, 'f');
	linked_list = add_to_list(linked_list, 5, 'g');
	linked_list = add_to_list(linked_list, 3, 'h');


	int search_number;
	printf("Enter number you want to search for:");
	scanf("%d", &search_number);

	struct node *last_node = find_last(linked_list, search_number);
	if (last_node != NULL)
	{
		printf("Node found: value = %d and marker = %c\n", last_node->value, last_node->marker);
	}else{
		printf("Number not found!\n");
	}

	linked_list = free_list(linked_list);
	
	//running your program using valgrind will show you memory leaks. You need to make sure
    //you free any allocated memory before you exit the program
}

