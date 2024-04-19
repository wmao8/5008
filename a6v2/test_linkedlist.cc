// *  This is free software: you can redistribute it and/or modify
// *  it under the terms of the GNU General Public License as published by
// *  the Free Software Foundation, either version 3 of the License, or
// *  (at your option) any later version.
// *
// *  It is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// *  GNU General Public License for more details.
// *
// *  See <http://www.gnu.org/licenses/>.
#include "gtest/gtest.h"

extern "C" {
#include "LinkedList_easy.h"
#include "Sort.c"
#include "Sort.h"
#include <stdbool.h>
#include <string.h>
}
const char *first = "first";
const char *second = "second";
const char *third = "third";
const char *fourth = "fourth";

bool contains(LinkedList list, char *str) {
  LinkedListNodePtr node = list->head;
  bool res = false;
  while (node != NULL) {
    res = res || strcmp(node->payload, str) == 0;
    node = node->next;
  }
  return res;
}

#define MAX_VALUE_LEN 75

TEST(SortInsertion, sortEmptyList) {
  LinkedList list = CreateLinkedList();
  SortInsertion(&list);
  EXPECT_EQ(list->head, nullptr);
  DestroyLinkedList(list);
}

TEST(SortInsertion, oneElement) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("1"));
  SortInsertion(&list);
  EXPECT_STREQ(list->head->payload, "1");
  DestroyLinkedList(list);
}

TEST(SortInsertion, twoElement_notSorted) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("3"));
  InsertLinkedList(list, strdup("2"));
  SortInsertion(&list);
  LinkedListNode *current = list->head;
  ASSERT_STREQ(current->payload, "2");
  current = current->next;
  ASSERT_STREQ(current->payload, "3");
  DestroyLinkedList(list);
}

TEST(SortInsertion, sortRandomList) {
  // Generate Random List
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("8"));
  InsertLinkedList(list, strdup("5"));
  InsertLinkedList(list, strdup("7"));
  InsertLinkedList(list, strdup("9"));
  InsertLinkedList(list, strdup("2"));
  InsertLinkedList(list, strdup("2"));
  // List should be sorted in ascending order
  SortInsertion(&list);
  LinkedListNode *cur = list->head;
  ASSERT_STREQ(cur->payload, "2");
  cur = cur->next;
  ASSERT_STREQ(cur->payload, "2");
  cur = cur->next;
  ASSERT_STREQ(cur->payload, "5");
  cur = cur->next;
  ASSERT_STREQ(cur->payload, "7");
  cur = cur->next;
  ASSERT_STREQ(cur->payload, "8");
  cur = cur->next;
  ASSERT_STREQ(cur->payload, "9");
  cur = cur->next;
  // Destroy
  DestroyLinkedList(list);
}

TEST(SortSelection, emptyList) {
  LinkedList list = CreateLinkedList();
  SortSelection(&list);
  EXPECT_EQ(list->head, nullptr);
  DestroyLinkedList(list);
}

TEST(SortSelection, oneElement) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("8"));
  SortSelection(&list);
  EXPECT_STREQ(list->head->payload, "8");
  DestroyLinkedList(list);
}

TEST(SortSelection, twoElement) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("88"));
  SortSelection(&list);
  EXPECT_STREQ(list->head->payload, "88");
  EXPECT_STREQ(list->head->next->payload, "99");
  DestroyLinkedList(list);
}

TEST(SortSelection, SortRandomList) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("78"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("65"));
  InsertLinkedList(list, strdup("34"));
  SortSelection(&list);
  LinkedListNode *current = list->head;
  EXPECT_STREQ(current->payload, "34");
  current = current->next;
  EXPECT_STREQ(current->payload, "65");
  current = current->next;
  EXPECT_STREQ(current->payload, "78");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "99");
  DestroyLinkedList(list);
}

TEST(SortMerge, emptyList) {
  LinkedList list = CreateLinkedList();
  SortMerge(list);
  EXPECT_EQ(list->head, nullptr);
  DestroyLinkedList(list);
}

TEST(SortMerge, oneElement) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("8"));
  SortMerge(list);
  EXPECT_STREQ(list->head->payload, "8");
  DestroyLinkedList(list);
}

TEST(SortMerge, twoElement) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("88"));
  SortMerge(list);
  EXPECT_STREQ(list->head->payload, "88");
  EXPECT_STREQ(list->head->next->payload, "99");
  DestroyLinkedList(list);
}

TEST(SortMerge, SortRandomList_Even) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("78"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("65"));
  InsertLinkedList(list, strdup("34"));
  SortMerge(list);
  LinkedListNode *current = list->head;
  EXPECT_STREQ(current->payload, "34");
  current = current->next;
  EXPECT_STREQ(current->payload, "65");
  current = current->next;
  EXPECT_STREQ(current->payload, "78");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "99");
  DestroyLinkedList(list);
}

TEST(SortMerge, SortRandomList_Odd) {
  LinkedList list = CreateLinkedList();
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("99"));
  InsertLinkedList(list, strdup("78"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("89"));
  InsertLinkedList(list, strdup("65"));
  InsertLinkedList(list, strdup("34"));
  SortMerge(list);
  LinkedListNode *current = list->head;
  EXPECT_STREQ(current->payload, "34");
  current = current->next;
  EXPECT_STREQ(current->payload, "65");
  current = current->next;
  EXPECT_STREQ(current->payload, "78");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "89");
  current = current->next;
  EXPECT_STREQ(current->payload, "99");
  current = current->next;
  EXPECT_STREQ(current->payload, "99");
  DestroyLinkedList(list);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
