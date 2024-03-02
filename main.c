#include "NEW_shell.h"

/*
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = { INFO_INIT }; /* Initialize info_t struct */
    int fd = 2; /* Initialize file descriptor */

    /* Inline assembly to modify file descriptor */
    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd));

    /* If an argument is provided */
    if (ac == 2)
    {
        /* Open the file in read-only mode */
        fd = open(av[1], O_RDONLY);
        /* Handle file open errors */
        if (fd == -1)
        {
            if (errno == EACCES) /* Permission denied */
                exit(126);
            if (errno == ENOENT) /* No such file or directory */
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        info->readfd = fd; /* Assign file descriptor to info struct */
    }
    populate_env_list(info); /* Populate environment list */
    read_history(info); /* Read history */
    hsh(info, av); /* Execute shell */
    return (EXIT_SUCCESS);
}
