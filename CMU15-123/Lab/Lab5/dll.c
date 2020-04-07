 /*@file dll.c
 *
 *  @brief DLL implementation
 *
 *  @author your name
 *
 *  @bug No known bugs
 */

#include "dll.h"
#include <stdio.h>
#include <stdlib.h>


/* initialise list*/
int dll_init_list(dll_l *list) {
  
  return SUCCESS;
}

/*set the free_key function */
int dll_set_free_key(dll_l *list, void (*free_key)(void*))
{
  
   return SUCCESS;
}

/* set the free_value function */
int dll_set_free_value(dll_l *list, void (*free_value)(void*))
{
  
  return SUCCESS;
}

/*set the compare funciton*/
int dll_set_cmp(dll_l *list, int (*cmp)(const void*, const void*)) {
  
  return SUCCESS;
}

/* insert the node in ascending/alphabetical order */
int dll_insert(dll_l *list, void *key, void *value)
{
  
  
  return SUCCESS; 
}


/* Retrieve the value of the node given the key*/
int dll_retrieve(dll_l *list, void *key, void **value) {
  

  return SUCCESS;
 
}


/* delete a node given the key*/
int dll_deletenode(dll_l *list, void *key)
{
	
   return FAILURE;
}

/* doubly linked list map*/
int dll_map(dll_l *list, void (*func)(void*, void*), void* args) {
 

   return SUCCESS;
}


/* free list */
int dll_dispose(dll_l *list, void (*func)(void*, void*), void* args) {

  return FAILURE;
}

