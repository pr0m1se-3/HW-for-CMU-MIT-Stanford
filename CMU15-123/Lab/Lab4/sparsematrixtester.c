/*
  Lab 4 Tester
  keep checking back in . This function will change often
  Report any discrepancies to guna@cs.cmu.edu
  Due: Sunday Feb 27, 2011
*/
#include "matrix.h"
#include <assert.h>
#include<math.h>

int main(int argc, char* argv[])
{
    FILE* in;
    long dimension, row, column;
    double value;
    matrix* M = malloc(sizeof(matrix));
    initializeMatrix(M,10,NULL);
    assert(M->dimension==10 && M->rowList != NULL && M->colList!=NULL);
    node* N = createNode(0,4,34.5);
    insertNode(M,N);
    N = createNode(0,2,56.7);
    insertNode(M,N);
    assert(is_sorted_Row(M->rowList[0])==TRUE);
    assert(is_sorted_Col(M->colList[4])==TRUE);
    assert(is_sorted_Col(M->colList[2])==TRUE);
    N=createNode(1,4,56.7);
    insertNode(M,N);
    assert(is_sorted_Col(M->colList[4])==TRUE);
    assert(is_sorted_Row(M->rowList[0])==TRUE);
    N=createNode(1,2,56.7);
    insertNode(M,N);
    assert(is_sorted_Col(M->colList[2])==TRUE);

    N=createNode(1,2,56.7); /* duplicate row col cannot be inserted */
    int oldindeg = indegree(M,1);
    insertNode(M,N);
    assert(indegree(M,1)== oldindeg); /* indegree should not change
                                         since we did not insert duplicate */ 
    assert(indegree(M,0)==0);
    //printSubMatrix(M,0,9,0,9);

    assert(indegree(M,2)==2);
    assert(indegree(M,4)==2);
    assert(outdegree(M,0)==2);
    N=createNode(0,0,65.1);
    insertNode(M,N);
    assert(outdegree(M,0)==3);
    assert(indegree(M,0)==1);
    assert(isSymmetric(M)==FALSE);
    assert(rowSum(M,0)==156.3);
    assert(columnSum(M,0)==65.1);
    assert(getValue(M,1,4)==56.7);
    assert(getValue(M,2,2)==INFINITY);
    freeAll(M); /* this should clean up the memory */
 
    /* testing with large files - to be added */
    FILE* fp = fopen("10000.txt","r");
    long dim;
    M = malloc(sizeof(matrix));
    fscanf(fp,"%ld", &dim);
    initializeMatrix(M,dim,NULL);
    while (fscanf(fp,"%ld %ld %e", &row, &column, &value)>0){
      N = createNode(row,column,value);
      insertNode(M,N);
     }
    // assert(indegree(M,7)==2);
    // assert(outdegree(M,7)==2);
    /* add more tests here looking at the data file */
    assert(isSymmetric(M)==FALSE);
    fclose(fp);
    freeAll(M);
    printf("Success!\n");
   /* write more testing with data files at /afs/andrew.cmu.edu/course/15/123/downloads/lab4/datafiles*/
   
    return 0;
   
}

  