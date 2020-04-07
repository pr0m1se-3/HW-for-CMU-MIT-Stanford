#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXINT 0x7fffffff
#define MININT 0x80000000

struct node
{  
    long row;
    long col;
    double value;
    struct node* rowPtr;
    struct node* colPtr;
};

typedef struct node node;

struct matrix
{
    long dimension;
    node** rowList;
    node** colList;
};

typedef struct matrix matrix;

node* createNode(int row, int col, double value);
node* insertInOrderRow(node* N, node* head);
node* insertInOrderCol(node* N, node* head);
int is_sorted_Row(node* head);
int is_sorted_Col(node* head);
int initializeMatrix(matrix*, long , FILE*);
int insertNode(matrix*, node*);
void printSubMatrix(matrix* ,long , long , long , long );
long indegree(matrix*, long);
long outdegree(matrix*, long);
double rowSum(matrix*, long);
double columnSum(matrix*, long );
int isSymmetric(matrix* );
double getValue(matrix*, long, long);
int freeAll(matrix*);

#endif