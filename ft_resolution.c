#include "includes/cub3d.h"

void ft_resolution(char *str, t_data *data)
{
    int i;

    i = 0;
        while (str[i])
        {
            while(is_whitespace(str[i]))
                i++;
            if (ft_isdigit(str[i]))
            {
                if (data->win.height == 0)
                {
                    data->win.height = ft_atoi(str[i]);
                    i += ft_intlen(data->win.height);
                }
                else
                {
                    (data->win.width = ft_atoi(str[i]));
                    i += ft_intlen(data->win.width);
                }
            }
        }
    }
}

