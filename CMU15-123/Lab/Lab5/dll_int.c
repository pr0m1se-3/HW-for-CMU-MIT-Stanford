#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef __STRING
#define __STRING(x) #x

/* Prints an error if the expression doesn't evaluate to SUCCESS */
#define TRY(exp) if((exp)!=SUCCESS) {printf("--%s failed in file %s: line %d \n", __STRING(exp), __FILE__, __LINE__);}
#define TRY_FAIL(exp) if((exp)== SUCCESS) {printf("--%s did not fail in file %s: line %d \n", __STRING(exp), __FILE__, __LINE__);}

int icomp(const void *a, const void *b);
void printi(void *val, void *args);
void idelete(void *, void *);

int main(int argc, char *argv[]) {
  dll_l *list = (dll_l*)malloc(sizeof(dll_l));
  void *retval;

  if(list==NULL) {
    printf("No memory to allocate list!\n");
    return -1;
  }

  /* Init dll */
  TRY(dll_init_list(list));

  /* Set compare function */
  TRY(dll_set_cmp(list, icomp));

  /* Insert a bunch of stuff */
  printf("Inserting...\n");
  TRY(dll_insert(list, (void*)50, (void*)500));
  TRY(dll_insert(list, (void*)30, (void*)300));
  TRY(dll_insert(list, (void*)70, (void*)700));
  TRY(dll_insert(list, (void*)20, (void*)200));
  TRY(dll_insert(list, (void*)40, (void*)400));
  TRY(dll_insert(list, (void*)60, (void*)600));
  TRY(dll_insert(list, (void*)80, (void*)800));
  TRY(dll_insert(list, (void*)35, (void*)350));
  TRY(dll_insert(list, (void*)65, (void*)650));
  
  TRY(dll_insert(list, (void*)50, (void*)500));
   
  /* Insert again, make sure it fails */
  printf("Re-inserting.  Should always fail...\n");
  TRY_FAIL(dll_insert(list, (void*)50, (void*)500));
  TRY_FAIL(dll_insert(list, (void*)30, (void*)300));
  TRY_FAIL(dll_insert(list, (void*)70, (void*)700));
  TRY_FAIL(dll_insert(list, (void*)20, (void*)200));
  TRY_FAIL(dll_insert(list, (void*)40, (void*)400));
  TRY_FAIL(dll_insert(list, (void*)60, (void*)600));
  TRY_FAIL(dll_insert(list, (void*)80, (void*)800));
  TRY_FAIL(dll_insert(list, (void*)35, (void*)350));
  TRY_FAIL(dll_insert(list, (void*)65, (void*)650));


  /* Test retrieve */
  printf("Retrieving...\n");
  TRY(dll_retrieve(list, (void*)50, &retval));
  if((int)retval != 500) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)30, &retval));
  if((int)retval != 300) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)70, &retval));
  if((int)retval != 700) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)20, &retval));
  if((int)retval != 200) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)40, &retval));
  if((int)retval != 400) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)60, &retval));
  if((int)retval != 600) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)80, &retval));
  if((int)retval != 800) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)35, &retval));
  if((int)retval != 350) {
    printf("Retrieve recieved wrong value!\n");
  }
  TRY(dll_retrieve(list, (void*)65, &retval));
  if((int)retval != 650) {
    printf("Retrieve recieved wrong value!\n");
  }
 
  /* Test bad retrieves */

  printf("Retrieving bad values.  Should always fail...\n");
  TRY_FAIL(dll_retrieve(list, (void*)1324, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)2123, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)29, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)4, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)34, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)324, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)1324, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)24, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)824, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)12, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)13, &retval));
  TRY_FAIL(dll_retrieve(list, (void*)124, &retval));

  /* Test map */
  printf("Mapping...\n");
  TRY(dll_map(list, printi, (void*)"Map sees:"));
  /* dll_dispose(list,idelete,(void *)("Delete done successfully")); */ 
  return 0;
}

/* Compare function */
int icomp(const void *a, const void *b) {
  if((int)a<(int)b) {
    return -1;
  } else if((int)a>(int)b) {
    return 1;
  } else {
    return 0;
  }
}

/* Print function for map */
void printi(void *val, void *args) {
  printf("%s %d\n", (char*)args, (int)val);
  return;
}

void idelete(void *a, void *args)
{
	free(a);
	return;
}