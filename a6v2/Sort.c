
#include "LinkedList_easy.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
// #include "LinkedList.c"


void SortInsertion(LinkedList *list) {
    // Check if list is null

    if (((*list) == NULL)
        || (*list)->head == NULL
        || (*list)->head->next == NULL) {
        return;
    }

    // Creating a new list to put sorted nodes
    LinkedList newList = CreateLinkedList();
    while ((*list)->head != NULL) {
        // Taking the head of the unsorted list one by one
        LinkedListNode *insert = (*list)->head;
        (*list)->head = (*list)->head->next;

        if ((*list)->head != NULL) {
            (*list)->head->prev = NULL;
        } else {
            (*list)->tail = NULL;
        }

        // Find the position to place insert node
        LinkedListNode *cur = newList->head;
        LinkedListNode *pre = NULL;


        while (cur != NULL && (atoi(cur->payload) < atoi(insert->payload))) {
            pre = cur;
            cur = cur->next;
        }

        // Insert node called insert
        // When insert node  is the head
        if (pre == NULL) {
            insert->next = newList->head;
            if (newList->head != NULL) {
                newList->head->prev = insert;
            }
            newList->head = insert;
        } else {  // When insert node is not the head
            insert->next = pre->next;
            insert->prev = pre;
            pre->next = insert;
            if (insert->next != NULL) {
                insert->next->prev = insert;
            }
        }
        if (insert->next == NULL) {
            newList->tail = insert;
        }
    }

    DestroyLinkedList(*list);

    // replace new list with old list.
    *list = newList;
}


void SortSelection(LinkedList *list) {
    if ((*list == NULL)
        || (*list)->head == NULL
        || (*list)->head->next == NULL) {
        return;
    }

    // New list to store min node
    LinkedList newList = CreateLinkedList();
    while ((*list)->num_elements > 0) {
        LinkedListNode *cur = (*list)->head;
        LinkedListNode *minNode = cur;
        int minValue = strtol(cur->payload, NULL, 10);
        // Find the min node
        while (cur != NULL) {
            if ((strtol(cur->payload, NULL, 10)) < minValue) {
                minValue = strtol(cur->payload, NULL, 10);
                minNode = cur;
            }
            cur = cur->next;
        }
        // Take the min node from old to list

        if (minNode->prev != NULL) {
            minNode->prev->next = minNode->next;
        } else {
            (*list)->head = minNode->next;
        }
        if (minNode->next != NULL) {
            minNode->next->prev = minNode->prev;
        } else {
            (*list)->tail = minNode->prev;
        }

        // Insert minnode into new list
        minNode->next = NULL;
        minNode->prev = newList->tail;
        if (newList->tail != NULL) {
            newList->tail->next = minNode;
        } else {
            newList->head = minNode;
        }
        newList->tail = minNode;
        if (newList->head == NULL) {
            newList->head = minNode;
        }
        (*list)->num_elements--;
        newList->num_elements++;
    }
    DestroyLinkedList(*list);

    *list = newList;
}

//  void PrintList(LinkedListNode* head) {
////    printf("List: ");
//    for (LinkedListNode* current = head;
//         current != NULL;
//         current = current->next) {
//         printf("%s, ", current->payload);
//  }
//    printf("\n");
// }


LinkedListNode *Middle(LinkedListNode *head) {
    if ((head == NULL) || head->next == NULL) {
        return head;
    }

    LinkedListNode *slow = head;
    LinkedListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode *middle = slow;

//    printf("Middle found at: %s\n", slow->payload);
//    printf("Slow found at: %s\n", slow->payload);

//    slow->next = NULL;
    return middle;
}

LinkedListNode *Sort(LinkedListNode *one, LinkedListNode *two) {
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;
//    printf("Merging lists \n");
//    PrintList(one);
//    PrintList(two);

    while (one != NULL && two != NULL) {
        LinkedListNode *newNode =
                (atoi(one->payload) <= atoi(two->payload)) ? one : two;
        if (newNode == one) {
            one = one->next;
        } else {
            two = two->next;
        }
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        newNode->prev = tail;
        tail = newNode;
    }
    LinkedListNode *rest = (one != NULL) ? one : two;
    while (rest != NULL) {
//        LinkedListNode *new = CreateLinkedListNode(rest->payload);
        if (head == NULL) {
            head = rest;
        } else {
            tail->next = rest;
        }
        rest->prev = tail;
        tail = rest;
        rest = rest->next;
    }
    if (tail) {
        tail->next = NULL;
    }

//    printf("Merged list:");
//    PrintList(head);
    return head;
}

//    if (one == NULL) {
//        return two;
//    }
//    if (two == NULL) {
//        return one;
//    }
//
////    LinkedListNode dummy;
////    LinkedListNode *current = &dummy;
////    dummy.next = NULL;
//
//    while(one !=NULL && two !=NULL) {
////        printf("compare\n");
//        int intOneValue = atoi(one->payload);
//        int intTwoValue = atoi(two->payload);
////        printf("%d ",intOneValue);
////        printf("%d;",intTwoValue);
//
//        if (intOneValue <= intTwoValue) {
//            one->next = Sort(one->next, two);
//            one->next->prev = one;
//            one->prev = NULL;
//            return one;
//        } else {
//            two->next = Sort(one, two->next);
//            two->next->prev = two;
//            two->prev = NULL;
//            return two;
//        }
//    }

//            current->next = two;
//            two->prev = current;
//            two = two->next;
//        }
//        current = current->next;
//    }
//    if(one!=NULL){
//        current->next=one;
//        one->prev = current;
//    }else if(two !=NULL){
//        current->next = two;
//        two->prev = current;
//    }
//    dummy.next->prev = NULL;
//    return dummy.next;
//    printf("%d", dummy.next->payload);
// }

LinkedListNode *SplitSortMerge(LinkedListNode *head) {
    if (head == NULL || head->next == NULL) {
//        PrintList(head);
        return head;
    }
    LinkedListNode *middle = Middle(head);
    LinkedListNode *secondList = middle->next;
    middle->next = NULL;

//    printf("Splitting list at %s\n", middle->payload);
//    printf("First half: ");
//    PrintList(head);
//    printf("Second half: ");
//    PrintList(secondList);

    LinkedListNode *one = SplitSortMerge(head);
    LinkedListNode *two = SplitSortMerge(secondList);

    LinkedListNode *sorted = Sort(one, two);
    return sorted;
}


void SortMerge(LinkedList list) {
//    printf("Starting SortMerge...\n");
    if ((list == NULL) || list->head == NULL || list->head->next == NULL) {
        return;
    }
    list->head = SplitSortMerge(list->head);

    LinkedListNode *current = list->head;
    if (current) {
        current->prev = NULL;
        while (current->next) {
            current->next->prev = current;
            current = current->next;
        }
        list->tail = current;
    }
}
//    printf("Final sorted list: \n");
//    PrintList(list->head);







