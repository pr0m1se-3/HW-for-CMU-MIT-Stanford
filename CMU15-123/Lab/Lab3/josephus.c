#include "circularll.h" 
void usage(char*);

int main(int argc, char* argv[]) 
{

  /* you need to modify this */ 
  LL* list = NULL;
  int i;
  for (i=0; i<atoi(argv[1]); i+=10){
    add(&list, i);
  }
  printf("%s \n", toString(list));
  rotate(&list,1);
  printf("%s \n", toString(list));
  printf("%d \n", size(list));  
  return EXIT_SUCCESS; 
}

void usage(char* processName)
{
  printf("Usage %s complete me \n", processName);
}



 



