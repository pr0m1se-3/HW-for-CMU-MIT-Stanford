/*
   Lab 1 - Reading, Storing and Sorting Large Data files 
   Name:
   Andrew ID: 
   Date:

   Input: file of words, one in each line
   output: sorted file of words with time to read and sort (optional)
   
 */

/* standard C libraries */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/* macros */
#define MAX_WORD_LENGTH 31
#define MAX_WORDS 172400 /* change the size based on largest file */
#define true 1
#define false 0

/* Function prototypes */
int readFile(char *infile, char list[][MAX_WORD_LENGTH], int flag);
/* flag is true to  sort , flag is false if no sort */
int insertInOrder(char list[][MAX_WORD_LENGTH], int lastIndex, char *word);
int writeToFile(char *outfile, char list[][MAX_WORD_LENGTH]);
void printTime(time_t begin);
void usage(char *processName);
/* include any other function prototype you may wish*/

/* global variables */
int wordCount = 0;

int main(int argc, char *argv[])
{
  time_t begin;
  char array[MAX_WORDS][MAX_WORD_LENGTH];
  memset(array, 0, sizeof(array[0][0]) * MAX_WORDS * MAX_WORD_LENGTH);
  int index=0;


  time(&begin);

  switch (argc)
  {
  case 3:
    readFile(argv[1], array, false);
    writeToFile(argv[2], array);
    break;
  case 4:
  {
    if (strcmp(argv[1], "-s") == 0)
    {
      readFile(argv[2], array, true);
      writeToFile(argv[3], array);
    }
    else if (strcmp(argv[1], "-t") == 0)
    {
      readFile(argv[2], array, false);
      writeToFile(argv[3], array);
      printTime(begin);
    }
    else
    {
      usage(argv[0]);
    }
    break;
  }
  case 5: /* complete case for -s -t */
  {
    if ((strcmp(argv[1], "-s") == 0 && strcmp(argv[2], "-t") == 0) || (strcmp(argv[1], "-t") == 0 && strcmp(argv[2], "-s") == 0))
    {
      readFile(argv[3], array, true);
      writeToFile(argv[4], array);
      printTime(begin);
    }
    else
      usage(argv[0]);
    break;
  }
  default:
    usage(argv[0]);
    break;
  }
  return 0;
 
}

/* Define all your functions here */

/* 
   Function: readFile
   Purpose: To read a file of words into a 2D array of chars, sort if flag is true
   Input:  infile - a name of a file of words one word per line. Max word length is 31
           wordcount - an address of an int variable to hold the size of the file
           list - a 2D array of chars. Fixed row (182000) and column size (32)
           Flag - if true array will be sorted (calls insertInOrder for each word)
   Output: return 0 for success, 1 otherwise
   Called by: main   
*/
int readFile(char *infile, char list[][MAX_WORD_LENGTH], int flag)
{
  FILE *f = fopen(infile, "r");
  if (f == NULL)
  {
    printf("Failed to open file %s\n", infile);
  }
  char word[MAX_WORD_LENGTH];
  int nowindex = 0;
  while (fgets(word, MAX_WORD_LENGTH, f) != NULL)
  {
    //printf("%s",word);
    if (flag)
      insertInOrder(list, nowindex++, word);
    else
      strcpy(list[nowindex++],word);
  }
  fclose(f);
  return 0;
}

/* Function: insertInOrder
   Purpose: This function inserts a word (in order) into the array of words
   Input: list is a 2D array of chars
          word is the word to be inserted in order
   output: return 0 is word can be inserted. 1 otherwise   
   Algorithm: Find the place to insert the word as shifting other words to the right   
   Called by: readFile
*/
int insertInOrder(char list[][MAX_WORD_LENGTH], int lastIndex, char *word)
{
  int index=0;
  while(index<lastIndex&&(strcmp(word,list[index])>0))
  {
    ++index;
  }
  while(lastIndex!=index)
  {
    strcpy(list[lastIndex],list[lastIndex-1]);
    --lastIndex;
  }
  strcpy(list[index],word);
  return 0;
}

/* Function: writeToFile
   purpose: This function writes the 2D array to a file
   input: outfile - name of a file to write
          wordcount - how many words to write to the file
          list - 2D array of words
   output: return 0 for success and 1 for failure
   Called by: main
*/
int writeToFile(char *outfile, char list[][MAX_WORD_LENGTH])
{
  FILE*f=fopen(outfile,"w");
  int index=0;
  while(list[index][0])
  {
    //printf("%s",list[index]);
    fprintf(f,"%s",list[index]);
    index++;
  }
  fclose(f);
  return 0;
}

/* 
   Function: printTime
   purpose: Takes the begin time, find the current time and prints the difference in 
            miliseconds   
   input: begin time as a long (time_t)
   output: prints time
   Called by main 
*/
void printTime(time_t begin)
{
  time_t end;
  time(&end);
  printf("The time cost is %lu\n",end-begin);
  return;
}

/* this function is complete  DO NOT MODIFY
*/
void usage(char *processName)
{
  printf("Usage %s [-s] [-t] inputFileName outputFileName\n", processName);
}
