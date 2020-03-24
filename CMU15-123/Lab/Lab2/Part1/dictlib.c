/**
 *  dictlib.c for lab2
 */

#include "dictlib.h"

/* This function takes the current array and double the array size.. 
   Note that we are dealing with ***'s.    
*/
int resize(char ***ptr, int *nptr)
{
  char **temp = calloc(*nptr * 2, sizeof(char *));
  for (int i = 0; i < *nptr; ++i)
  {
    temp[i]=*(*ptr+i);
  }
  (*nptr)*=2;
  ptr=&temp;
  return EXIT_SUCCESS;
}

/* 
   This function inserts the word to array[index].
   Must allocate memory to hold the word
*/

int insertWord(char **array, char *word, int cap, int index)
{

 // printf("%s\n",word);
  if(index<0||index>=cap||array==NULL||word==NULL)
    return EXIT_FAILURE;
  array[index]=calloc(strlen(word)+1, sizeof(char));
  for(int i=0;i<strlen(word);++i)
    array[index][i]=word[i];
  array[index][strlen(word)]=0;
  return EXIT_SUCCESS;
}

/* 
  This function sorts the sub array using a simple sorting
  algorithm. Low is the beginning index of the array and
  high is the upper index of the array.
  to sort the entire array of length n we call: sortArray(A,0,n-1)
*/

int sortArray(char **array, int low, int high)
{
  for(int i=low+1;i<=high;++i)
  {
    int pos=binarysearch(array,array[i],low,i-1);
    // printf("i=%d,pos=%d  %s\n",i,pos,array[i]);
    char*temp=calloc(strlen(array[i])+1,sizeof(char));
    memcpy(temp,array[i],strlen(array[i])+1);
    // printf("@@@@@@@%s\n",temp);
    // printf("before:\n");
    // for(int m=low;m<i;++m)
    // {
    //   printf("%s%s",array[m],m==i-1?"\n":"    ");
    // }
    int j=i;
    
    while(j>pos)
    {
      // printf("***%s  %s\n",array[j],array[j-1]);
      memcpy(array[j],array[j-1],sizeof(*array));

      j--;
    }
    // printf("@@@@@@@%s\n",temp);
    memcpy(array[j],temp,sizeof(*array));
    free(temp);
    // printf("after:\n");
    // for(int m=low;m<=i;++m)
    // {
    //   printf("%s %s",array[m],m==i?"\n":"      ");
    // }
  }

  return EXIT_SUCCESS;
}

/* 
   This function frees all dynamic memory allocated.
   Program will be tested with valgrind                                                                                    
*/

void freeAll(char **array, int count)
{

}

/* print the array and all its entries into outfile.
   Separate words by a space.
 */

void printArray(FILE *fout, char **array, int count)
{
}

/* This function finds the place to insert the element. It must return
   the place to insert between low and high. Error conditions will
   return -1   
*/

int binarysearch(char **array, char *word, int low, int high)
{
  if(word==NULL||array==NULL||*array==NULL||low>high)
    return -1;
  int middle=0;
  while(low<=high)
  {

    middle=low+(high-low)/2;
    if(strcmp(word,array[middle])>0)
      low=middle+1;
    else if(strcmp(word,array[middle])<0)
      high=middle-1;
    else if(strcmp(word,array[middle])==0)
      return middle;
  }
  return low;
}
