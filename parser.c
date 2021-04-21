#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, t_data *data)
{
    int     ret;
    int     fd;
    char    *line;

    ret = 1;
    line = NULL;
    if (ft_check_extension(fichier, "cub") != 1)
        return (ERROR_FORMAT); //faire un strjoin pour indiquer quel est le pb
    if (fd = open(fichier, O_DIRECTORY) != -1)
        return (ERROR_FORMAT);
    if (fd = open(fichier, O_READONLY) == -1)
        return (OPENING_ERROR);
    while (get_next_line(fd, &line))
    {
        ft_parse_infos(line, data);
        /*comment savoir qu'il s'agit de la map*/
        if (ft_parse_infos == 1)
            ft_fill_map(line, data);
    }
    close(fd);
    free(line);
}

int parse_infos(char *line, int i, t_data *data)
{
    while (data->win.set_infos < 4)
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

//int     ft_check_error()
int ft_check_extension(char *str, char *ext)
{
    while(*str != '.')
        str++;
    if (ft_strcmp(str, ext) == 1)
        return (1);
    return (0); //set le retour d'erreur
}

