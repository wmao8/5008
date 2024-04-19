#include "Hashtable_easy.h"
#include "LinkedList_easy.h"
#include <gtest/gtest.h>
#include <string>


void insertWords(Hashtable *ht, const char *words[], size_t count) {
    for (size_t i = 0; i < count; ++i) {
        char *sortedWord = sortWord(words[i]);
        insertHashtable(ht, sortedWord, words[i]);
        free(sortedWord);
    }
}

// Test to verify that anagrams are correct
TEST(AnagramTest, CorrectGrouping) {
    Hashtable *ht = createHashtable();
    const char *words[] = {"listen", "silent", "islent"};
    insertWords(ht, words, 3);  // Update to use array and count

    Node *node = findInHashtable(ht, "eilnst");  // Assuming sorted "abc" as key
    ASSERT_TRUE(node != nullptr);
    EXPECT_EQ(node->size, 3);

    freeHashtable(ht);
}


TEST(AnagramTest, IncorrectGrouping) {
    Hashtable *ht = createHashtable();
    const char *words[] = {"abc", "xyz"};
    insertWords(ht, words, 2);

    Node *nodeAbc = findInHashtable(ht, "abc");
    Node *nodeXyz = findInHashtable(ht, "xyz");
    ASSERT_TRUE(nodeAbc != nullptr);
    ASSERT_TRUE(nodeXyz != nullptr);
    EXPECT_EQ(nodeAbc->size, 1);
    EXPECT_EQ(nodeXyz->size, 1);

    freeHashtable(ht);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//
// Created by Mao on 4/10/24.
//
//
// Created by Mao on 4/10/24.
//
