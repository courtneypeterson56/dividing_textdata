#ifndef _pp3_H
#define _pp3_H
#include <stdio.h>
#include <stdlib.h>
#include "pp3.h"

typedef struct node{ // Node structure
  char * string;
  struct node * next;
} node_t;


char * getCharBlock();
node_t * splitChars(node_t * head, char * value);
node_t * insert_rear(node_t * head, node_t * temp);
node_t * addNode(char * value);
void display(node_t * head);

#endif //_PP3_H
