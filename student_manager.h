#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    char surname[100];
    char major[100];
    float gpa;
} Student;

typedef struct {
    Student *data;
    int count;
    int capacity;
} StudentList;

void initList(StudentList *list);
void freeList(StudentList *list);
void ensureCapacity(StudentList *list);
int  getNextId(const StudentList *list);
void appendStudentToFile(const Student *s);
void loadStudents(StudentList *list);
void addStudent(StudentList *list);
void displayStudents(const StudentList *list);
int  readMenuChoice(void);
void rewriteFile(const StudentList *list);
void deleteStudent(StudentList *list, int id);
void updateStudent(StudentList *list, int id);

#endif