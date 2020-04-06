/*
Skills Lab 5 - 
Due: 02-11-11
What to do: Compile and run the program
1. gcc -Wall -pedantic -ggdb SL5.c -o SL5
   
   First remove all warnings.
   Then  run with
   >./SL5 datafile    
   --- test with 105-data.txt first, then
   --- test with data files from /afs/andrew/course/15/123/datafiles
   --- since printing takes time for large data files, you might want to
       comment out printing parts for large files. 

  The purpose of this program is to understand how to defining, allocating 
  and deallocating memory for structs. We will discuss linked list concept
  in class on thursday. In this lab, we will learn how to allocate memory
  for an array of structs and array of struct*'s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* a slightly differnt way to use a typedef*/
typedef struct node
{
    char *word;
    int count;
} node;

int main(int argc, char *argv[])
{
    /* define an array of node's */
    node A[1000];
    int size = 105;
    /* write the code to read the word file 105-data.txt to the array 
     be sure to allocate the memory for words. size is the size of the data
     file. Leave the count field in the Node as zero.
  */
    int index=0;
    FILE*f=fopen("data.txt","r");
    char words[100];
    while(fscanf(f,"%s",words)!=EOF)
    {
        A[index].word=malloc(sizeof(char)*(strlen(words)+1));
        strcpy(A[index].word,words);
        index++;
    }
    for (int i = 0; i < size; i++)
        printf("%s ", A[i].word);
    printf("\n");
    /* define an array of node*'s */

    while(index--)
    {
        free(A[index].word);
       // printf("%d ",index);
    }

    printf("Finish Part I\n");
    node *B[1000];
    /* write the code to read the word file 105-data.txt to the array                     
     be sure to allocate the memory for structs and words. size is the size of the 
     data file. Leave the count field in the Node as zero. 
  */

    f=fopen("data.txt","r");
    index=0;
    
    while(fscanf(f,"%s",words)!=EOF)
    {
        B[index]=malloc(sizeof(node));
        B[index]->word=malloc(sizeof(char)*(strlen(words)+1));
        strcpy(B[index]->word,words);
        index++;
    }
    for (int i = 0; i < size; i++)
        printf("%s ", B[i]->word);
    printf("\n");

    /* write the code to read a data file (test.txt) that contains
     two fields word(string) count(int). Free the memory allocated for
     array A and read words and counts from text.txt to A. 
  */
    f=fopen("test.txt","r");
    int cnt=0;
    index=0;
    while(fscanf(f,"%s %d",words,&cnt)!=EOF)
    {
        A[index].word=malloc(sizeof(char)*(strlen(words+1)));
        strcpy(A[index].word,words);
        A[index].count=cnt;
        index++;
    }

    size=5;
    for (int i = 0; i < size; i++)
        printf("%s %d\n", A[i].word,A[i].count);
    printf("\n");
    return EXIT_SUCCESS;
}
