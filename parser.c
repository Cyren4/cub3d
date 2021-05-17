#include "includes/cub3d.h"

int parse_infos(char **infos, t_data *data)
{
    int i;

    i = 0;
    
    while (data->set_infos < 4)
    {    
        while (is_whitespace(*infos[i]))
            i++;
        if (*infos[i] == 'R')
        {
            ft_set_resolution(infos, i, data);
            printf("2 = %d", i);
        }
        if (*infos[i] == 'C'|| *infos[i] == 'F')
            ft_set_color(infos, i, data);
        if (data->set_infos != 3)
        {
            return (MISSING_INFOS);
            printf("Error\nmissing infos");
        }   
    }
    return (1);
}

int ft_check_extension(char *str, char *ext)
{
    while(*str != '.')
        str++;
    if (ft_strcmp(str, ext) == 0)
        return (1);
    return (WRONG_EXTENSION);
}

int is_whitespace(char c)
{
    if (((c >= 9) && (c <= 13))|| c == 32)
        return(1);
    return (0);
}