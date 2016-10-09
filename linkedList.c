#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list(struct node * np){
  printf("%d", np->i);
  np = np->next;
  while (np){ //node not null
    printf(", ");
    printf("%d", np->i);
    np = np->next;
  }
  printf("\n");
}

struct node *insert_front(struct node * listP, int data){
  //create new node
  struct node * addIn = (struct node *) malloc(sizeof(struct node));
  addIn->i = data;
  addIn->next = listP;

  //return pointer to front of list
  return addIn;
} 

struct node *free_list(struct node * listP){
  struct node * retP = listP;
  while (listP){
    struct node * next = listP->next;
    free(listP);
    listP = next;
  }
  return retP;
}

int main(){
  
  struct node * n = (struct node *) malloc(sizeof(struct node));
  n->i = 1;
  n->next = NULL;

  struct node * myList;

  printf("\n");
  printf("Adding elements to the list:\n");
  myList = insert_front(n, 10);
  print_list(myList);
  myList = insert_front(myList, 55);
  print_list(myList);
  myList = insert_front(myList, 7);
  print_list(myList);
  myList = insert_front(myList, 817);
  print_list(myList);

  printf("\n");
  printf("Freeing list:\n");
  free_list(myList);
  print_list(myList);
  return 0;
}
