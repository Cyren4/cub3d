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

    if (fd = open(fichier, O_DIRECTORY) != -1)
    {
        printf("Erreur: ceci est un dossier");
        return (ERROR);
    }
    if (fd = open(fichier, O_READONLY) == -1)
    {
        printf("Une erreur est survenue à l'ouverture du fichier");
        return (ERROR);
    }
    while (get_next_line(fd, &line);
        /*récupérer les infos sur la résolution*/
        while (is_whitespaces(str[i])
            i++;
        
        /*ft_check_NSEW*/
        ft_check_map(str, data);
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

