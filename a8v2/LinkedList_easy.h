#ifndef LINKEDLIST_EASY_H
#define LINKEDLIST_EASY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Node {
    char *key;
    char **values;
    int size;
    int capacity;
    struct Node *next;
} Node;

Node *createNode(const char *key, const char *value);
void insertNode(Node **head, const char *key, const char *value);
void freeList(Node *head);
void printList(Node *head);

#ifdef __cplusplus
}
#endif


#endif  // LINKEDLIST_EASY_H

