#include "includes/cub3d.h"
char    **get_file(int fd, int lvl)
{
    char *line;
    char **tab;

    if (get_next_line(fd, &line) == 1)
        tab = get_file(fd, lvl + 1);
    else
    {
        tab = malloc(sizeof(char*) * lvl);
        free(line);
        return (tab);
    }
    tab[lvl] = line;
    return (tab);
}
/*int main(int ac, char **av)
{
    
    int fd = open(av[1], O_RDONLY);
    char **tab = get_file(fd, 0);
    for (int i = 0; tab[i]; i++)
    {
        printf("%d - %s\n", i, tab[i]);
        free(tab[i]);
    }
    free(tab);
    close(fd);
    return (0);
}*/