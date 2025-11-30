#ifndef DIARY_H
#define DIARY_H

#include <stdio.h>

struct Diary {
    char date[20];
    char title[50];
    char content[500];
};

/* here i have made 5 void fuctions and each function is made for different tasks
 which will be specified later in the program*/
void ADDentry();
void VIEWentry();
void SEARCHentry();
void EDITentry();
void DELETEentry();

#endif
