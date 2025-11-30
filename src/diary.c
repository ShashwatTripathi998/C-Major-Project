#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/diary.h"

// Add New Entry
void ADDentry() {
    FILE *fp = fopen("diary.txt", "a");
    struct Diary d;

    if (!fp) {
        printf("\nError: Unable to open diary file.\n");
        return;
    }

    printf("\nEnter the date (DD-MM-YYYY): ");
    fgets(d.date, sizeof(d.date), stdin);

    printf("Enter the title: ");
    fgets(d.title, sizeof(d.title), stdin);

    printf("Enter the content:\n> ");
    fgets(d.content, sizeof(d.content), stdin);

    fprintf(fp, "%s|%s|%s", d.date, d.title, d.content);
    fclose(fp);

    printf("\nEntry saved successfully.\n");
}

// View All Entries
void VIEWentry() {
    FILE *fp = fopen("diary.txt", "r");
    struct Diary d;

    if (!fp) {
        printf("\nNo entries found.\n");
        return;
    }

    printf("\n========== SAVED DIARY ENTRIES ==========\n");

    while (fscanf(fp, "%19[^|]|%49[^|]|%499[^\n]\n",
                  d.date, d.title, d.content) != EOF) {
        printf("\n----------------------------------------\n");
        printf("Date  : %s", d.date);
        printf("Title : %s", d.title);
        printf("Entry :\n%s\n", d.content);
    }

    fclose(fp);
}

// Search Entry by Date
void SEARCHentry() {
    FILE *fp = fopen("diary.txt", "r");
    struct Diary d;
    char searchDate[20];
    int found = 0;

    if (!fp) {
        printf("\nNo entries available to search.\n");
        return;
    }

    printf("\nEnter the date to search (DD-MM-YYYY): ");
    fgets(searchDate, sizeof(searchDate), stdin);

    while (fscanf(fp, "%19[^|]|%49[^|]|%499[^\n]\n",
                  d.date, d.title, d.content) != EOF) {
        if (strcmp(searchDate, d.date) == 0) {
            printf("\nEntry Found:\n");
            printf("Date  : %s", d.date);
            printf("Title : %s", d.title);
            printf("Entry :\n%s\n", d.content);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nNo entry exists for that date.\n");
}

// Edit Entry
void EDITentry() {
    FILE *fp = fopen("diary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Diary d;
    char searchDate[20];
    int found = 0;

    if (!fp || !temp) {
        printf("\nNo entries available to edit.\n");
        return;
    }

    printf("\nEnter the date of the entry to edit: ");
    fgets(searchDate, sizeof(searchDate), stdin);

    while (fscanf(fp, "%19[^|]|%49[^|]|%499[^\n]\n",
                  d.date, d.title, d.content) != EOF) {

        if (strcmp(searchDate, d.date) == 0) {
            printf("\nEditing Entry...\n");

            printf("Enter new title: ");
            fgets(d.title, sizeof(d.title), stdin);

            printf("Enter new content:\n> ");
            fgets(d.content, sizeof(d.content), stdin);

            found = 1;
        }

        fprintf(temp, "%s|%s|%s", d.date, d.title, d.content);
    }

    fclose(fp);
    fclose(temp);

    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found)
        printf("\nEntry updated successfully.\n");
    else
        printf("\nNo entry found for the given date.\n");
}

// Delete Entry
void DELETEentry() {
    FILE *fp = fopen("diary.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Diary d;
    char searchDate[20];
    int found = 0;

    if (!fp || !temp) {
        printf("\nError: Unable to open file.\n");
        return;
    }

    printf("\nEnter the date of the entry to delete: ");
    fgets(searchDate, sizeof(searchDate), stdin);
    searchDate[strcspn(searchDate, "\n")] = '\0';

    while (fscanf(fp, "%19[^|]|%49[^|]|%499[^\n]\n",
                  d.date, d.title, d.content) != EOF) {

        d.date[strcspn(d.date, "\n")] = '\0';
        d.title[strcspn(d.title, "\n")] = '\0';
        d.content[strcspn(d.content, "\n")] = '\0';

        if (strcmp(searchDate, d.date) != 0) {
            fprintf(temp, "%s|%s|%s\n",
                    d.date, d.title, d.content);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (found)
        printf("\nEntry deleted successfully.\n");
    else
        printf("\nNo entry found for the given date.\n");
}