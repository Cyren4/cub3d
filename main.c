#include "includes/cub3d.h"

int main(int ac, char **argv)
{
    int fd;
    t_data *data;
    
    if (ac < 1)
        return (NO_CONFIG_FILE);
    if ((fd = open(argv[1], O_RDONLY) == -1))
    {
        return (OPENING_ERROR);
        printf("Error\nwhile opening file");
    }
    ft_parser(argv[1],fd);
}