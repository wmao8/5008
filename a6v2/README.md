* a6  
-Weiyi Mao  
-Google  
-Lost track. Prob more than 7 hours. I did it periodically over Spring break  
-Merge Sort and its debug took me a while  
-I used LinkedList_easy.h as header file 


# **Tests all passed**
  
-e ====================================  
Run tests by running ./test_suite  
-e ====================================  
(base) AppledeMacBook-Air-2:a6 Mao$ ./test_suite  
[==========] Running 13 tests from 3 test cases.  
[----------] Global test environment set-up.  
[----------] 4 tests from SortInsertion  
[ RUN      ] SortInsertion.sortEmptyList  
[       OK ] SortInsertion.sortEmptyList (0 ms)  
[ RUN      ] SortInsertion.oneElement  
[       OK ] SortInsertion.oneElement (0 ms)  
[ RUN      ] SortInsertion.twoElement_notSorted  
[       OK ] SortInsertion.twoElement_notSorted (0 ms)  
[ RUN      ] SortInsertion.sortRandomList  
[       OK ] SortInsertion.sortRandomList (0 ms)  
[----------] 4 tests from SortInsertion (0 ms total)  

[----------] 4 tests from SortSelection  
[ RUN      ] SortSelection.emptyList  
[       OK ] SortSelection.emptyList (0 ms)  
[ RUN      ] SortSelection.oneElement  
[       OK ] SortSelection.oneElement (0 ms)  
[ RUN      ] SortSelection.twoElement  
[       OK ] SortSelection.twoElement (0 ms)  
[ RUN      ] SortSelection.SortRandomList  
[       OK ] SortSelection.SortRandomList (0 ms)  
[----------] 4 tests from SortSelection (0 ms total)  

[----------] 5 tests from SortMerge  
[ RUN      ] SortMerge.emptyList  
[       OK ] SortMerge.emptyList (0 ms)  
[ RUN      ] SortMerge.oneElement  
[       OK ] SortMerge.oneElement (0 ms)  
[ RUN      ] SortMerge.twoElement  
[       OK ] SortMerge.twoElement (0 ms)  
[ RUN      ] SortMerge.SortRandomList_Even  
[       OK ] SortMerge.SortRandomList_Even (0 ms)  
[ RUN      ] SortMerge.SortRandomList_Odd  
[       OK ] SortMerge.SortRandomList_Odd (0 ms)  
[----------] 5 tests from SortMerge (1 ms total)  

[----------] Global test environment tear-down  
[==========] 13 tests from 3 test cases ran. (1 ms total)  
**[  PASSED  ] 13 tests.**  


# **Valgrind no error no leak**  
  
==11530== HEAP SUMMARY:  
==11530==     in use at exit: 0 bytes in 0 blocks  
==11530==   total heap usage: 389 allocs, 389 frees, 121,717 bytes allocated  
==11530== 
==11530== All heap blocks were freed -- no leaks are possible  
==11530== 
==11530== For lists of detected and suppressed errors, rerun with: -s  
==11530== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)  


# **Clint**

-(base) AppledeMacBook-Air-2:a6 Mao$ python2 clint.py linkedlist.c  
Done processing linkedlist.c  
Total errors found: 0  
 
-(base) AppledeMacBook-Air-2:a6 Mao$ python2 clint.py Sort.c  
Done processing Sort.c  
Total errors found: 0 
 
-(base) AppledeMacBook-Air-2:a6 Mao$ python2 clint.py Main.c   
Main.c:12:  Consider using rand_r(...) instead of rand(...) for improved thread safety.  [runtime/ threadsafe_fn] [2]   
Done processing Main.c   
Total errors found: 1 **(Instructor requirement)**   

-(base) AppledeMacBook-Air-2:a6 Mao$ python2 clint.py test_linkedlist.cc  
Done processing test_linkedlist.cc  
Total errors found: 0  

