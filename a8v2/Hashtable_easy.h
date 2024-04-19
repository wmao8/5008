#ifndef HASHTABLE_EASY_H
#define HASHTABLE_EASY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "LinkedList_easy.h"


#define TABLE_SIZE 1000


typedef struct Hashtable {
    Node *table[TABLE_SIZE];  // Array of pointers to Node (linked list heads)
} Hashtable;

Hashtable* createHashtable();
unsigned int hash(const char *str);
void insertHashtable(Hashtable *ht, const char *key, const char *value);
Node* findInHashtable(Hashtable *ht, const char *key);
void freeHashtable(Hashtable *ht);
void printHashtable(Hashtable *ht);

int charCompare(const void *a, const void *b);
char* sortWord(const char* str);


#ifdef __cplusplus
}
#endif

#endif  // HASHTABLE_EASY_H
