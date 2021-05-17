#include "includes/cub3d.h"
char    **get_file(int fd, int lvl)
{
    char *line;
    char **infos;

    line = NULL;
    if (get_next_line(fd, &line) == 1)
        infos = get_file(fd, lvl + 1);
    else
    {
        infos = malloc(sizeof(char*) * (lvl + 2));
        infos[lvl + 1] = NULL;
        infos[lvl] = line;
        return (infos);
    }
    infos[lvl] = line;
    return (infos);
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