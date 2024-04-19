// #include "node.c"
#include "node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct L_List {
  struct L_Node *head;
  struct L_Node *tail;
  //    L_Node* current;
  int size;
} L_List;

L_List *createList() {
  L_List *list = (L_List *)malloc(sizeof(L_List));
  if (list == NULL) {
      printf("Memory allocation failed.");
      return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  //    list->current
  return list;
}

void addNode(L_List *list, int value) {  // add node after head
  L_Node *addedNode = createNode(value);
  if (list->head == NULL) {
    list->head = addedNode;
    list->tail = addedNode;
    return;
  } else {
    list->tail->next = addedNode;
    addedNode->prev = list->tail;
    list->tail = addedNode;
  }
  list->size++;
  addedNode->value = value;
  //    free(addedNode);
}

void removeAllNodesWithValue(L_List *list, int value) {
  if (list->size == 0) {
    printf("The list is empty");
  }
  L_Node *current = list->head;

  while (current != NULL) {
    if (current->value == value) {
      L_Node *n = current;

      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        list->head = current;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      } else {
        list->tail = current->prev;
      }
      current = current->next;
      list->size--;
      free(n);
    } else {
      current = current->next;
    }
  }
  free(current);
}

void addLeft(L_List *list, int value) {
  L_Node *addedNode = createNode(value);
  if (list->size <= 0) {
    list->head = addedNode;
    list->tail = addedNode;
  } else {
    addedNode->next = list->head;
    list->head->prev = addedNode;
    list->head = addedNode;
  }
  list->size++;
  addedNode->value = value;
}

void addRight(L_List *list, int value) {
  L_Node *addedNode = createNode(value);
  if (list->size <= 0) {
    list->head = addedNode;
    list->tail = addedNode;
    return;
    //        node->value = value;
  } else {
    if (list->tail != NULL) {
      addedNode->prev = list->tail;
      list->tail->next = addedNode;
      list->tail = addedNode;
    } else {
      printf("list->tail is null");
    }
  }
  list->size++;
}

void removeLeft(L_List *list) {
  if (list->head == NULL) {
    printf("The list is empty");
  } else {
    L_Node *current = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(current);
    list->size--;
  }
}

void removeRight(L_List *list) {
  if (list->tail == NULL) {
    printf("The list is empty");
  } else {
    L_Node *current = list->tail;
    list->tail = current->prev;
    list->tail->next = NULL;
    free(current);
    list->size--;
  }
}

void insertAt(L_List *list, int value, int index) {
  L_Node *addedNode = createNode(value);

  if ((index < 0) || (index > list->size)) {
    printf("Index out of list's size range.");
    return;
  }

  if (index == 0) {
    addedNode->next = list->head;
    if (list->head != NULL) {
      list->head->prev = addedNode;
    } else {
      list->tail = addedNode;
    }
    list->head = addedNode;

  } else if (index == list->size) {
    addedNode->prev = list->tail;
    if (list->tail != NULL) {
      list->tail->next = addedNode;
    } else {
      list->head = addedNode;
    }
    list->tail = addedNode;
  } else {
    L_Node *current = list->head;

    for (int i = 1; i < index - 1; i++) {
      current = current->next;
    }
    addedNode->next = current->next;
    current->next = addedNode;
    addedNode->prev = current;
    current->next->prev = addedNode;
  }
  list->size++;
  addedNode->value = value;
}

void removeAt(L_List *list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Index is out of list's size range.");
    return;
  }

  if (index == 1) {
    removeLeft(list);
    return;
  } else if (index == list->size) {
    removeRight(list);
  } else {
    L_Node *current = list->head;
    for (int i = 1; current != NULL && i <= index; i++) {
      current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    list->size--;
  }
  printf("--\n");
}

bool hasValue(L_List *list, int value) {
  L_Node *current = list->head;
  if (list->size <= 0) {
    printf("The list is empty.");
    return false;
  }
  while (current != NULL) {
    if (current->value == value) {
      return true;
    } else {
      current = current->next;
    }
  }
  return false;
  free(current);
}

void pushLeft(L_List *deque, int i) { addLeft(deque, i); }

