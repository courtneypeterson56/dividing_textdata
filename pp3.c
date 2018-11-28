#include <stdio.h>
#include <stdlib.h>
#include "pp3.h"

/*
Courtney Peterson
Computer Systems

This program takes in a long, single line of text and reads 80 chars of the line at a time (unless there are less than 80 chars left).
These groups of at most 80 chars are stored in a properly defined struct and then the
divided 80 char chunks are printed out on separate lines.
* The structs (also an unkown number of them) ultimately forms a linked
list of structs holding all the many, many, many characters read in.
*/

char * getCharBlock() {
  //fills in the "string" of chars for the passed in char pointer
  int count = 0;
  char c, * a;
  a = (char *)malloc(sizeof(char));
  c = getchar();
  while (c != '\n') {
    *(a + count) = c;
    count++;
    a = (char *)realloc(a, (count+1));
    c = getchar();
  }
  *(a + count) = '\0';
  return a;
}

node_t * splitChars(node_t * head, char * value) {
    node_t * list;
    char * block;
    int p;
    int q=0;

    while (*(value+q)!= '\0') {
      block = (char *)malloc(81*sizeof(char));
      int p=0;
      while (p < 81) {
        *(block + p) = *(value + q);
        p++;
        q++;
      }
    *(block + p) = '\0';
    list = addNode(block);
    head = insert_rear(head, list);
  }
    return head;
}

node_t * addNode(char * value){
    node_t * p;// declares two nodes temp and p (temp below)
    node_t * temp = (node_t *)malloc(sizeof(node_t)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    temp->string = value; //add element's value to data part of node
    return temp;
}

node_t * insert_rear(node_t * head, node_t * temp) { /*this will always insert at the head of the list*/
  node_t *p;
  if (head == NULL)
    return temp;
  p = head;
  while (p->next != NULL){
    p = p->next;
  }
  p->next = temp;
  return head;
}

void display(node_t * head) {
    while (head) {
      printf("Chunk: %s \n", head->string);
      head = head->next;
    }
}
