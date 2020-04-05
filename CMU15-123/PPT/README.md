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

Example 3: This example shows how to pass the address of a `char** ` to double the size of an array of length n.

```C
char** s = NULL; 
/* this does not allocates memory for the array of strings */

allocate(&s,n); 
/* allocate as defined in example 2. Now this allocates an array of n char’*s */

doubleArray(&s, n); 
/*call the function to double the size of the array */

int doubleArray(char*** ptr, int n){ 
    if ((*ptr=malloc(2*n*sizeof(char*))) != NULL) 
        return 0;
    return 1; 
}
```

Example 4:A function matrixAllocate that takes two integers, m and n and allocate an m by n block of memory.

```C
int matrixAllocate(int*** Mptr, int n, int m){ 
    *Mptr = (int**)malloc(m*sizeof(int*)); 
    int i=0; 
    for (i=0;i<m;i++) 
        (*Mptr)[i] = malloc(n*sizeof(int)); 
}
```

##### Run time errors
|Index|Reasons|
|-|-|
|A| dereference of uninitialized or otherwise invalid pointer|
|B| insufficient (or none) allocated storage for operation|
|C| storage used after free|
|D| allocation freed repeatedly|
|E| free of unallocated or potentially storage|
|F| free of stack space|
|G| return, directly or via argument, of pointer to local variable H) dereference of wrong type|
|I| assignment of incompatible types|
|J| program logic confuses pointer and referenced type|
|K| incorrect use of pointer arithmetic|
|L| array index out of bounds|

##### Memory Copy
`memcpy(void *dest,void *src,size_t n)`:The `memcpy( )` function copies n bytes from memory area src to memory area dest.**The memory areas should not overlap.**

`memmove(void *dest,void *src,size_t n)`:The `memmove( )` function copies n bytes from memory area src to memory area dest.**The memory areas can overlap.**

Example:
A:
|1|2|3|4|5|6|
|-|-|-|-|-|-|
`memmove(A+1,A,4*sizeof(int))`
|1|1|2|3|4|6|
|-|-|-|-|-|-|

### Recitation
`./a.out`:This command says to look in the current directory (.) and run a.out. Normally the system doesn't look in the current directory for executable programs unless you have "." in your PATH.




