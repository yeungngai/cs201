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

// Name: Yi Yang
// Student ID: 1542688
// CCID: yyang13
// Lecture section: B2
// Instructor's name: Sarah Nadi
// Lab section: H02


#include <stdio.h>

int main(void)
{
    int dollarAmount, twentyBill, tenBill, fiveBill, oneBill;

    twentyBill = 0;
    tenBill = 0;
    fiveBill = 0;
    oneBill = 0;

    printf("\nEnter a dollar amount: ");
    scanf("%d", &dollarAmount);

    while (dollarAmount >= 20)
    {
        dollarAmount = dollarAmount - 20;
        twentyBill = twentyBill + 1;
    }

    while (dollarAmount >= 10)
    {
        dollarAmount = dollarAmount - 10;
        tenBill = tenBill + 1;
    }

    while (dollarAmount >= 5)
    {
        dollarAmount = dollarAmount - 5;
        fiveBill = fiveBill + 1;   
    }

    while (dollarAmount > 0)
    {
        dollarAmount = dollarAmount - 1;
        oneBill = oneBill + 1;
    }
        
    printf("\n$20 bills: %d \n$10 bills: %d \n$5 bills: %d \n$1 bills :%d\n\n", twentyBill, tenBill, fiveBill, oneBill);

    return 0;

}

