/**
 *  dictlib.h for lab2
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>

#ifndef H_DICTLIB
#define H_DICTLIB

#define MAX_WORD_LEN 35 
#define INITIAL_ARR_LEN 50

/* insert a word */
int insertWord(char**, char*, int, int);

/* double the array size */
int resize(char***, int* );


/* sort the array using any sorting algorithm */
int sortArray(char **, int, int );

/* free the entire array */
void freeAll(char **, int );

/* print the array and all its entries */
void  printArray(FILE* , char **, int );

/* binary search. An efficient way to find a 
   place to insert.
*/
int binarysearch(char** , char* , int , int );


#endif
