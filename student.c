#include "Student_manager.h"



#define MAX_LENGTH 100

typedef struct{
    int id;
    char name[100];
    char surname[100];
    char major[100];
    float gpa;
}Student;

typedef struct{
    Student *data;
    int count;
    int capacity;
}StudentList;


void initList(StudentList *list) {
    list->data = malloc(5 *sizeof(Student));
    list->count = 0;
    list->capacity = 5;
}

void freeList(StudentList *list) {
    free(list->data);
}

int getNextId(const StudentList *list){
    int max_id = 0 ;
    for(int i = 0; i < list->count; i++){
        if(list->data[i].id > max_id){
            max_id = list->data[i].id;
        }
    }
    return max_id + 1;
}

void ensureCapacity(StudentList *list){
    if (list->count < list->capacity)
    {
        return;
    }
    
    int yeni_capacity = list->capacity * 2;
    Student *temp = realloc(list->data, yeni_capacity * sizeof(Student));
    if (temp == NULL)
    {
        printf("yaddas error");
        return;
    }
    list->data = temp;
    list->capacity = yeni_capacity;
}

void addStudent(StudentList *list) {
    Student s;
    s.id = getNextId();
}