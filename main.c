#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  printf("Hello there\n");
  list_t* linked_list = list_alloc();
  
  list_print(linked_list);
  
  list_add_to_front(linked_list,8);
  list_add_to_front(linked_list,14);
  list_add_to_front(linked_list,49);
  list_print(linked_list);
  printf("\n");
  
 // printf("Hello\n");
  
  list_add_to_back(linked_list, 23);
  list_add_to_back(linked_list, 91);
  list_add_to_back(linked_list, 55);
  list_print(linked_list);
  printf("\n");
  
  list_add_at_index(linked_list, 67, 2);
  list_print(linked_list);
  printf("\n");
  list_add_at_index(linked_list, 2, 5);
  list_print(linked_list);
  printf("\n");
  list_add_at_index(linked_list, 4, 4);
  list_print(linked_list);
  printf("\n");
  
  printf("The Element at Index 2 is %d\n", list_get_elem_at(linked_list, 2));
  printf("The Element at Index 4 is %d\n", list_get_elem_at(linked_list, 4));
  printf("The Element at Index 10 is %d\n", list_get_elem_at(linked_list, 10));
  
  printf("The Element 49 is at Index %d\n", list_get_index_of(linked_list, 49));
  printf("The Element 23 is at Index %d\n", list_get_index_of(linked_list, 23));
  printf("The Element 99 is at Index %d\n", list_get_index_of(linked_list, 99));

  printf("Is 14 in the list? %d\n", list_is_in(linked_list, 14));
  printf("Is 87 in the list? %d\n", list_is_in(linked_list, 87));
  
  list_remove_from_back(linked_list);
  list_print(linked_list);
  printf("\n");
  list_remove_from_back(linked_list);
  list_print(linked_list);
  printf("\n");
  
  list_remove_from_front(linked_list);
  list_print(linked_list);
  printf("\n");
  
  list_remove_at_index(linked_list, 3);

  list_print(linked_list);
  printf("\n");
  
  return 0;
}
