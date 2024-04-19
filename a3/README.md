Weiyi Mao

1）doubly.c and deque.c
	I run my doubly.c and deque.c by first getting inside the working directory where these two files are saved. Then I type "make all" in the terminal. deque.c output (which included doubly.c output) would be like below. This file shows how doublinked list and deque works. 

Please beware that my index starts at 1 in a4. For example, I wrote 
    for (int i = 1; i < index - 1; i++) {
      current = current->next;
    }

2)Summary 

I learnt how to use C to implement the definition of doubly linked list and deque. I also learnt how to use valgrind and gdb to debug.

I learnt the memory leak as well as node == null could easily lead to bugs in programming, therefore whenever I print or implement a function, I need to always make sure that node ！= NULL.

What’s challenging is figuring out which node can be free(). I am still learning on this part. 

the first value is 1
The list is: 1


addLeft: 
The list is: 01
addLeft: the size of l1 is 2 

addRight:
The list is: 012

insertAt: 
The list is: 0412

removeAT: 
The list is: 412

hasValue: 
Does n1 includes value of 1: 1

pushLeft 
The list is: 0412

peekLeft_print: 
The value of the node is 0 

popLeft_print: 
The value of the node is 0 

The list is: 412

pushRight: 
The list is: 4123

peekRight_print: 
The value of the node is 3 

popRight_print: 
The value of the node is 3 
The result of the list
The list is: 412