#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LEN 50
#define MAX_WORD_LEN 50

int printcount = 0;
int loadcount = 0;

int scomp(const void *a, const void *b);
void sprint(void *value, void *file);
void readFile(dll_l *list, const char *inName);
void writeToFile(const char *outName, dll_l *list);
void printTime(time_t begin);
void usage(char* processName);
void sdelete(void *,void *);

int main(int argc, char *argv[]) {
  time_t begin;   
  dll_l *list = (dll_l*)malloc(sizeof(dll_l));
  char test[20];
  time(&begin);

  /* Initialize list*/
  dll_init_list(list);

  /* Set compare function */
  dll_set_cmp(list, scomp);
  
  switch (argc)
  {
  case 3:
    readFile(list, argv[1]);
    writeToFile(argv[2], list);
    break;
  case 4:
  {
    if (strcmp(argv[1], "-t") == 0)
      {
        readFile(list, argv[2]);
        writeToFile(argv[3], list);
        printTime(begin);
      }
    else if(strcmp(argv[1],"-d")== 0)
      {
	printf("Please enter the key to be deleted\n");
	scanf("%s",test);
	readFile(list,argv[2]);
	/*dll_deletenode(list,(void *)test);*/
	writeToFile(argv[3],list);
      }
      else
      {
        usage(argv[0]);
      }
    break;
  }
  case 5:
  default:
    usage(argv[0]);
    break;
  
  }
  /*dll_dispose(list,sdelete,(void *)("Deleted successfully!"));*/
  /*free(list);*/
  return 0;

}

void usage(char* processName)
{
  printf("Usage %s [-t|-d] inputFileName outputFileName\n", processName);
}

/* Prints the amount of time that has passed since begin */
void printTime(time_t begin) {
  time_t end;
  time(&end);

  printf("The time to execute the program is %d seconds.\n", (int)(end-begin));

  return;
}

/* Compares two strings passed as void*s */
int scomp(const void *a, const void *b) {
  if((a==NULL) || (b == NULL)) {
    return -1;
  }

  return strcmp((char *)a,(char *)b);
  
}

/* Reads strings in from the file */
void readFile(dll_l *list, const char *inName) {
  char *buffer;
  FILE* infile;

  /* Open file */
  infile = fopen(inName, "r");

  if(infile==NULL) {
    return;
  }

  buffer = malloc(sizeof(char)*MAX_WORD_LEN);

  while(fscanf(infile, "%s", buffer)!=EOF) {
    dll_insert(list, buffer, buffer);
    buffer = malloc(sizeof(char)*MAX_WORD_LEN);
    loadcount++;
  }



  return;
  
}

/* prints a string to the file */
void sprint(void *value, void *file) {
  FILE *outfile = (FILE*)file;
  char *word = (char*)value;

  printcount++;
  fprintf(outfile, "%s\n", word);

  return;
  
}

void sdelete(void *node,void *args)
{
  dll_node *temp= (dll_node *)node;
  printf("%s\n",(char*)args);
  free(temp->key);
  free(temp);		
  return;
}

/* Outputs to a file */
void writeToFile(const char *outName, dll_l *list) {
  FILE *outfile;

  /* Open file */
  outfile = fopen(outName, "w");

  if(outfile==NULL) {
    return;
  }

  dll_map(list, sprint, (void*)outfile);
  fclose(outfile);
  return;

}