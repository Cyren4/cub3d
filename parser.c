#include "includes/cub3d.h"
#define ERROR "Error/n"
/*faire un tableau de char à double entrée pour y mettre les coordonnées */
int ft_parser(char *fichier, t_data *data)
{
    int ret;
    int fd;
    char *str;

    /*utiliser get_next_line pour lire les infos du fichier.cub*/
    ret = 1;
    str = NULL;

    if (fd = open(fichier, O_DIRECTORY) != -1;
    {
        printf("erreur ceci est un dossier");
        return (ERROR);
    }
    if (fd = open(fichier, O_READONLY) == -1;
    {
        printf("Une erreur est survenue à l'ouverture du fichier");
        return (ERROR);
    }
    /*si on arrive jusqu'ici c'est qu'il n'y a pas eu d'erreur à l'ouverture*/
    while (ret != 0)
    {
        ret = get_next_line(fd, &str, data);
        /*récupérer les infos sur la résolution*/
        ft_resolution

}

