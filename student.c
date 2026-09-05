#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student_manager.h"

void initList(StudentList *list) {
    list->data = malloc(5 * sizeof(Student));
    list->count = 0;
    list->capacity = 5;
}

void freeList(StudentList *list) {
    free(list->data);
}

int getNextId(const StudentList *list) {
    int max_id = 0;
    for (int i = 0; i < list->count; i++) {
        if (list->data[i].id > max_id) {
            max_id = list->data[i].id;
        }
    }
    return max_id + 1;
}

void ensureCapacity(StudentList *list) {
    if (list->count < list->capacity) {
        return;
    }
    
    int yeni_capacity = list->capacity * 2;
    Student *temp = realloc(list->data, yeni_capacity * sizeof(Student));
    if (temp == NULL) {
        printf("Yaddas xetasi!\n");
        return;
    }
    list->data = temp;
    list->capacity = yeni_capacity;
}

void appendStudentToFile(const Student *s) {
    FILE *fp = fopen("Students.txt", "a");
    if (fp == NULL) {
        return;
    }
    fprintf(fp, "%d|%s|%s|%s|%.2f\n", s->id, s->name, s->surname, s->major, s->gpa);
    fclose(fp);
}

void addStudent(StudentList *list) {
    Student s;
    s.id = getNextId(list);

    printf("Ad: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Soyad: ");
    fgets(s.surname, sizeof(s.surname), stdin);
    s.surname[strcspn(s.surname, "\n")] = '\0';

    printf("Ixtisas: ");
    fgets(s.major, sizeof(s.major), stdin);
    s.major[strcspn(s.major, "\n")] = '\0';

    while (1) {
        printf("GPA (0.0 - 4.0): ");
        char buf[32];
        if (fgets(buf, sizeof(buf), stdin) == NULL) continue;

        char *endptr;
        float val = strtof(buf, &endptr);

        if (endptr == buf || (*endptr != '\n' && *endptr != '\0') || val < 0.0f || val > 4.0f) {
            printf("Xetali daxil etme. Yanliz 0.0 - 4.0 arasi eded girin.\n");
            continue;
        }
        s.gpa = val;
        break; 
    }

    ensureCapacity(list);
    list->data[list->count++] = s;
    appendStudentToFile(&s);
    printf("Telebe uqurla elave olundu!\n");
}

void loadStudents(StudentList *list) {
    FILE *fp = fopen("Students.txt", "r");
    if (fp == NULL) {
        return;
    }

    Student tmp;
    while (fscanf(fp, "%d|%99[^|]|%99[^|]|%99[^|]|%f\n",
                  &tmp.id, tmp.name, tmp.surname, tmp.major, &tmp.gpa) == 5) {
        ensureCapacity(list);
        list->data[list->count++] = tmp;
    }

    fclose(fp);
}

void displayStudents(const StudentList *list) {
    if (list->count == 0) {
        printf("\nSistemde telebe tapilmadi.\n");
        return;
    }

    printf("\n------------------------------------------\n");
    printf("           Telebelerin Siyahisi           \n");
    printf("------------------------------------------\n");

    for (int i = 0; i < list->count; i++) {
        printf("ID: %d | Ad: %s | Soyad: %s | Ixtisas: %s | GPA: %.2f\n", 
               list->data[i].id, 
               list->data[i].name, 
               list->data[i].surname, 
               list->data[i].major, 
               list->data[i].gpa);
    }
    printf("------------------------------------------\n");
}

int readMenuChoice(void) {
    char buf[64];
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return -1;
    }

    char *endptr;
    long val = strtol(buf, &endptr, 10);

    if (endptr == buf || (*endptr != '\n' && *endptr != '\0')) {
        return -1;
    }
    if (val < 1 || val > 5) {
        return -1;
    }

    return (int)val;
}