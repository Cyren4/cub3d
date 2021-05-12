#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */

{
    int     lvl;
    char    *line;
    char    **infos;
    int     i;

   
    line = NULL;
    if (ft_check_extension(fd, ".cub") != 1)
        return (ERROR_FORMAT);
    /*trouver comment detecter que c'est un dossier*/

    infos = get_file(fd, 0);
    while (infos[i++])
    {
        printf("%d - %s\n", i, tab[i]);
        free(tab[i]);
    }
    close(fd);
    free(infos);
    return (0);
}

int parse_infos(char **infos, t_data *data)
{
    while (data->set_infos < 4)
    {    
        while (is_whitespaces(line[i]))
            i++;
        if (line[i] == 'R')
            ft_set_resolution(line, i, data);
        if (line[i] == 'C' || line[i] == 'F')
            ft_set_color(line, i, data);
        if (data->set_infos != 3)
        {
            return (MISSING_INFOS);
            printf("Error\nmissing infos");
        }
        return (1);
    }
}

int ft_check_extension(char *str, char *ext)
{
    while(*str != '.')
        str++;
    if (ft_strcmp(str, ext) == 1)
        return (1);
    return (WRONG_EXTENSION);
}

