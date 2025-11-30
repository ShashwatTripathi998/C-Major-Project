#include <stdlib.h>
#include "../include/utils.h"

// Cross-platform clear screen function
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}