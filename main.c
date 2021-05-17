#include "includes/cub3d.h"

int main(int ac, char **argv)
{
    int     fd;
    t_data  data;
    int     lvl;
    char    **infos;
    int i;

    if (ac < 2)
    {
        printf("Error\nconfiguration file's missing");
        return (NO_CONFIG_FILE);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nwhile opening file");
        return (OPENING_ERROR);     
    }
    
    infos = get_file(fd, 0);
    /*while (infos[i])
    {
        printf("%d - %s\n", i, infos[i]);
        i++;
    }*/
    parse_infos(infos, &data);
    close(fd);
    free(infos);
    return (0);
}