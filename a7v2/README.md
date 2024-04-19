# a7#  


# **Command Name**  
- cd  
- help  
- exit  
- gameCommand  
  
# **Synopsis** 
- cd: change directory  
- help: print out the description of all commands in in this shell  
- exit: exit
- gameCommand: print out “This is gameComand”  

# **Description** 
- cd: change directory  
	cd ~: change path back to home directory  
	cd _folder_: enter the folder   
- help: print out the description and manual of all commands in in this shell  
- exit: exit the shell  
- gameCommand: print out “This is gameComand”  

# **Notes**  
I enter gameCommand after prompt  
I enter cd ~ or cd _folder_  
I enter help after prompt  
I enter exit after prompt  



# **Valgrind no error no leak**  

==8519== HEAP SUMMARY:  
==8519==     in use at exit: 0 bytes in 0 blocks  
==8519==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated  
==8519==  
==8519== All heap blocks were freed -- no leaks are possible  
==8519==  
==8519== For lists of detected and suppressed errors, rerun with: -s  
==8519== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)  


# **Clint**  
(base) AppledeMacBook-Air-2:a7 Mao$ python2 clint.py shell.c  
Done processing shell.c  
Total errors found: 0  

