#include "includes/cub3d.h"

/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, t_data *data)
{
    int     ret;
    int     fd;
    char    *line;
    int i;

    ret = 1;
    line = NULL;
    i = 0;

    if (ft_check_cub(fichier, data) != 1)
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
            ft_parse_map(line, &i, data);
    }
    close(fd);
    free(line);
}

int ft_check_cub(char *str, t_data *data)
{
    while(str[i] != '.')
        i++;
    if (str[i + 1] != 'c'&& str[i + 2] != 'u' && str[i + 3] != 'b')
        return (-1);//définir le retour d'erreur
}

