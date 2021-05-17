#include "includes/cub3d.h"

int ft_color_value(char *infos, int i)
{
    int color;

    color = 0;
    while (is_whitespace(infos[i]))
        i++;
    if (ft_isdigit(infos[i]))
    {
        color = ft_atoi(&infos[i]);
        if (color > 9)
		    i += (ft_intlen(color) - 1);    
    }
    printf("%d\n", color);
    if (check_value(color) == 0)
        return (-1);
    return (color);
}

int ft_set_color(char **infos, int i, t_data *data)
{
        int rgb;
        int r;
        int g;
        int b;

        r = 0;
        g = 0;
        b = 0;

        if (*infos[i] == 'C')
        {
            i++;
            r = ft_color_value(*infos, i);
            g = ft_color_value(*infos, i);
            b = ft_color_value(*infos, i);
            if (r == -1 || g == -1 || b == -1)
                    return(-1);//set le retour d'erreur
            data->win.ceiling_color = get_rgb(rgb, r, g, b);
            printf("C = %d\n", rgb);
            data->set_infos += 1;
        }
        if (*infos[i] == 'F')
        {
            i++;
            while (is_whitespace(*infos[i]))
                    i++;
            r = ft_color_value(*infos, i);
            printf("r = %d\n", r);
            g = ft_color_value(*infos, i);
            printf("g = %d\n", g);
            b = ft_color_value(*infos, i);
            printf("b = %d\n", b);
            if (r == -1 || g == -1 || b == -1)
                return(-1);//set le retour d'erreur
            data->win.floor_color = get_rgb(rgb, r, g, b);
            printf("F = %d\n", rgb);
            data->set_infos += 1;
        }
    return (0);      
}
int check_value(int c)
{
    if (c < 0 || c > 255) 
        return (0);
    return (1);
}

int get_rgb(int rgb, int r, int g, int b)
{
    rgb = r;
    rgb = rgb << (8 + g);
    rgb = rgb << (8 + b);
    return (rgb);
}