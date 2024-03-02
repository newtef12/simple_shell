#include "NEW_shell.h"

/* 
 * Implementation of memory-related functions.
 */

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    // Loop through the memory area and fill it with the specified byte
    for (i = 0; i < n; i++)
        s[i] = b;
    return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    char **a = pp;

    // Check if the pointer to the array of strings is not NULL
    if (!pp)
        return;

    // Free each string in the array
    while (*pp)
        free(*pp++);

    // Free the array itself
    free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    // If the pointer is NULL, simply allocate memory for the new size
    if (!ptr)
        return (malloc(new_size));

    // If the new size is zero, free the memory and return NULL
    if (!new_size)
        return (free(ptr), NULL);

    // If the old size is equal to the new size, return the pointer
    if (new_size == old_size)
        return (ptr);

    // Allocate memory for the new size
    p = malloc(new_size);
    if (!p)
        return (NULL);

    // Copy contents from the old block to the new block
    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];
    free(ptr);
    return (p);
}
