/* 
  This function tests important  dictlib methods.
  Your code must pass all assertions.
*/ 

#include "dictlib.h" 
#include <assert.h>

int main(int argc, char* argv[]) 
{
  printf("testing assertions ...\n");
  int cap = 10;
  char** A = calloc(cap,sizeof(char*));
  resize(&A,&cap);
  assert(cap==20);
  resize(&A,&cap);
  assert(cap==40);
  assert(A[cap-1]==NULL);
  printf("All assertions for resize passed\n");
  /******************************************/
  assert(insertWord(A,"guna",cap,0)==EXIT_SUCCESS);
  assert(insertWord(A,"guna",cap,cap-1)==EXIT_SUCCESS);
  assert(insertWord(A,"guna",cap,cap/2)==EXIT_SUCCESS);
  assert(insertWord(A,"guna",cap,-1)==EXIT_FAILURE);
  assert(insertWord(A,"guna",cap,cap)==EXIT_FAILURE);
  free(A);
  A=NULL;
  assert(insertWord(A,"guna",cap,10)==EXIT_FAILURE);
  assert(insertWord(A,NULL,cap,10)==EXIT_FAILURE); 
  printf("All assertions for insertword passed\n");
  /*******************************************/                                          
  char* list[10]; 
  for (int i=0; i<10; i++)  list[i] = malloc(10);
  strcpy(list[0],"andy"); strcpy(list[1],"bob"); strcpy(list[2],"guna");
  strcpy(list[3],"me"); strcpy(list[4],"pete"); strcpy(list[5],"zoo"); 
  assert(binarysearch(list,"guna",0,7)==2);
  assert(binarysearch(list,"andy",0,7)==0);
  assert(binarysearch(list,"zoo",0,7)==5);
  assert(binarysearch(NULL,"zoo",0,7)==-1);
  assert(binarysearch(list,NULL,0,7)==-1);
  //assert(binarysearch(list,"zoo",10,7)==-1);
  printf("All assertions for binarysearch passed\n");
  /*******************************************/ 
  char* list2[10];
  for (int i=0; i<6; i++)  list2[i] = malloc(10);
  strcpy(list2[0],"zoo"); strcpy(list2[1],"me"); strcpy(list2[2],"bob");
  strcpy(list2[3],"quad"); strcpy(list2[4],"pete"); strcpy(list2[5],"guna");
  sortArray(list2,0,5);
  assert(strcmp(list2[0],"bob")==0);
  assert(strcmp(list2[1],"guna")==0);
  assert(strcmp(list2[2],"me")==0);
  assert(strcmp(list2[5],"zoo")==0);
  printf("All assertions for sortArray passed\n");
  /*******************************************/
 
  return EXIT_SUCCESS; 
} 



