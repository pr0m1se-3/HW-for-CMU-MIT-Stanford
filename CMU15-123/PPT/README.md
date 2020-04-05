### Lecture 06 Debugging Programs with GDB and memory leaks

### Lecture 07 Pointers, *, ** and ***

A pointer is an address in the memory


##### Passing a pointer to a function
Example 1: This example shows how to pass the address of a `char*` to assign a string to a location.
```C
char* s = NULL; 
/* this does not allocate memory for the string*/ 
allocate(&s, n); 
/*call the function to allocate memory of n bytes for s*/

int allocate(char** ptr, int n){ 
    if ((*ptr=malloc(n)) != NULL) 
        return 0;
    return 1; }
```
Example 2: This example shows how to pass the address of a char** to assign an array of char*’s to a location.

```C
char** s = NULL;
/* this does not allocate memory for the array of strings */ 
 allocate(&s, n);
/*call the function to allocate memory of for an array of char*’s */

int allocate(char*** ptr, int n){ 
    if ((*ptr=malloc(n*sizeof(char*))) != NULL) 
        return 0;
    return 1; 
}
```


