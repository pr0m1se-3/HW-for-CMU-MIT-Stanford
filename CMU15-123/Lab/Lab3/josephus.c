#include "circularll.h"
void usage(char *);

int main(int argc, char *argv[])
{
  node *list = NULL;
  int num = 16;
  for (int i = 1; i <= num; ++i)
  {
    append(&list,i);
  }
  doCircular(list);
  printf("%s\n",toString(list));
  while(size(list)!=1)
  {
    removeAt(&list,1);
    rotate(&list,-1);
    printf("%s\n",toString(list));
  }
  printf("%s\n",toString(list));
}
