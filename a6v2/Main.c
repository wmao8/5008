#include <stdio.h>
#include "Sort.h"
#include "LinkedList_easy.h"
#include <time.h>
#include <stdlib.h>
// #include "LinkedList.c"
// #include "Sort.c"

#define NUMCHAR_SIZE 5

int getRan() {
    return rand();
}


int main() {
    srand(time(NULL));
    // Random List1;

    LinkedList rList = CreateLinkedList();
    for (int i = 0; i < 50; ++i) {
        int numerInt = getRan() % 100 + 1;
        char *numchar = malloc(5 * sizeof(*numchar));
        if (numchar == NULL) {
            printf("Malloc failed");
        }

        snprintf(numchar, NUMCHAR_SIZE, "%d", numerInt);
        int sorf = InsertLinkedList(rList, numchar);
        if (sorf == 1) {
            printf("Insert failed");
            free(numchar);
        }
    }

    // Print Random List 1
    printf("Unsorted list1: ");
    LinkedListNode *current = rList->head;
    while (current != NULL) {
        printf("%s", current->payload);
        printf(", ");
        current = current->next;
    }
    printf("End \n");

    // Sort Insertion
    printf("Sort Insertion: ");
    fflush(stdout);

    SortInsertion(&rList);
    current = rList->head;

    while (current != NULL) {
        printf("%s", current->payload);
        printf(", ");
        current = current->next;
    }
    printf("\n");
    printf("\n");
    DestroyLinkedList(rList);


    // Random List2

    LinkedList rList2 = CreateLinkedList();
    for (int i = 0; i < 50; ++i) {
        int numerInt = getRan() % 100 + 1;
        char *numchar = malloc(5 * sizeof(*numchar));

        if (numchar == NULL) {
            printf("Malloc failed");
        }
        snprintf(numchar, NUMCHAR_SIZE, "%d", numerInt);
        int sorf = InsertLinkedList(rList2, numchar);
        if (sorf == 1) {
            printf("Insert failed");
            free(numchar);
        }
    }
    // Print Random List2

    printf("Unsorted list2: ");
    LinkedListNode *current2 = rList2->head;
    while (current2 != NULL) {
        printf("%s", current2->payload);
        printf(", ");
        current2 = current2->next;
    }
    printf("\n");

    // SortSelection
    printf("Sort Selection: ");
    SortSelection(&rList2);

    // Print sorted list2

    current2 = rList2->head;

    while (current2 != NULL) {
        printf("%s", current2->payload);
        printf(", ");
        current2 = current2->next;
    }
    printf("\n");
    printf("\n");
    DestroyLinkedList(rList2);


    // Random List 3

    LinkedList rList3 = CreateLinkedList();
    for (int i = 0; i < 50; ++i) {
        int numerInt = getRan() % 100 + 1;
        char *numchar = malloc(5 * sizeof(*numchar));

        if (numchar == NULL) {
            printf("Malloc failed");
        }
        snprintf(numchar, NUMCHAR_SIZE, "%d", numerInt);
        int sorf = InsertLinkedList(rList3, numchar);
        if (sorf == 1) {
            printf("Insert failed");
            free(numchar);
        }
    }

    // Print Random List 3

    printf("Unsorted list3: ");
    LinkedListNode *current3 = rList3->head;

    while (current3 != NULL) {
        printf("%s", current3->payload);
        printf(", ");
        current3 = current3->next;
    }
    printf("\n");

    SortMerge(rList3);

    // SortMerge

    printf("Sort Merge: ");
    SortMerge(rList3);

    // Print Sorted List 3

    current3 = rList3->head;

    while (current3 != NULL) {
        printf("%s", current3->payload);
        printf(", ");
        current3 = current3->next;
    }
    printf("\n");
    printf("\n");
    DestroyLinkedList(rList3);

//    printf("Print final from main");

//    PrintList(current3);
}
