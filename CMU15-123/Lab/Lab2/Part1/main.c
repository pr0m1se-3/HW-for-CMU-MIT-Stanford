/*  programming Lab 2
    15-123 Lecture 3
    Spring 2011

    Name: 
    Andrew ID:
    Due Date: Monday 2/7/11
*/ 

#include "dictlib.h" 


int main(int argc, char* argv[]) 
{
  int count=0;       /* no elements in the array*/
  int cap=INITIAL_ARR_LEN; /* cap is the capacity of the array. We will
                              start with INITIAL_ARR_LEN=50 and double
                              the capacity as needed 
                           */
  char** array;     /* A place to hold an array of char*'s */
  FILE* fin, *fout; /* input and output file pointers */
  char word[32];
  if (argc<3)       /* program must have at least 3 args
                       >./a.out infile outfile
		    */
    return EXIT_FAILURE;
  
  array = malloc(cap*sizeof(char*));  /* allocate memory for the array */
  fin = fopen(argv[1],"r");  /* open argv[1] for read */
  fout = fopen(argv[2],"w"); /* open argv[2] for write */
  if (fin==NULL)             /* if there is no input file exit */
    return EXIT_FAILURE; 

  while (fscanf(fin,"%s", word)>0){  /* read words from the file */
    if (count>=cap)           /* if no more space in the array */
      resize(&array, &cap);  /* double the capacity */
    insertWord(array,word,cap,count);/* insert the word to next array location */    count++;
    // printf("After insert %s\n",word);
    // for(int i=0;i<count;++i)
    // {
    //   printf("%d,%s ",i,array[i]);
      
    // }
    // printf("\n");
  }

  //printf("*******read is done!\n");
  // for(int i=0;i<100;++i)
  // {
  //   printf("%d,%s\n",i,array[i]);
  // }
  sortArray(array,0,count-1);       /* sort the array using any sorting algorithm */ 
  //printf("*******sortArray is done!\n");
  printArray(fout,array,count); /* print the array to output file */
  freeAll(array,count);        /* free all heap memory. Check with valgrind*/  
  return EXIT_SUCCESS; 
} 



