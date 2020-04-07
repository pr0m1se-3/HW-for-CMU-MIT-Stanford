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
// initialize the dll_l structure fields.
int dll_init_list(dll_l *list)
{
  if (list == NULL)
    return FAILURE;
  list->head = NULL;
  list->cmp = NULL;
  list->free_key = NULL;
  list->free_value = NULL;
  return SUCCESS;
}

/*set the free_key function */
int dll_set_free_key(dll_l *list, void (*free_key)(void *))
{
  if (list == NULL || free_key == NULL)
    return FAILURE;
  list->free_key = free_key;
  return SUCCESS;
}

/* set the free_value function */
int dll_set_free_value(dll_l *list, void (*free_value)(void *))
{
  if (list == NULL || free_value == NULL)
    return FAILURE;
  list->free_value = free_value;
  return SUCCESS;
}

/*set the compare funciton*/
int dll_set_cmp(dll_l *list, int (*cmp)(const void *, const void *))
{
  if (list == NULL || cmp == NULL)
    return FAILURE;
  list->cmp = cmp;
  return SUCCESS;
}

/* insert the node in ascending/alphabetical order */
int dll_insert(dll_l *list, void *key, void *value)
{
  if (list == NULL || key == NULL || value == NULL)
    return FAILURE;

  dll_node *newnode = malloc(sizeof(dll_node));
  newnode->key = key;
  newnode->value = value;
  newnode->next = NULL;
  newnode->prev = NULL;

  dll_node *head = list->head;
  dll_node *before = NULL;
  while (head != NULL && list->cmp(head->key, key) <= 0)
  {
    if(list->cmp(head->key, key) == 0)
      return FAILURE;
    before = head;
    head = head->next;
  }
  
  if (before == NULL) //插到队头
  {
    newnode->next = head;
    if (list->head != NULL)
    {
      list->head->prev = newnode;
    }
    list->head = newnode;
    return SUCCESS;
  }

  before->next = newnode;
  newnode->prev = before;
  newnode->next = head;
  if (head != NULL) //考虑插入的是最后一个
    head->prev = newnode;

  return SUCCESS;
}

/* Retrieve the value of the node given the key*/
int dll_retrieve(dll_l *list, void *key, void **value)
{
  if (list == NULL || list->cmp == NULL)
    return FAILURE;
  dll_node *head = list->head;
  while (head != NULL)
  {
    if (list->cmp(head->key, key) == 0)
    {
      *value = head->value;
      return SUCCESS;
    }
    if (list->cmp(head->key, key) > 0)
      return FAILURE;
    head = head->next;
  }
  return FAILURE;
}

/* delete a node given the key*/
int dll_deletenode(dll_l *list, void *key)
{
  if (list == NULL || list->cmp == NULL)
    return FAILURE;

  dll_node *head = list->head;
  dll_node *before = NULL;

  while (head != NULL)
  {
    if (list->cmp(head->key, key) == 0)
    {
      break;
    }
    if (list->cmp(head->key, key) > 0)
      return FAILURE;
    before = head;
    head = head->next;
  }
  if (head == NULL) //空队列
    return FAILURE;

  if (before == NULL) //去掉第一个
  {
    list->head = head->next;
    if (head->next != NULL)
    {
      head->next->prev = NULL;
    }
    list->free_key(head->key);
    list->free_value(head->value);
    free(head);
    return SUCCESS;
  }
  before->next = head->next;
  if (head->next != NULL)
    head->next->prev = before;

  list->free_key(head->key);
  list->free_value(head->value);
  free(head);
  return SUCCESS;
}

//The dll_map function will apply the function, func to all the elements in the data structure. For example func can be a print function that defines how value in each node should be printed. The third argument args can become an input to one of the func arguments. See dll_string.c to see how dll_map is used by the writeToFile function. Apply function to value of the node.
/* doubly linked list map*/
int dll_map(dll_l *list, void (*func)(void *, void *), void *args)
{
  if(list->head==NULL)
    return FAILURE;
  dll_node*head=list->head;
  while(head!=NULL)
  {
    (*func)(head->value,args);
    head=head->next;
  }
  return SUCCESS;
}

/* free list */
//The dll_dispose function will free all memory associated with the list. The func can define how memory in each value in a node should be freed. The function (as in map) applies to all the value fields in the node. This function can overwrite free_value function or can be left as null (in this case dispose will use free_key and free_value functions to free the data)
int dll_dispose(dll_l *list, void (*func)(void *, void *), void *args)
{

  return FAILURE;
}
