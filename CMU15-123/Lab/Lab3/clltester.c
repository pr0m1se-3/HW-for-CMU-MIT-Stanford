#include "circularll.h" 
#include <assert.h>

#define true 1
#define false 0

int main(int argc, char* argv[]) 
{
  node* list = NULL; 
  assert(size(list)==0);
  printf("success!!!\n");
  append(&list,12);
  append(&list,14);
  assert(size(list)==2);
  printf("success!!!\n");
  removeAt(&list,0);
  assert(size(list)==1);
  printf("success!!!\n");
  assert(elementAt(list,0)==14);
  printf("success!!!\n");
  removeAt(&list,0);
  assert(isEmpty(list)==true);
  printf("success!!!\n");
  FILE* fp = fopen("data.txt", "r");
  int tmp;
  while (fscanf(fp,"%d",&tmp)>0){
    append(&list,tmp);
  }
  assert(size(list)==10);
  printf("success!!!\n");
  doCircular(list);
  assert(elementAt(list,10)==10); /* once the list is circular
                                     you should % size the index
                                     index=10, size=9 ==> 10%9==1
				  */
  assert(isCircular(list)==true);
  assert(isEmpty(list)==false);
  undoCircular(list);
  assert(contains(list,11)==true);
  list=sort(list);
  //printf("%s\n",toString(list)); 
  return EXIT_SUCCESS;
}





 



