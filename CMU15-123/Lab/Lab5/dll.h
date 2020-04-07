/** @file dll.h
 *  @brief Function delclarations for a Doubly Linked List
 *
 *  @author Ananda Gunawardena (guna)
 *
 *  @bug No known bugs
 */

#ifndef __DLL_H__
#define __DLL_H__

#define SUCCESS 0
#define FAILURE -1

/** @brief Structure for a node in the DLL
 *
 *  This structure should ONLY be used by dll functions.  User code should only
 *  use the dll_l type
 */
typedef struct DLL_NODE
{
    void *key;             /* pointer to the key for node */
    void *value;           /* pointer to the value for the node */
    struct DLL_NODE *next; /* pointer to next node */
    struct DLL_NODE *prev; /* pointer to previous node */
} dll_node;

/** @brief Structure for a doubly linked list
 *
 *  <pre>
 *  This contains the head and compare and free function pointers.
 *  The compare function must take 2 void* sized arguments and return an
 *  integer.  The return value must conform to the following spec:
 *    -If the first argument is less than the second, return < 0
 *    -If the first argument is greater than the second, return >0
 *    -If the two arguments are equal, return 0
 *	The free functions take a DLL_NODE.key and properly free the associated memory 
 *  </pre>
 */
typedef struct DLL
{
    dll_node *head;                         /* head node of the list */
    int (*cmp)(const void *, const void *); /* Compare function pointer */
    void (*free_key)(void *);               /* takes a pointer to a key and frees it*/
    void (*free_value)(void *);             /* takes a pointer to a value and frees it*/
} dll_l;

/** @brief Initializes the linked list
 *
 *  This function must be called before any other functions are called using
 *  the given dll
 *
 *  @param head Pointer to the dll to initialize
 *  @return SUCCESS(0) or FAILURE(1) code on error
 */
int dll_init_list(dll_l *head);

/** @brief Sets the free key function for the given dll
  *
  *	@param free_key	Function pointer to free_key
  *	@return SUCCESS(0) or FAILURE(1) on error
  */
int dll_set_free_key(dll_l *list, void (*free_key)(void *));

/** @brief Sets the free value function for the given dll
  *
  *	@param free_value Function pointer to free_value 
  *	@return SUCCESS or FAILURE code on error
  */
int dll_set_free_value(dll_l *list, void (*free_value)(void *));

/** @brief Sets the compare function for the given dll
 *
 *  @param sets the cmp Function pointer to compare function
 *  @return SUCCESS or error code on error
 */
int dll_set_cmp(dll_l *list, int (*cmp)(const void *, const void *));

/** @brief Inserts the given key/value pair into the DLL
 *
 *  @param list Pointer to the dll to insert into
 *  @param key The key to use
 *  @param value The value to insert
 *  @return SUCCESS or FAILURE code on error
 */
int dll_insert(dll_l *list, void *key, void *value);

/** @brief Retrieves the entry with the given key
 *
 *  @param list Pointer to the DLL to retrieve from
 *  @param key a Key to search for
 *  @param value Memory address to store the value in
 *  @return SUCCESS or FAILURE code on error
 */
int dll_retrieve(dll_l *list, void *key, void **value);

/** @brief Runs the passed function to all the values in the dll
 *
 *  This function will traverse the dll in linear order and call the 
 *  passed function on each node.
 *
 *  The function should take in two void*s.  The first will be the value of the
 *  entry.  The second should be a pointer to a struct containing any aditional
 *  arguments the function needs.  As an example, the argument
 *  pointer could point to a filename or file descriptor.
 *
 *  @param list Pointer to the DLL to traverse
 *  @param func Function to run on each 
 *  @param args Pointer to argument structure for optional arguments (or NULL)
 *  @return SUCCESS or FAILURE on error
 */
int dll_map(dll_l *list, void (*func)(void *, void *), void *args);

/** @brief Frees all the memory used by the dll nodes.
 *
 *  This function will traverse the dll in a linear fashion, calling
 *  the given function on the *value* of each node, and then frees the node.
 *  This will cause all the memory used by the value field and dll_node to be freed.
 *
 *  The function passed should expect two arguments, a pointer to the value,
 *  and a pointer to the argument structure (which is passed to the dispose
 *  function by the user).  The function will be responsible for dealing with
 *  the memory used by the value.
 *
 *  The function pointer can be NULL, in which case the node will be freed
 *  without doing anything to the value (useful if the value is interpreted as
 *  an int instead of a pointer, as there is nothing to be freed).
 *
 *  Once this function has been run the list will be empty (the list structure
 *  is still valid).
 *
 *  @param list Pointer to the dll to dispose of
 *  @param func Function to be called on each value
 *  @param args Argument structure for function
 *  @return SUCCESS or FAILURE on error
 */
int dll_dispose(dll_l *list, void (*func)(void *, void *), void *args);

/* @brief given a key delete the corresponding node
 *
 * This function will traverse the dll to find the node 
 * corresponding to the given key
 * and delete that node. Memory must be freed using free_key and free_value
 * functions.
 *
 * @param list Pointer to the DLL
 * @param key Key of the node to be deleted
 * @return SUCCESS or FAILURE on error
 */
int dll_deletenode(dll_l *list, void *key);

#endif /* __DLL_H__ */