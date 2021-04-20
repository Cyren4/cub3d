#include "includes/cub3d.h"

void ft_set_resolution(char *line, int i, t_data *data)
{
    i += 1;
        while (line[i])
        {
            while(is_whitespace(line[i]))
                i++;
            if (ft_isdigit(line[i]))
            {
                if (data->win.height == 0)
                {
                    data->win.height = ft_atoi(&line[i]);
                    i += ft_intlen(data->win.height);
                }
                else
                {
                    (data->win.width = ft_atoi(&line[i]));
                    i += ft_intlen(data->win.width);
                }
            }
        }
}

