#include "NEW_shell.h"

/**
 * is_cmd - Determines if a file is an executable command.
 * @info: Pointer to the info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    /* Ignore the info parameter */
    (void)info;

    /* Check if the path is NULL or if stat fails */
    if (!path || stat(path, &st))
        return (0);

    /* Check if the file is a regular file */
    if (st.st_mode & S_IFREG)
        return (1);

    return (0);
}

/**
 * dup_chars - Duplicates characters from a string.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    /* Copy characters from start to stop, excluding ':' */
    for (k = 0, i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];

    buf[k] = '\0';
    return (buf);
}

/**
 * find_path - Finds the specified command in the PATH string.
 * @info: Pointer to the info struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Return: Full path of cmd if found, otherwise NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    /* If pathstr is NULL, return NULL */
    if (!pathstr)
        return (NULL);

    /* Check if cmd starts with "./" and is a valid command */
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }

    /* Iterate through the PATH string */
    while (1)
    {
        /* Check for path delimiter or end of string */
        if (!pathstr[i] || pathstr[i] == ':')
        {
            /* Duplicate characters from curr_pos to i */
            path = dup_chars(pathstr, curr_pos, i);

            /* If path is empty, concatenate cmd */
            if (!*path)
                _strcat(path, cmd);
            else
            {
                /* Otherwise, concatenate "/" and cmd */
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            /* Check if the resulting path is a valid command */
            if (is_cmd(info, path))
                return (path);

            /* If end of string, break the loop */
            if (!pathstr[i])
                break;

            /* Update the current position */
            curr_pos = i;
        }

        /* Move to the next character */
        i++;
    }

    return (NULL);
}
