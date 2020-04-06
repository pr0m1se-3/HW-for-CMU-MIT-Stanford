/*
   The purpose of this program is to understand how to create
   a java style ArrayList using C pointers. You are to complete 
   the functions createNode, insertRecordInOrder and freeAll.
   Compile the program as: gcc -std=c99 -Wall -pedantic -ansi SL6.c
   Run the program as: ./a.out data.txt
   DUE: Sunday Feb 20, 2011  @ 11:59 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node
{
    char *name;
    int age;
    struct node *next;
} node;

typedef struct ArrayList
{
    node *list; /* linked list of nodes */
    int count;  /* how many nodes are in the array */
} ArrayList;

node *createNode(char *name, int age);
void insertRecordInOrder(ArrayList *A, node *N);
void print(ArrayList *A);
int freeAll(ArrayList *A);

int main(int argc, char *argv[])
{
    FILE *fp;
    char name[32];
    int age;
    ArrayList *A = malloc(sizeof(ArrayList));
    A->list = NULL;
    A->count = 0;
    if ((fp = fopen(argv[1], "r")) == NULL)
        return EXIT_FAILURE;
    while (fscanf(fp, "%s %d", name, &age) > 0)
    {
        insertRecordInOrder(A, createNode(name, age));
        (A->count)++;
        print(A);
    }
    print(A);
    return EXIT_SUCCESS;
}

/* creates node and returns a pointer 
   must allocate memory.
*/
node *createNode(char *name, int age)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
        return NULL;
    new->name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new->name, name);
    new->age = age;
    new->next = NULL;
    return new;
}

/* insert the node N to the list in the order of the name */
void insertRecordInOrder(ArrayList *A, node *N)
{
    if (A->count == 0)
    {
        A->list = N;
        return;
    }
    node *head = A->list;
    node *before = NULL;

    while (head != NULL && strcmp(head->name, N->name) < 0)
    {
        before = head;
        head = head->next;
    }
    if(before==NULL){
        
        N->next=head;
        A->list= N;
        return;
    }
    before->next = N;
    N->next = head;
}

/* print the ArrayList. This function is complete */
void print(ArrayList *A)
{
    int i;
    node *head = A->list;
    for (i = 0; i < A->count; i++)
    {
        printf("(%s %d) ", head->name, head->age);
        head = head->next;
    }
    printf("\n");

    return;
}

/* free all dynamically allocated memory */
int freeAll(ArrayList *A)
{
    node*head=A->list;
    while(head!=NULL){
        node*temp=head->next;
        free(head);
        head=temp;
    }
    return EXIT_SUCCESS;
}