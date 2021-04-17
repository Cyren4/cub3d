#include "includes/cub3d.h"

int parse_infos(char *str, t_data *data)
{
    int i;

    i = 0;
    if (str[i] == 'R')
        ft_resolution(str, data);
    if (str[i] == 'C' || str[i] == 'F')
        ft_color(str, data);
}

void ft_resolution(char *str, t_data *data)
{
    int i;

    i = 0;
    while (is_whitespace(str[i]))
        i++;
    if (ft_isdigit(str[i]))
        data->axe_x = ft_atoi(str[i]);
    while (is_whitespace(str[i]))
        i++;
    if (ft_isdigit(str[i]))
        (data->axe_y = ft_atoi(str[i]));
    if (data->x < 1 || data->y < 1)
        return (0);
    return (1);
    }/*retourner une erreur si la résolution est égale à 0*/
}

void ft_color(char *str, t_data *data)
{
    /*faire comme le vrai atoi zapper les whitespaces*/
    char **rgb;
    int r;
    int g;
    int b;

    r = 0;
    g = 1;
    b = 2;

        while (is_whitespace(str[i])
            i++;
        if (str[i] == 'C')
        {
            str = ft_strtrim(str, ' ');
            rgb = ft_split(str, ',');
            ft_get_color(rgb, t_data *data);
        }
        if (str[i] == 'F')
        {
            if (ft_isdigit(str[i]))
                data->f = ft_atoi(str[i]);
        }
}

int check_color_error(char **rgb)
{
   int i;
   int j;

   i = 0;
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) 
        return (0);
    return (1);
}

int convert_color(char *rgb, int *r, int *g, int *b)
{
    /*convertir d'héxadécimal en binaire pour 
    savoir de combien de bits on décale rgb*/
    rgb = r;
    rgb = rgb << 8 + g;
    rgb = rgb << 8 + b;
}