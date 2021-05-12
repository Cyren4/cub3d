#include "includes/cub3d.h"

void ft_set_resolution(char **infos, int i, t_data *data)
{
    i += 1;
        while (*infos[i])
        {
            while(is_whitespace(*infos[i]))
                i++;
            if (ft_isdigit(*infos[i]))
            {
                if (data->win.height == 0)
                {
                    data->win.height = ft_atoi(&*infos[i]);
                    i += ft_intlen(data->win.height);
                    data->set_infos += 1;
                }
                else
                {
                    (data->win.width = ft_atoi(&*infos[i]));
                    i += ft_intlen(data->win.width);
                    data->set_infos += 1;
                }
            }
        }
}

