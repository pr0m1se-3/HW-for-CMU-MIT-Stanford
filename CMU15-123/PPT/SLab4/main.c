/* Skills Lab 4  (This lab is optional)
   Name:
   Andrew ID:
   Points : 10 points

   Instructions: Complete the tasks as shown below.
   You may want to comment using // other tasks 
   while working on one task. Your code must NOT
   seg fault to get full credit 
   
   Compile : gcc -std=c99 SL4.c
   Run: ./a.out input.txt  
   Submit to: /afs/andrew/course/15/123/handin/SL4/ID
   Due one or Before: 2/4/11 11:59PM
*/   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* 
  This function takes an array of char *'s, a file name
  and allocate memory for each word in the file.
  It must return the size of the array through
  &n. Note that this is a new concept. By passing the address
  of a variable through argument list we can actually change the
  value of the variable. The function must pass all assertions.
  function must return -1 if the file does not exists. Otherwise
  return the number of records read.   
*/

int readFile(char* fname, char* A[], int *n){ 
    FILE*f=fopen(fname,"r");
    if(f==NULL)
        return -1;
    char word[100];
    while(fscanf(f,"%s",word)!=EOF)
    {
        A[*n]=malloc(sizeof(char)*(strlen(word)+1));
        strcpy(A[*n],word);
        (*n)++;
    }
  return *n; 
}

/* This function Swaps two memory blocks.
   first block starts at address old
   second block starts at address new
   the size of the block is given as size
   you can use memcpy or memmove
*/
int swapblocks(void* old, void* new, size_t size){
    if(old==NULL||new==NULL)
        return EXIT_FAILURE;
    void*temp=malloc(size);
    memmove(temp,old,size);
    memmove(old,new,size);
    memmove(new,temp,size);
    free(temp);
  return EXIT_SUCCESS;
} 


int main(int argc, char* argv[]){
  char* B[100];
  for (int i=0; i<100; i++)
    B[i] = NULL;
  char word[32];  
  int i=0;
  assert(readFile("data.txt",B,&i)==10);
  assert(readFile("temp.txt",B,&i)==-1);
  for (int j=0; j<i;j++)
    assert(B[j]!= NULL);

  /* TASK 2 - Swap Blocks */
  int A[] ={1,2,3,4,5,6,7,8,9};
  assert(swapblocks(A,A+4,4*sizeof(int))==0);
  assert((A[0]==5) && (A[1]==6) && A[2]==7 && A[3]==8);
  assert((A[4]==1) && (A[5]==2) && A[6]==3 && A[7]==4);
  assert(A[8]==9);     

printf("Finish!!!\n");
  return EXIT_SUCCESS;
}