#include <stdio.h>
#include <stdlib.h>
#include "../include/diary.h"
#include "../include/utils.h"

int main() {
    int choice;

    while (1) {
        clear_screen();

        printf("\n========================================");
        printf("\n        PERSONAL DIARY MANAGEMENT       ");
        printf("\n========================================\n");

        printf("\nOptions:\n");
        printf("1. Write a new entry\n");
        printf("2. View all saved entries\n");
        printf("3. Search an entry\n");
        printf("4. Edit an existing entry\n");
        printf("5. Delete an entry\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            ADDentry();
            break;
        case 2:
            VIEWentry();
            break;
        case 3:
            SEARCHentry();
            break;
        case 4:
            EDITentry();
            break;
        case 5:
            DELETEentry();
            break;
        case 6:
            printf("\nThank you for using this diary system.\nGoodbye!\n");
            exit(0);
        default:
            printf("\nInvalid option. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}