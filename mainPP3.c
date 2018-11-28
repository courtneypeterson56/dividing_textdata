#include <stdio.h>
#include <stdlib.h>
#include "pp3.h"

int main() {
  node_t * list;
  node_t * head = NULL;
  char * text;

  printf("Please input a HUGE line: \n" );
  text = getCharBlock();
  printf("\n");
  head = splitChars(head, text);
  display(head);
  printf("\n All done! \n" );
  return 0;
}
