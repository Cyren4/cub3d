#include "cub3d.h"



void get_path(int path, t_data *d, char *str)
{
    int i;

    i = 0;
    while (is_whitespace(str[i]))
        i++;
    if (path == NO)
        ft_strcpy(&str[i], d->txt.path_no);
    else if (path == SO)
        ft_strcpy(&str[i],  d->txt.path_so);
    else if (path == EA)
        ft_strcpy(&str[i], d->txt.path_ea);
    else if (path == WE)
        ft_strcpy(&str[i], d->txt.path_we);
    //il y a t-il moyen de tester un path ?
}

void parse_infos(t_data *d)
{
    int i;
    int path;
    char **directions;

    i = 0;
    directions = build_array();
    while(d->file[i])
    {
        while(is_whitespace(*d->file[i]))
            i++;
        if (!ft_strcmp(d->file[i], "F") || !ft_strcmp(d->file[i], "C"))
        {
            //get_color(d->file[i + 1], d->floor);
            d->infos++;
        }
        if (is_in_array(directions, d->file[i]) != -1)
        {
            path = is_in_array(directions, d->file[i]);
            get_path(path, d, d->file[i]);
        }
        i++;
    }
    //free_array(directions)
}


//check_map
    //wrong charactr
    //open map
    //
