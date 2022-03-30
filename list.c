// list/list.c
// 
// Implementation for linked list.
//
// <Author>Darryle Mensah

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* list = malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_free(list_t *l) {
  while(l->head != NULL){
    node_t * temp = l->head;
    l->head = l->head->next;
    free(temp);
  }
}

void node_free(node_t *n){
  free(n);
}

void list_print(list_t *l) {
  node_t *cur = l->head;
  
  while(cur != NULL){
    printf("%d ", cur->value);
    cur = cur->next;
  }
}


int list_length(list_t *l) { 
  node_t *cur = l->head;
  int count = 0;
  while(cur != NULL){
    count++;
    cur = cur->next;
  }
  return count; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t *cur = l->head;
  if (l->head == NULL){
    node_t *new_head = malloc(sizeof(node_t));
    new_head->value = value;
    l->head = new_head;
  }
  else{
    while (l->head->next != NULL){
      l->head = l->head->next;
    }
    node_t* hold = malloc(sizeof(node_t));
    hold->value = value;
    l->head->next = hold;
  }
  l->head = cur;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_head = malloc(sizeof(node_t));
  new_head->value = value;
  new_head->next = l->head;
  l->head = new_head;
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t *cur = l->head;
  if(index == 0){
    list_add_to_front(l,value);
  }
  else if(index == list_length(l)-1){
    list_add_to_back(l,value);
  }
  else if(index < list_length(l)){
    while(index != 1){
      index--;
      l->head = l->head->next;
    }
    node_t* hold = malloc(sizeof(node_t));
    hold->value = value;
    hold->next = l->head->next;
    l->head->next = hold;
    l->head = cur;
  }
 }

elem list_remove_from_back(list_t *l) { 
  node_t *cur = l->head;
  if(list_length(l) == 0){
    list_remove_from_back(l);
  }
  
  
  while(l->head->next->next != NULL){
    l->head = l->head->next;
  }
  
  free(l->head->next);
  l->head->next = NULL;
  l->head = cur;
  return 1;
}

elem list_remove_from_front(list_t *l) { 
  node_t *front = l->head;
  l->head = l->head->next;
  free(front);
  return l->head->value;
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *cur = l->head;
  node_t *hold;
  
  while(index != 1){
    index--;
    l->head = l->head->next;
  }
  
  hold = l->head->next;
  l->head->next = l->head->next->next;
  l->head = cur;
  free(hold);
  return -1;
}

bool list_is_in(list_t *l, elem value) {
  node_t *cur = l->head;
  while(cur != NULL){
    if(cur->value == value){
      return true;
    }
    cur = cur->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) { 
  node_t *cur = l->head;
  int l_ind = 0;
  while (cur != NULL){
    if(l_ind == index){
      return cur->value;
    }
    l_ind++;
    cur = cur->next;
  }
  return -1;
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *cur = l->head;
  int index = 0;
  while(cur != NULL){
    if(cur->value == value){
      return index;
    }
    index++;
    cur = cur->next;
  }
  return -1;
}

