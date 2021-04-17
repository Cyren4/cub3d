#include "includes/cub3d.h"

void ft_resolution(char *str, t_data *data)
{
    if (is_whitespace(str[i]))
        i++;
    if (ft_isdigit(str[i]))
        data->axe_x = ft_atoi(str[i]);
    if (is_whitespace(str[i]))
        i++;
    if (ft_isdigit(str[i]))
        (data->axe_y = ft_atoi(str[i]));
    }/*retourner une erreur si la résolution est égale à 0*/
}

void ft_color(char *str, t_data *data)
{
    /*faire comme le vrai atoi zapper les whitespaces*/

        while (is_whitespace(str[i])
            i++;
        if (str[i] == 'C')
        {
             if (ft_isdigit(str[i]))
                    data->c = ft_atoi(str[i]);
        }
        if (str[i] == 'F')
        {
            if (ft_isdigit(str[i]))
                data->f = ft_atoi(str[i]);
        }
}
