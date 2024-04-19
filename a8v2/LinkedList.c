#include "LinkedList_easy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node *createNode(const char *key, const char *value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) return NULL;

    newNode->key = strdup(key);
    newNode->capacity = 2;  // Starting capacity
    newNode->size = 1;
    newNode->values = (char **) malloc(sizeof(char *) * newNode->capacity);
    newNode->values[0] = strdup(value);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a word into the linked list
void insertNode(Node **head, const char *key, const char *value) {
    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && strcmp(current->key, key) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Create a new node if key not found
        Node *newNode = createNode(key, value);
        if (previous == NULL) {
            *head = newNode;
        } else {
            previous->next = newNode;
        }
    } else {
        // Add value to existing node
        if (current->size >= current->capacity) {
            // Resize the values array if needed
            current->capacity *= 2;
            current->values = (char **) realloc(
                    current->values,
                    sizeof(*(current->values)) * current->capacity);
        }
        current->values[current->size++] = strdup(value);
    }
}


void freeList(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        for (int i = 0; i < tmp->size; i++) {
            free(tmp->values[i]);
        }
        free(tmp->values);
        free(tmp->key);
        free(tmp);
    }
}


void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s: ", current->key);
        for (int i = 0; i < current->size; i++) {
            printf("%s ", current->values[i]);
        }
        printf("\n");
        current = current->next;
    }
}
