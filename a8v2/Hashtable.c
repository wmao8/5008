#include "Hashtable_easy.h"
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char *str) {
    uint64_t hash = 2166136261u;
    for (const char *p = str; *p; p++) {
        hash ^= (unsigned int) (*p);
        hash *= 16777619;
    }
    return hash % TABLE_SIZE;
}

// Create a new hashtable
Hashtable *createHashtable() {
    Hashtable *ht = (Hashtable *) malloc(sizeof(Hashtable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert a key-value pair into the hashtable
void insertHashtable(Hashtable *ht, const char *key, const char *value) {
    unsigned int index = hash(key);
    insertNode(&(ht->table[index]), key, value);
}

// Find a node in the hashtable by key
Node *findInHashtable(Hashtable *ht, const char *key) {
    unsigned int index = hash(key);
    Node *head = ht->table[index];
    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


void freeHashtable(Hashtable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            freeList(ht->table[i]);
        }
    }
    free(ht);
}


void printHashtable(Hashtable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printList(ht->table[i]);
        }
    }
}


int charCompare(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}
// Sort characters in a string
char *sortWord(const char *str) {
    // Duplicate the string to keep the original unchanged
    char *sortedStr = strdup(str);
    qsort(sortedStr, strlen(sortedStr), sizeof(*sortedStr), charCompare);
    return sortedStr;
}

