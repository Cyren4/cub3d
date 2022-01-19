#include "cub3d.h"


void parse_infos(t_data *d)
{
    int i;

    i = 0;
    while(d->file[i])
    {
        while(is_whitespace(d->file[i]))
            i++;
        if (d->file[i] == "F")
        {
            get_color(d->file[i + 1], d->floor);
            d->infos++;
        }
        if (d->file[i] == "C")
        {
            get_color(d->file[i + 1], d->ceiling);
            d->infos++;
        }
        if (ft_strncmp(d->file[i], "NO", 2)
            //get_textures()
        i++;
    }
}

/*check_map*/
    //wrong charactr
    //open map
    //

/*