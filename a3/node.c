#include "node.h"
#include <stdio.h>
#include <stdlib.h>

L_Node *createNode(int value) {
  L_Node *node = (L_Node *)malloc(sizeof(L_Node));
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
