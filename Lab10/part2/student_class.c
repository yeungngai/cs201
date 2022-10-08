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
Lab 10 part 2

* Name: Yi Yang
* Student ID: 1542688
* CCID: yyang13
* Lecture Section: B2
* Instructor: Sarah Nadi
* Lab Section: H02
* TA: Panyu Lu

***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
int studentID;
char name[20];
} Student;


int main()
{
    Student *students = malloc(2 * (sizeof(Student)));
    int input, index = 0, num = 0, allocated = 2;

    while (num < 5)
    {
        printf("Enter operation: ");
        scanf("%d", &input);

        if (input == 1)
        {
            num = num + 1;
            if ((num > 2) && (num <= 5) && (allocated < 5))
            {
                students = realloc(students, num*sizeof(Student));
                allocated = allocated + 1;
            }

            Student student;
            int id;
            char studentName[20] = "\0";
            printf("Enter ID to add (%d spots available): ", 6 - num);
            scanf("%d", &id);

            printf("Enter student name: ");
            scanf("%s", studentName);

            int check = 0;
            for (int i = 0; i < num; i++)
            {
                if (students[i].studentID == -1)
                {
                    check = 1;
                    student.studentID = id;
                    strcpy(student.name, studentName);
                    students[i] = student;
                    break;
                }
            }

            if (check == 0)
            {
                student.studentID = id;
                strcpy(student.name, studentName);
                students[index] = student;
                index = index + 1;
            }
        }

        else if (input == 2)
        {
            int id;
            printf("Enter ID to drop: ");
            scanf("%d", &id);
            for (int i = 0; i < num; i++)
            {
                if (students[i].studentID == id)
                {
                    students[i].studentID = -1;
                    num = num - 1;
                    break;
                }
            }
        }

        else if (input == 0)
        {
            break;
        }
    }

    if (num == 5)
    {
        printf("You have reached the maximum capacity of the class. You have 5 students in the class:\n");
    }
    else
    {
        printf("You have %d students in the class:\n", num);
    }

    for (int i = 0; i < num; i++)
    {
        printf("%d, %s\n", students[i].studentID, students[i].name);
    }

    free(students);

    return 0;
}