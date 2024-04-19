## 1 How to run

## 1) I run my LinkedinList.c by first getting inside the working directory where files are saved. Then I type "make all" in the terminal. Then I type "make test". Then I type "./test_suite".

## 2) I learnt how to sort LinkedList in C and what is an iterator. Writing this assignment helps me become more familiar with wiring things in C and LinkedList.  


## 2 Test results 
(base) AppledeMacBook-Air-2:a4and5 Mao$ ./test_suite
[==========] Running 16 tests from 9 test cases.
[----------] Global test environment set-up.
[----------] 1 test from contains
[ RUN      ] contains.givenEmptyListThenReturnsFalse
[       OK ] contains.givenEmptyListThenReturnsFalse (0 ms)
[----------] 1 test from contains (0 ms total)

[----------] 2 tests from CreateLinkedList
[ RUN      ] CreateLinkedList.givenNoInputWhenCreatingListThenSizeIsZero
[       OK ] CreateLinkedList.givenNoInputWhenCreatingListThenSizeIsZero (0 ms)
[ RUN      ] CreateLinkedList.givenNoInputWhenCreatingListThenHeadAndTailAreNull
[       OK ] CreateLinkedList.givenNoInputWhenCreatingListThenHeadAndTailAreNull (0 ms)
[----------] 2 tests from CreateLinkedList (0 ms total)

[----------] 2 tests from InsertLinkedList
[ RUN      ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringIsInList
[       OK ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringIsInList (0 ms)
[ RUN      ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringHead
[       OK ] InsertLinkedList.givenNonNullStringWhenInsertedThenStringHead (0 ms)
[----------] 2 tests from InsertLinkedList (0 ms total)

[----------] 1 test from RemoveLLElem
[ RUN      ] RemoveLLElem.givenNonNullStringWhenRemovedThenStringIsNotInList
[       OK ] RemoveLLElem.givenNonNullStringWhenRemovedThenStringIsNotInList (0 ms)
[----------] 1 test from RemoveLLElem (0 ms total)

[----------] 1 test from EmptyListHasNullHeadAndTell
[ RUN      ] EmptyListHasNullHeadAndTell.givenEmptyListWhenInsertAndRemoveThenHeadAndTailAreNull
[       OK ] EmptyListHasNullHeadAndTell.givenEmptyListWhenInsertAndRemoveThenHeadAndTailAreNull (0 ms)
[----------] 1 test from EmptyListHasNullHeadAndTell (0 ms total)

[----------] 3 tests from NumElementsInLinkedList
[ RUN      ] NumElementsInLinkedList.givenEmptyListThenNumElementsIsZero
[       OK ] NumElementsInLinkedList.givenEmptyListThenNumElementsIsZero (0 ms)
[ RUN      ] NumElementsInLinkedList.givenListWithSingleNodeThenNumElementsIsOne
[       OK ] NumElementsInLinkedList.givenListWithSingleNodeThenNumElementsIsOne (0 ms)
[ RUN      ] NumElementsInLinkedList.givenListWith_N_NodeThenNumElementsIsN
[       OK ] NumElementsInLinkedList.givenListWith_N_NodeThenNumElementsIsN (0 ms)
[----------] 3 tests from NumElementsInLinkedList (0 ms total)

[----------] 3 tests from PopLinkedList
[ RUN      ] PopLinkedList.givenEmptyListWhenPoppedThenReturnsTheInputDataPtr
List or List-> head of dataPtr is NULL[       OK ] PopLinkedList.givenEmptyListWhenPoppedThenReturnsTheInputDataPtr (0 ms)
[ RUN      ] PopLinkedList.givenNonEmptyListWhenPoppedThenDoesNotReturnTheInputDataPtr
[       OK ] PopLinkedList.givenNonEmptyListWhenPoppedThenDoesNotReturnTheInputDataPtr (0 ms)
[ RUN      ] PopLinkedList.givenListWithMultipleItemsWhenPoppedThenDoesNotReturnTheInputDataPtr
[       OK ] PopLinkedList.givenListWithMultipleItemsWhenPoppedThenDoesNotReturnTheInputDataPtr (0 ms)
[----------] 3 tests from PopLinkedList (0 ms total)

[----------] 1 test from TestIterator
[ RUN      ] TestIterator.givenValidListTestIteratorOnEmptyList
iter->cur_node is NULL [       OK ] TestIterator.givenValidListTestIteratorOnEmptyList (0 ms)
[----------] 1 test from TestIterator (0 ms total)

[----------] 2 tests from Test_Iterator
[ RUN      ] Test_Iterator.givenValidListTestIteratorOnListWithSingleValue
[       OK ] Test_Iterator.givenValidListTestIteratorOnListWithSingleValue (0 ms)
[ RUN      ] Test_Iterator.givenValidListTestIteratorOnListWithMultipleValues
[       OK ] Test_Iterator.givenValidListTestIteratorOnListWithMultipleValues (0 ms)
[----------] 2 tests from Test_Iterator (0 ms total)

[----------] Global test environment tear-down
[==========] 16 tests from 9 test cases ran. (1 ms total)
[  PASSED  ] 16 tests.

## 3 Heap Summary

==8824== 
==8824== HEAP SUMMARY:
==8824==     in use at exit: 0 bytes in 0 blocks
==8824==   total heap usage: 536 allocs, 536 frees, 137,637 bytes allocated
==8824== 
==8824== All heap blocks were freed -- no leaks are possible
==8824== 
==8824== For lists of detected and suppressed errors, rerun with: -s
==8824== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
~/.../a4v2/a4_$ 

## 4 Clint 

Done processing /home/wmao8/CS5008/CS5008/a4/LinkedList.c
Total errors found: 0
bash-4.4$ 
