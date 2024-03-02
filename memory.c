#include "NEW_shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
    /* Check if the pointer is not NULL and if it points to a valid memory location */
	if (ptr && *ptr)
	{
        /* Free the memory pointed to by the pointer */
		free(*ptr);
        /* Set the pointer to NULL to avoid dangling pointers */
		*ptr = NULL;
        /* Return 1 to indicate successful memory deallocation */
		return (1);
	}
    /* Return 0 if the pointer is already NULL or invalid */
	return (0);
}
