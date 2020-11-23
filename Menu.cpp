//Menu.cpp
#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Classes.h"

void PrintMenu (int num) {
    if (num == 0) {
        printf("\nMain Menu\n");
        printf(" 0 - Array\n");
        printf(" 1 - Linked List\n");
        printf(" 2 - Stack\n");
        printf(" 3 - Queue\n");
        printf("-1 - Leave Menu\n");
    } 
    else if (num == 1) {
        printf("\nArray Menu\n");
        printf(" 0 - Create Random Array\n");
        printf(" 1 - Print Array\n");
        printf(" 2 - Selection Sort\n");
        printf(" 3 - Insertion Sort\n");
        printf(" 4 - Linear Search\n");
        printf(" 5 - Binary Search\n");
        printf(" 6 - Merge Sort\n");
        printf(" 7 - Quick Sort\n");
        printf("-1 - Leave Menu\n");
    }
    else if (num == 2) {
        printf("\nLinked List Menu\n");
        printf(" 0 - Print Linked List\n");
        printf(" 1 - Append\n");
        printf(" 2 - Preappend\n");
        printf(" 3 - Remove Head\n");
        printf(" 4 - Remove Tail\n");
        printf("-1 - Leave Menu\n");
    }
    else if (num == 3) {
        printf("\nStack Menu\n");
        printf(" 0 - Push\n");
        printf(" 1 - Pop\n");
        printf("-1 - Leave Menu\n");
    }
    else if (num == 4) {
        printf("\nQueue Menu\n");
        printf(" 0 - Enqueue\n");
        printf(" 1 - Dequeue\n");
        printf("-1 - Leave Menu\n");
    }

}

int Validate (int num) {
    int result;
    PrintMenu(num);
    while (!(scanf("%d", &result))) {
            printf(" Numbers Only\n");
            PrintMenu(num);
            getchar();
    }
    return result;
}

void Array () {
    int len, target;

    printf("Creating Random Array\nArray length: ");
    scanf("%d", &len);
    int * array = new int[len];
    CreateRandomArray(array, len);
    PrintArray(array, len);

    int arraymenu = 0;
    while (arraymenu != -1) {
        arraymenu = Validate(1);

        if (arraymenu == 0) {
            delete[] array;
            printf("Array length: ");
            scanf("%d", &len);
            int * array = new int[len];
            CreateRandomArray(array, len);
            PrintArray(array, len);
        }
        else if (arraymenu == 1) PrintArray(array, len);
        else if (arraymenu == 2) SelectionSort(array, len);
        else if (arraymenu == 3) InsertionSort(array, len);
        else if (arraymenu == 4 || arraymenu == 5) {
            printf("Target: ");
            scanf("%d", &target);
            if (arraymenu == 4) {
                printf("Search: %d\n", LinearSearch(array, len, target));
            } else {
                printf("Search: %d\n", BinarySearch(array, len, target));
            }
        }
        else if (arraymenu == 6) MergeSort(array, 0, len-1);
        else if (arraymenu == 7) QuickSort(array, 0, len-1);
        else if (arraymenu == -1) printf("Back to Main Menu\n");
        else printf("Invalid Choice, please choose again\n");        
    }
    delete[] array;
}

void LinkedList () {
    int val;
    LL * list = new LL;
    
    int llmenu = 0;
    while (llmenu != -1) {
        llmenu = Validate(2);

        if (llmenu == 1 || llmenu == 2) {
            printf("Value: ");
            scanf("%d", &val);
            if (llmenu == 1) list->Append(val);
            else list->Prepend(val);
        } 
        else if (llmenu == 3) list->RemoveHead();
        else if (llmenu == 4) list->RemoveTail();

        if (llmenu >= 0 && llmenu <=4) list->Print();
        else if (llmenu == -1) printf("Back to Main Menu\n");
        else printf("Invalid Choice, please choose again\n");
    }
    delete list;
}

void SStack () {
    int val;
    Stack * slist = new Stack;
    int smenu = 0;
    while (smenu != -1) {
        smenu = Validate(3);

        if (smenu == 0) {
            printf("Value: ");
            scanf("%d", &val);
            slist->Push(val);
        }
        else if (smenu == 1) slist->Pop();

        if (smenu == 0 || smenu == 1) slist->Print();
        else if (smenu == -1) printf("Back to Main Menu\n");
        else printf("Invalid Choice, please choose again\n");
    }

    delete slist;
}

void QQueue () {
    int val;
    Queue * qlist = new Queue;
    int qmenu = 0;
    while (qmenu != -1) {
        qmenu = Validate (4);

        if (qmenu == 0) {
            printf("Value: ");
            scanf("%d", &val);
            qlist->Enqueue(val);
        }
        else if (qmenu == 1) qlist->Dequeue();

        if (qmenu == 0 || qmenu == 1) qlist->Print();
        else if (qmenu == -1) printf("Back to Main Menu\n");
        else printf("Invalid Choice, please choose again\n");
    }
    delete qlist;
}