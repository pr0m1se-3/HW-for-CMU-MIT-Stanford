/**
 *  circularLL.c for lab3
 */

#include "circularll.h"



/* clears the list. All heap memory allocated for list nodes
   must be freed. Check with valgrind after using this 
   function in the main.
*/

/* precondition: list is a singly LL 
   postcondition: all memory allocated for list nodes and data are freed
*/
 
void freeAll(node* list){
   while(list!=NULL)
   {
      node*temp=list;
      list=list->next;
      free(temp);
   }
}


/* returns the size of the list. 
   precondition: list is a singly LL
   postcondition: list has not chnaged 
 */
int size(node* list) {

   int res=0;
   while(list!=NULL)
   {
      ++res;
      list=list->next;
   }
  return res;
}


/* append (insert to end) a node with value data.
   append must cover the case of inserting the first one
   precodition: list is a singly LL and can be empty
   postcondition: new data node is added to the end of the list
 */
 
void append(node** list,int data){
   node* insert=malloc(sizeof(node*));
   if(insert==NULL)
   {
      printf("falied to malloc a new pointer of node");
      return;
   }
   insert->data=data;
   insert->next=NULL;
   if(isEmpty(*list))
   {
      *list=insert;
      printf("now the head is not null!\n");
      return;
   }
   node*before=NULL;
   node*now=*list;
   while(now!=NULL)
   {
      before=now;
      now=now->next;
   }
   before->next=insert;
}


/* insert the node with value data to the beginning of the list 
   returns a pointer to the new head.  
   precodition: list is a singly LL and can be empty
   postcondition: new data node is added to the beginning
     of the list. The head must now point to this new node 
*/
node* prepend(node** listptr,int data){
   node* insert=malloc(sizeof(node*));
   if(insert==NULL)
   {
      printf("falied to malloc a new pointer of node");
      return NULL;
   }
   insert->data=data;
   insert->next=NULL;   
   if(isEmpty(*listptr))
   {
      *listptr=insert;
      return *listptr;
   }
   insert->next=*listptr;
   *listptr=insert;
   return *listptr;
}


/* insert data  to the list at index. 
   0 <= index < size(list)
   precondition: list is a singly LL and can be empty
   postcondition: a new node with data is added to the
      list index given within boundaries
*/

void insertAt(node** listptr , int data, int index ){
   if(!index)
   {
      prepend(listptr,data);
      return;
   }
   if(index==size(*listptr))
   {
      append(listptr,data);
   }
   node* insert=malloc(sizeof(node*));
   if(insert==NULL)
   {
      printf("falied to malloc a new pointer of node");
      return;
   }
   insert->data=data;
   insert->next=NULL; 

   node*before=NULL;  
   node*now=*listptr;
   while(index--)
   {
      before=now;
      now=now->next;
   }
   before->next=insert;
   insert->next=now;
   return;
}


/* returns a java style string that represents the list node values
   Separated each value with a space. Your must allocate a dynamic
   block of memory just enough to hold all elements in the list.
   freeAll may not be responsible for this memory. When testing
   freeAll comment out any calls to toString
   returns a string, for example "10 12 14 56 NULL"
   precondition: list is a singly LL and list can be empty
   postcondition: A string is returned with valid memory allocation
      list is not changed.
*/ 

char* toString(node* list) {

  return NULL;
}


/* returns 1(true) if the list contains node with value data. Otherwise 
   return 0 (false)
   0 <= n < size(list)
   precondtion: list is a singly LL and can be empty
   postcondition: list is not changed
 
*/
int contains(node* list, int data ){
   while(list!=NULL)
   {
      if(list->data==data)
         return 1;
      list=list->next;
   }
   return 0;
}


/* returns 1(true) if the list is empty. Otherwise return 0 (false)
   precondition: list is a singly LL and can be empty
   postcondition: list is not changed
*/
int isEmpty(node* list){

  return size(list)==0;
}


/* remove the node at index (indices starts from 0) 
   must free memory for the node.
   0<= index < size(list)
   precondition: list is a singly LL and can be empty
   postcondition: a node at index is removed. List size
     is one less
*/  
int removeAt(node** listptr, int index ){
   if(*listptr==NULL||index<0||index>=size(*listptr))
      return 0;
   if(!index)
   {
      node*temp=*listptr;
      *listptr=temp->next;
      free(temp);
      return 1;
   }

   node*before=NULL;
   node*now=*listptr;
   while(index--)
   {
      before=now;
      now=now->next;
   }
   before->next=now->next;
   free(now);
   return 1;
}


/* list is rotated clockwise (n>0) or counterclockwise( n<0)
   see description for a precise definition of this.
   A positive n indicates rotating clockwise. For example
   if n = 2 then rotation means head now pointing to second to
   last node in the list.
   Precondition: the list is circular
   Postcondition: list nodes has not changed but head may have 
*/
node* rotate(node** listptr, int n ){

  return NULL;
}

/* returns the element at index .
   0<= index < size(list)
   Precondition: list is singly LL and can be empty
*/
int elementAt(node* list,int index){
   if(list==NULL||index<0||index>=size(list))
      return 0;
   while(index--)
   {
      list=list->next;
   }
   return list->data;
}

/* make a non circular list circular.
   pre-condition: list is not circular
   post-condition: list is circular
   use isCircular to assert before changing
*/
void doCircular(node* list) {
   assert(1==isCircular(list));
   node*head=list;
   node*before=NULL;
   node*now=list;
   while(now!=NULL)
   {
      before=now;
      now=now->next;
   }
    before->next=head;
}


/* make a circular list, non circular
   pre-condition: list is circular
   post-condition: list is not circular
   use isCircular to assert before changing
*/
void undoCircular(node* list){
   assert(0==isCircular(list));
   node*head=list;
   node*now=list;
   while(now->next!=head)
      now=now->next;
   now->next=NULL;
}

/* returns 1 if the list is circular. otherwise return 0
   a null list is circular.
   A circular list means the last node is connected to
   first node. An empty list is circular by defintion
   A list is one node is circular if head->next = head
*/
int isCircular(node* list){

   node*fast=list;
   node*slow=list;
   while(fast!=NULL&&slow!=NULL&&slow->next!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
   {
      if(fast==slow)
         return 1;
      slow=slow->next;
      fast=fast->next->next;
   }
   return 0;
}

/* sort the list in incrasing order of the elements. Return a pointer to
   the head of the list. Any dynamically allocated for sorting
   the list must be freed. One method is to create an array
   from the linked list and use our insertion sort from lab2
   to sort it and then recreate the sorted list. Deallocate memory
   allocated for the dynamic array. 
   Preconditions: list is a singly LL.
   Postcondition: list is sorted. 
*/ 
node* sort(node* listptr){

  return NULL;
}
