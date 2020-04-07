#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include<math.h>
/* some helper functions. Can be used by other functions */

node *createNode(int row, int col, double value)
{
  /* creates a node from row, col and value */
  node *res = malloc(sizeof(node));
  res->col = col;
  res->row = row;
  res->value = value;
  res->colPtr = NULL;
  res->rowPtr = NULL;
  return res;
}

/* This function inserts a node to a linked list
   The node is inserted inorder by row index.
   returns a pointer to the row head of the list
   That is rowList[0]
*/

node *insertInOrderRow(node *N, node *head)
{
  node *before = NULL;
  node *now = head;
  while (now != NULL && now->row <= N->row)
  {
    before = now;
    now = now->rowPtr;
  }
  if (before == NULL)
  {
    N->rowPtr = now;
    return N;
  }
  before->rowPtr = N;
  N->rowPtr = now;
  return head;
}

/* This function inserts a node to a linked list                                          
   The node is inserted inorder by col index.  
   returns a pointer to the col head of the list.
   That is colList[0]                                         
*/

node *insertInOrderCol(node *N, node *head)
{
  node *before = NULL;
  node *now = head;
  while (now != NULL && now->col <= N->col)
  {
    before = now;
    now = now->colPtr;
  }
  if (before == NULL)
  {
    N->colPtr = head;
    return N;
  }
  before->colPtr = N;
  N->colPtr = now;
  return head;
}

/* this function checks if a list is sorted by row index
   This function is complete. 
*/

int is_sorted_Row(node *head)
{
  if (head == NULL || head->rowPtr == NULL)
    return 1;
  while (head->rowPtr != NULL)
  {
    if (head->row > head->rowPtr->row)
      return 0;
    head = head->rowPtr;
  }
  return 1;
}

/* this function checks if a list is sorted by col index                                
   This function is complete.                                                             
*/

int is_sorted_Col(node *head)
{
  if (head == NULL || head->colPtr == NULL)
    return 1;
  while (head->colPtr != NULL)
  {
    if (head->col > head->colPtr->col)
      return 0;
    head = head->colPtr;
  }
  return 1;
}

/* This function allocates memory for rowList and colList arrays
   Each array is an array of node*'s with size dimension.   
 */

int initializeMatrix(matrix *M, long dimension, FILE *in)
{
  M->dimension = dimension;
  M->colList = malloc(sizeof(node *) * dimension);
  M->rowList = malloc(sizeof(node *) * dimension);
  for(int i=0;i<dimension;++i)
    M->colList[i]=M->rowList[i]=NULL;
  long row, col;
  double value;
  if (in != NULL)
  {
    while (fscanf(in, "%ld %ld %e", &row, &col, &value) != EOF)
    {
      node *N = createNode(row, col, value);
      insertNode(M, N);
    }
  }
  return EXIT_SUCCESS;
}

/* This function inserts a node "inorder" to the sparse matrix
   structure. When inserting from rowList, node must be sorted in
   column order and when inserting from colList, node must be
   sorted by rows. Node is NOT inserted by the value.
*/
int insertNode(matrix *M, node *N)
{
  long col=N->col;
  long row=N->row;
  if(getValue(M,N->row,N->col)!=INFINITY)
  {
    free(N);
    return EXIT_SUCCESS;
  }
  M->rowList[row]=insertInOrderCol(N,(M->rowList)[row]);
  M->colList[col]=insertInOrderRow(N,(M->colList)[col]);
  return EXIT_SUCCESS;
}

/* This function prints the submatrix. 
   print as an array of lists. example
   0  (2,34)  (5,30)
   1 
   2  (1,45)
   Shows a submatrix from beginrow=0, endrow=2, begincol=1, endcol=5 
 */
void printSubMatrix(matrix *M, long beginrow, long endrow, long begincol, long endcol)
{
  for(long i=beginrow;i<=endrow;++i)
  {
    printf("%ld",i);
    node*head=M->rowList[i];
    while(head!=NULL&&head->col<=endcol)
    {
      if(head->col<begincol)
      {
        head=head->colPtr;
        continue;
      }
      printf(" (%ld, %e) ",head->col,head->value);
      head=head->colPtr;
    }
    printf("\n");
  }
}

/* indegree of a node is the number of edges coming into the node*/
long indegree(matrix *M, long N)
{
 // printf("***indegree:");
  long res=0;
  node*head=M->colList[N];
  while(head!=NULL)
  {
   // printf("%ld, %ld ",head->row,head->col);
    res++;
    head=head->rowPtr;
  }
 // printf("\n");
  return res;
}

/* outdegree of a node is the number of edges going out of the node*/
long outdegree(matrix *M, long N)
{
  long res=0;
  node*head=M->rowList[N];
  while(head!=NULL)
  {
    res++;
    head=head->colPtr;
  }
  return res;
}

/* This function returns the rowsum of row*/
double rowSum(matrix *M, long row)
{
  node*head=M->rowList[row];
  double res=0;
  while(head!=NULL)
  {
    res+=head->value;
    head=head->colPtr;
  }
  return res;
}

/* This function returns column sum of column */
double columnSum(matrix *M, long column)
{
  node*head=M->colList[column];
  double res=0;
  while(head!=NULL)
  {
    res+=head->value;
    head=head->rowPtr;
  }
  return res;
}

/* This function checks if the matrix is symmetric. A matrix is
   symmetric if A[i,j] = A[j,i] for all i, j
*/

int isSymmetric(matrix *M)
{
  long dimension=M->dimension;
  for(long i=0;i<dimension;++i)
  {
    node*rowhead=M->rowList[i];
    node*colhead=M->colList[i];
    while(rowhead!=NULL&&colhead!=NULL)
    {
      if(rowhead->col!=colhead->row||rowhead->value!=colhead->value)
        return FALSE;
      rowhead=rowhead->colPtr;
      colhead=colhead->rowPtr;
    }
    if(rowhead!=NULL||colhead!=NULL)
      return FALSE;
  }
  return TRUE;
}

/* This function returns the value at row and col 
   That is M[row][col]
   If the value does not exists, return the smallest
   negative integer or largest positive integer. Given in the .h 
   file as MININT or MAXINT.  
*/
double getValue(matrix *M, long row, long col)
{
  node*head=M->rowList[row];
  while(head!=NULL)
  {
    if(head->col==col)
      return head->value;
    head=head->colPtr;
  }
  return  INFINITY;
}

/* This function must free all dynamically allocated memory.
   Valgrind must be used to check for memory leaks
 */
int freeAll(matrix *M)
{
  long dimension=M->dimension;
  for(long i=0;i<dimension;++i)
  {
    node*head=M->rowList[i];
    while(head!=NULL)
    {
      node*temp=head;
      head=head->colPtr;
      free(temp);
    }
  }
  free(M->colList);
  free(M->rowList);
  free(M);
  return EXIT_SUCCESS;
}