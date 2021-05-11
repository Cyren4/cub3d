#include "includes/cub3d.h"
char    **get_file(int fd, int lvl)
{
    char *line;
    char **tab;

    if (get_next_line(fd, &line) == 1)
        tab[lvl] = *get_file(fd, lvl + 1);
    else
    {
        tab = (char**)malloc(sizeof(char*) * lvl);
        //tab[lvl] = NULL;
        return (tab);
    }
    tab[lvl] = line;
    return (tab);
}
int main(int ac, char **av)
{
    if (ac < 1)
        return (0);
    int fd = open(av[1], O_RDONLY);
    char **tab = get_file(fd, 0);
    for (int i = 0; tab[i]; i++)
        printf("%d - %s\n", i, tab[i]);
    return (0);
}