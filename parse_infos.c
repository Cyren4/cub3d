#include "includes/cub3d.h"

int parse_infos(char *line, int i, t_data *data)
{
    while (data->win.set_infos < 4)
    {    
        while (is_whitespaces(line[i]))
            i++;
        if (line[i] == 'R')
            ft_set_resolution(line, i, data);
        if (line[i] == 'C' || line[i] == 'F')
            ft_set_color(line, i, data);
        //if (ft_check_error == -1)
        //  return (0);
        return (1);
    }
}


//int     ft_check_error()