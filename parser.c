#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, int fd)
{
    int     lvl;
    char    **infos;
    int     i;

   
    infos = NULL;
    if (ft_check_extension(fichier, ".cub") != 1)
        return (ERROR_FORMAT);
    /*trouver comment detecter que c'est un dossier*/

    infos = get_file(fd, 0);
    while (infos[i++])
    {
        printf("%d - %s\n", i, infos[i]);
        free(infos[i]);
    }
    close(fd);
    free(infos);
    return (0);
}

int parse_infos(char **infos, t_data *data)
{
    int i;

    i = 0;
    while (data->set_infos < 4)
    {    
        while (is_whitespaces(*infos[i]))
            i++;
        if (*infos[i] == 'R')
            ft_set_resolution(infos, i, data);
        if (*infos[i] == 'C' || *infos[i] == 'F')
            ft_set_color(infos, i, data);
        if (data->set_infos != 3)
        {
            return (MISSING_INFOS);
            printf("Error\nmissing infos");
        }
        
    }
    return (1);
}

int ft_check_extension(char *str, char *ext)
{
    while(*str != '.')
        str++;
    if (ft_strcmp(str, ext) == 0)
        return (1);
    return (WRONG_EXTENSION);
}

int is_whitespace(char c)
{
    if (((c >= 9) && (c <= 13))|| c == 32)
        return(1);
    return (0);
}