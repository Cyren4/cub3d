#include "includes/cub3d.h"

int ft_color_value(char *line, int i)
    {
    int color;

    color = 0;
    while (is_whitespace(line[i]))
        i++;
    if (ft_isdigit(line[i]))
        color = ft_atoi(&line[i]);
    i += ft_intlen(color);
    if (check_value(color) == 1)
        return (-1);
    return (color);
}

void ft_set_color(char *line, int i, t_data *data)
{
        int rgb;
        int r;
        int g;
        int b;

        r = 0;
        g = 0;
        b = 0;

        while (is_whitespace(line[i]))
            i++;
        if (line[i] == 'C')
        {
            r = ft_color_value(line, i);
            g = ft_color_value(line, i);
            b = ft_color_value(line, i);
            if (r == -1 || g == -1 || b == -1)
                return(-1);//set le retour d'erreur
            data->win.ceiling_color = get_rgb(rgb, r, g, b);
            data->set_infos += 1;
        }
        if (line[i] == 'F')
        {
            r = ft_color_value(line, i);
            g = ft_color_value(line, i);
            b = ft_color_value(line, i);
            if (r == -1 || g == -1 || b == -1)
                return(-1);//set le retour d'erreur
            data->win.floor_color = ft_get_color(line, i, 'F');
            data->set_infos += 1;
        }      
}
int check_value(int c)
{
    if (c < 0 || c > 255) 
        return (0);
    return (1);
}

int get_rgb(int rgb, int *r, int *g, int *b)
{
    rgb = r;
    rgb = rgb << 8 + g;
    rgb = rgb << 8 + b;
    return (rgb);
}