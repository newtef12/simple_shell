#include "NEW_shell.h"

/*
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    /* Copy characters from src to dest up to n - 1 characters */
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }
    /* If i < n, fill remaining characters of dest with null terminators */
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);
}

/*
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    /* Move to the end of dest */
    while (dest[i] != '\0')
        i++;
    /* Append characters from src to dest up to n characters */
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    /* If j < n, append null terminator to dest */
    if (j < n)
        dest[i] = '\0';
    return (s);
}

/*
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
    /* Search for the character c in the string s */
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}
