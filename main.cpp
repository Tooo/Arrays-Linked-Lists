//main.cpp
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

int main () { 
    int menu = 0;
    while (menu != -1 ) {
        menu = Validate(0);
        if (menu == 0) Array();
        else if (menu == 1) LinkedList();
        else if (menu == 2) SStack();
        else if (menu == 3) QQueue();
        else if (menu == -1) printf("Bye!\n");
        else printf("Invalid Choice, please choose again\n");
    }
    return 0;
}