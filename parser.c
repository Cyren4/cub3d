#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, t_data *data)
{
    int     ret;
    int     fd;
    char    *line;

    /*utiliser get_next_line pour lire les infos du fichier.cub*/
    ret = 1;
    str = NULL;

    if (!ft_check_cub(fichier, data) != 1)
        return (ERROR_FORMAT); //faire un strjoin pour indiquer
    if (fd = open(fichier, O_DIRECTORY) != -1)
        return (ERROR_FORMAT);
    if (fd = open(fichier, O_READONLY) == -1)
        return (OPENING_ERROR);
    while (get_next_line(fd, &line))
    while (is_whitespaces(str[i])
        i++;
    ft_parse_infos(line, data);
    ft_parse_map(line, data);
    }
    close(fd);
    free(str);

}

int ft_check_cub(*str, t_data *data)
{
    while(str[i] != '.')
        i++;
    if (str[i + 1] != 'c'&& str[i + 2] != 'u' && str[i + 3] != 'b')
        return (ERROR);
}

