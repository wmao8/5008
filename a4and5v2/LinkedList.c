#include "LinkedList_easy.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

LinkedListNode *CreateLinkedListNode(char *data) {
    LinkedListNode *newnode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    if (newnode == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    newnode->payload = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

int DestroyLinkedListNode(LinkedListNode *node) {
    if (node == NULL) {
        printf("Node is NULL");
        return -1;
    }
//    free(node->payload);
    free(node);
    return 0;
}

int RemoveLLElem(LinkedList list, LinkedListNodePtr ptr) {
    if (list == NULL || ptr == NULL || list->head == NULL) {
        printf("The list or the ptr or list's head is NULL");
        return 1;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    } else {
        list->head = ptr->next;
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    } else {
        list->tail = ptr->prev;
    }
    DestroyLinkedListNode(ptr);
    list->num_elements--;
    return 0;
}

LinkedList CreateLinkedList() {
    LinkedList list = (LinkedList) malloc(sizeof(LinkedListHead));
    if (list == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    list->num_elements = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int DestroyLinkedList(LinkedList list) {
    if (list == NULL) {
        printf("The list is null");
        return 1;
    }
    LinkedListNode *current = list->head;
    while (current != NULL) {
        LinkedListNode *next = current->next;
        DestroyLinkedListNode(current);
        current = next;
    }
    // DestroyLinkedListNode(current);
    free(list);
    return 0;
}

unsigned int NumElementsInLinkedList(LinkedList list) {
    if (list == NULL) {
        printf("The list is NULL");
        return 0;
    }
    return list->num_elements;
}

int InsertLinkedList(LinkedList list, char *data) {
    if (list == NULL) {
        printf("List is NULL");
        return 1;
    }
    LinkedListNode *node = CreateLinkedListNode(data);
    if (node == NULL) {
        return 1;
    }
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->num_elements++;
    return 0;
}

int PopLinkedList(LinkedList list, char **dataPtr) {
    if (list == NULL || list->head == NULL || dataPtr == NULL) {
        printf("List or List-> head of dataPtr is NULL");
        return -1;
    }

    *dataPtr = list->head->payload;
    LinkedListNode *current = list->head;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
//        LinkedListNode *current = list->head;
//        list->head->next = NULL;
//        list->head->next->prev = NULL;
        list->head = current->next;
//         list->head = list->head->next;
        list->head->prev = NULL;
    }
    current->payload = NULL;
    DestroyLinkedListNode(current);
    list->num_elements--;
    return 0;
}


void SortLinkedList(LinkedList list, unsigned int ascending) {
    if (list == NULL) {
        printf("List is NULL");
        return;
    }
    if (list->head == NULL) {
        printf("List->head is NULL");
        return;
    }

    if (list->tail == NULL) {
        printf("List->tail is NULL");
        return;
    }

    int check;

    LinkedListNode *current = list->head;
    LinkedListNode *lastNode = NULL;

    do {
        check = 0;

        while (current->next != lastNode) {
            if (ascending == 1) {
                if (strcmp(current->payload, current->next->payload) > 0) {
                    check = 1;
                    char *tem = current->payload;
                    current->payload = current->next->payload;
                    current->next->payload = tem;
                }
            } else {  // ascending is false aka 0
                if (strcmp(current->payload, current->next->payload) < 0) {
                    check = 1;
                    char *tem = current->payload;
                    current->payload = current->next->payload;
                    current->next->payload = tem;
                }
            }
            current = current->next;
        }
        lastNode = current;
    } while (check);
}

LLIter CreateLLIter(LinkedList list) {
    LLIter iter = (LLIter) malloc(sizeof(LLIterSt));
    if (iter == NULL) {
        printf("Memory allocation not succeed");
        return NULL;
    }
    iter->list = list;
    iter->cur_node = list->head;
    return iter;
}

int LLIterHasNext(LLIter iter) {
    if (iter == NULL) {
        printf("Iterator is NULL");
        return 0;
    }
    if (iter->cur_node == NULL) {
        printf("iter->cur_node is NULL ");
        return 0;
    }
    return iter->cur_node->next != NULL;
}

int LLIterHasPrev(LLIter iter) {
    if (iter == NULL) {
        printf("Iterator is NULL");
        return 0;
    }
    if (iter->cur_node == NULL) {
        return 0;
    }
    return iter->cur_node->prev != NULL;
}

int LLIterNext(LLIter iter) {
    if (iter == NULL) {
        printf("iter is NULL");
        return 0;
    }
    if (iter->cur_node == NULL) {
        printf("List head aka current node is NULL");
        return 0;
    }
    if (iter->cur_node->next == NULL) {
        printf("There is no next node after current node");
        return 0;
    }
    iter->cur_node = iter->cur_node->next;
    return 1;
}

int LLIterPrev(LLIter iter) {
    if (iter == NULL) {
        printf("iter is NULL");
        return 0;
    }
    if (iter->cur_node == NULL) {
        printf("Current node is NULL");
        return 0;
    }
    if (iter->cur_node->prev == NULL) {
        printf("No prev node");
        return 0;
    }
    iter->cur_node = iter->cur_node->prev;
    return 1;
}

int DestroyLLIter(LLIter iter) {
    if (iter == NULL) {
        printf("iter is NULL");
        return 1;
    }
    free(iter);
    return 0;
}

int LLIterGetPayload(LLIter iter, char **payload) {
    if (iter == NULL) {
        printf("iter is NULL");
        return 1;
    }
    if (iter->cur_node == NULL) {
        printf("current node is NULL ");
        return 1;
    }
    *payload = iter->cur_node->payload;
    return 0;
}

int LLIterDelete(LLIter iter) {
    if (iter == NULL) {
        printf("iter is NULL");
        return 0;
    }
    if (iter->cur_node == NULL) {
        printf("Current node is NULL");
        return 0;
    }
    LinkedListNode *current = iter->cur_node;
    LinkedListNode *current_prev = iter->cur_node->prev;
    LinkedListNode *current_next = iter->cur_node->next;

    if ((current_prev) != NULL) {
        current_prev->next = current_next;
    } else {
        iter->list->head = current_next;
    }

    if (current_next != NULL) {
        current_next->prev = current_prev;
    } else {
        iter->list->tail = current_next;
    }

    // Free payload
    if (current->payload != NULL) {
        free(iter->cur_node);
    }
    // free(current);

    // Update iter's current node
    if (current_next != NULL) {
        iter->cur_node = current_next;
    } else {
        iter->cur_node = current_prev;
    }
    iter->list->num_elements--;
    return 1;
}


int LLIterInsertBefore(LLIter iter, char *payload) {
    if (iter == NULL || iter->cur_node == NULL) {
        printf("iter is NULL");
        return 1;
    }

    LinkedListNode *insert = CreateLinkedListNode(payload);
    if (iter->cur_node->prev != NULL) {
        iter->cur_node->prev->next = insert;
//        iter->cur_node->prev=insert;
    } else {
//        iter->cur_node->prev=insert;
//        insert->next=iter->cur_node;
        iter->list->head = insert;
    }
    iter->list->num_elements--;
    return 0;
}

//int main() {
//    printf("hi\n");
//    return -1;
//}
