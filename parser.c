#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, t_data *data)
{
    int     lvl;
    int     fd;
    char    *line;

   
    line = NULL;
    if (ft_check_extension(fichier, ".cub") != 1)
        return (ERROR_FORMAT);
    /*trouver comment detecter que c'est un dossier*/
    if (fd = open(fichier, O_RDONLY) == -1)
        return (OPENING_ERROR);
    
    /*while (get_next_line(fd, &line))
    {
        ft_parse_infos(&line, data);
        if (ft_parse_infos == 1)
            ft_fill_map(&line, data);
    }*/
    close(fd);
    free(line);
}

int parse_infos(char *line, int i, t_data *data)
{
    while (data->set_infos < 4)
    {    
        while (is_whitespaces(line[i]))
            i++;
        if (line[i] == 'R')
            ft_set_resolution(line, i, data);
        if (line[i] == 'C' || line[i] == 'F')
            ft_set_color(line, i, data);
        //if (ft_check_error == -1)
        //  return (0);
        if (data->set_infos != 3)
            return (MISSING_INFOS);
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

