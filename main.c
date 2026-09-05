#include <stdio.h>
#include "Student_manager.h"

static void printMenu(void) {
    printf("\n===== Telebe Idareetme Sistemi =====\n");
    printf("1. Telebe elave et\n");
    printf("2. Telebeni sil\n");
    printf("3. Telebelerin siyahisini goster\n");
    printf("4. Telebe melumatlarini yenile\n");
    printf("5. Cixis\n");
    printf("Seciminizi daxil edin: ");
}

int main(void) {
    StudentList list;
    initList(&list);
    loadStudents(&list);

    int running = 1;
    while (running) {
        printMenu();
        int choice = readMenuChoice();

        switch (choice) {
            case 1:
                addStudent(&list);
                break;
            case 2:
                // Silme funksiyasi
                break;
            case 3:
                displayStudents(&list);
                break;
            case 4:
                // Yenileme funksiyasi
                break;
            case 5:
                running = 0;
                break;
            default:
                printf("Zehmet olmasa yanliz 1-5 arasi reqemler girin.\n");
                break;
        }
    }

    freeList(&list);
    return 0;
}