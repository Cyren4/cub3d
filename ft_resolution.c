#include "includes/cub3d.h"

void ft_resolution(char *str, t_data *data)
{
    if (str[data->i] == 'R')
    {
        while(str[i++] == ' ')/*faire comme le vrai atoi zapper les whitespaces*/
            if (ft_isdigit(str[data->i]))
            {
                if (data->axe_x == 0)
                    data->axe_x = ft_atoi(str[data->i]);
                else
                    (data->axe_y = ft_atoi(str[data->i]));
            }
    }/*retourner une erreur si la résolution est égale à 0*/
}

void ft_color(char *str, t_data *data)
{
    /*faire comme le vrai atoi zapper les whitespaces*/

        if (str[data->i] == 'C')
        {
            while (str[data->i++])
            {
                if (ft_isdigit(str[data->i]))
                    data->c = ft_atoi(str[data->i]);
            }
        }
        if (str[data->i] == 'F')
        {
            while (str[data->i++])
            {
              if (ft_isdigit(str[data->i]))
                data->f = ft_atoi(str[data->i]);
            }
        }
}

int ft_check_map(char *str, t_data *data)
{
    int i;

    i = 0;
    while (str[i++] == '\0')
    {
        /*checker si la map existe*/
        /*checker s'il y a autre chose que 1, 0, N, S, W*/ 
        /*checker si elle est bien fermée*/
    



}