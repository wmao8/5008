#include "Hashtable_easy.h"
#include "LinkedList_easy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  #include "Hashtable.c"
//  #include "LinkedList.c"

#define MAX 100


int main() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    Hashtable *ht = createHashtable();
    char word[MAX];

    // Read each word from the file and process
    while (fscanf(file, "%s", word) == 1) {
        char *sortedWord = sortWord(word);    // Sort the characters in the word
        insertHashtable(ht, sortedWord, word);  // Insert into hashtable
        free(sortedWord);  //  Free the sorted word now that it's been used
    }

    fclose(file);

    printf("***************************************"
           "Printing the entire hashtable"
           "***********************************\n");

    // Print the anagrams from the hashtable
    printHashtable(ht);

    // Print all anagrams found
    printf("\n");
    printf("*************************************"
           "End of entire hashtable"
           "************************************************\n");

    printf("+++++++++++++++++++++++++++++++++++++++"
           "Anagrams found:"
           "++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *node = ht->table[i];
        while (node != NULL) {
            if (node->size > 1) {  // print lists that has more than one anagram
                for (int j = 0; j < node->size; j++) {
                    printf("%s ", node->values[j]);
                }
                printf("\n");
            }
            node = node->next;
        }
    }

    freeHashtable(ht);
    return EXIT_SUCCESS;
}
