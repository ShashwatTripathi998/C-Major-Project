#ifndef DIARY_H
#define DIARY_H

#include <stdio.h>

struct Diary {
    char date[20];
    char title[50];
    char content[500];
};

// Function Declarations
void ADDentry();
void VIEWentry();
void SEARCHentry();
void EDITentry();
void DELETEentry();

#endif