L_Node *peekLeft(L_List *deque) {
  if (deque->size <= 0 || deque->head == NULL) {
    printf("The list is empty");
    return NULL;
  } else {
    return deque->head;
  }
}

L_Node *popLeft(L_List *deque) {
  if (deque->size <= 0 || deque->head == NULL) {
    printf("The list is empty.");
    return NULL;
  }

  L_Node *leftNodePopped = deque->head;

  deque->head = deque->head->next;
  deque->head->prev = NULL;
  deque->size--;

  return leftNodePopped;
}

void pushRight(L_List *deque, int i) { addRight(deque, i); }

L_Node *peekRight(L_List *deque) {
  if (deque->size <= 0) {
    printf("The list is empty");
    return NULL;
  }
  return deque->tail;
}

L_Node *popRight(L_List *deque) {
  if (deque->size <= 0) {
    printf("The list is empty");
    return NULL;
  }
  //
  L_Node *rightNodePopped = deque->tail;
  deque->tail = deque->tail->prev;
  deque->tail->next = NULL;
  deque->size--;
  return rightNodePopped;
}

void printList(L_List *list) {
  //    L_Node *current = list->head;
  if (list->head == NULL) {
    printf("The list is empty.\n");
    //        return;
  } else {
    L_Node *current = list->head;

    printf("The list is: ");

    while (current != NULL) {
      //            printf(current);
      printf("%d", current->value);
      current = current->next;
    }
  }
  printf("\n");
  //    free(current);
}

void printNode(L_Node *node) {
  if (node == NULL) {
    printf("The node is NULL. \n");
  } else {
    printf("The value of the node is %d \n", node->value);
  }
}

void freeList(L_List *list) {
  if (list == NULL) {
    return;
  }

  L_Node *current = list->head;

  while (current != NULL) {
    L_Node *temp = current;
    current = current->next;
    free(temp);
  }
  free(current);
  free(list);
}

int main() {
  L_Node *n1 = createNode(1);
  printf("the first value is %d\n", n1->value);

  L_List *l1 = createList();

  l1->head = n1;
  l1->tail = n1;
  l1->size = 1;

  printList(l1);

  printf("\n");
  printf("\n");

  addLeft(l1, 0);
  printf("addLeft: \n");
  printList(l1);
  printf("addLeft: the size of l1 is %d \n", l1->size);

  printf("\n");

  addRight(l1, 2);
  printf("addRight:\n");
  printList(l1);

  printf("\n");

  insertAt(l1, 4, 2);  //  List head's index is 1
  printf("insertAt: \n");
  printList(l1);

  printf("\n");

  removeAt(l1, 1);  //  List head's index is 1
  printf("removeAT: \n");
  printList(l1);

  printf("\n");

  int a = 1;

  bool test1 = hasValue(l1, a);
  printf("hasValue: \n");
  printf("Does n1 includes value of 1: %d\n", test1);

  printf("\n");

  pushLeft(l1, 0);
  printf("pushLeft \n");
  printList(l1);

  printf("\n");

  //    peekLeft();
  L_Node *peekLeftNode = peekLeft(l1);
  printf("peekLeft_print: \n");
  printNode(peekLeftNode);

  printf("\n");

  //    popLeft();
  L_Node *popLeftNode = popLeft(l1);

  printf("popLeft_print: \n");
  printNode(popLeftNode);

  printf("\n");
  printList(l1);

  printf("\n");

  //    pushRight()
  pushRight(l1, 3);
  printf("pushRight: \n");
  printList(l1);

  printf("\n");

  //    peekRight()
  L_Node *peekRightNode = peekRight(l1);
  printf("peekRight_print: \n");
  printNode(peekRightNode);

  printf("\n");

  //    popRight()
  L_Node *popRightNode = popRight(l1);
  printf("popRight_print: \n");
  printNode(popRightNode);

  printf("The result of the list\n");
  printList(l1);

  freeList(l1);
  free(n1);
  free(popRightNode);
  free(popLeftNode);

  return 0;
}
//
// Created by Mao on 2/6/24.
//
