# a8#  
# Weiyi Mao#  
- more than 8 hours?
- No
- Google

# What went well and tricky 
- gtest and makefile
- created new starter code for a8

# **How to build and run** 
## To use gtest
 - In terminal, enter 
    - make all
    - make test
    - ./test_suite
## To use main
- uncomment 
    -  //  #include "Hashtable.c"
    - //  #include "LinkedList.c" 
- click run


# **Valgrind no error no leak**    

==6268== HEAP SUMMARY:  
==6268==     in use at exit: 0 bytes in 0 blocks  
==6268==   total heap usage: 182 allocs, 182 frees, 121,844 bytes allocated  
==6268==   
==6268== All heap blocks were freed -- no leaks are possible  
==6268==   
==6268== For lists of detected and suppressed errors, rerun with: -s  
==6268== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)   


# **Clint**  
(base) AppledeMacBook-Air-2:a8v2 Mao$ python2 clint.py Hashtable_easy.h   LinkedList_easy.h test_hashtable.cc  
Done processing Hashtable_easy.h  
Done processing LinkedList_easy.h  
Done processing test_hashtable.cc  
Total errors found: 0  

(base) AppledeMacBook-Air-2:a8v2 Mao$ python2 clint.py Hashtable.c LinkedList.c main.c  
Done processing Hashtable.c  
Done processing LinkedList.c  
Done processing main.c  
Total errors found: 0  
(base) AppledeMacBook-Air-2:a8v2 Mao$  



