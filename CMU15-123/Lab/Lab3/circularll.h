/**
 *  CircularLL.h for lab3
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
#ifndef H_CIRCULARLL
#define H_CIRCULARLL


typedef struct node{
  int data;
  struct node* next;
} node;

/* function prototypes */
void freeAll(node*);
int size(node*);
void append(node**,int);
node* prepend(node**,int);
void insertAt(node**,int, int );
char* toString(node*);
int contains(node*, int );
int isEmpty(node*);
int removeAt(node**, int );
node* rotate(node**, int ); 
int elementAt(node*,int);
void doCircular(node*);
void undoCircular(node*);
node* sort(node*);
int isCircular(node* );

#endif
