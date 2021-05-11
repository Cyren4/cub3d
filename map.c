#include "includes/cub3d.h"

int ft_check_map(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {        
        if (line[i] != 0 || line[i] != 1 || line[i] != 2 
            || line[i] != 'N' || line[i] != 'S' 
            || line[i] != 'W' || line[i] != 'E')
            return (WRONG_CHARACTER);
        return (1);}
    }

        /*checker si la map existe*/
        /*checker si elle est bien fermée*/
int ft_player_position(char **map, t_data *data)//sinon faire un strchr dans *line pour chaque lettre
{
    int *i;

    i = 0;
    while (map[*i])
    {
        if (map[*i] == 'N')
        {
            data->player = 'N';
            return (&i);
        }
        if (map[*i] == 'S')
        {
            data->player = 'S';
            return (&i);
        }
        if (map[*i] == 'W')
        {
            data->player = 'W';
            return (&i);
        }
        if (map[*i] == 'E')
        {
            data->player = 'E';
            return (&i);
        }
        i++;
        return (MISSING_PLAYER);
    }    
}
int ft_fill_map(char *line, t_data *data)
{
     /*copier la map dans un tableau à double entrée*/
     char **map;
     int x;
     int y;
     int i;

     x = 0;
     y = 0;

     while (line[i])
     {
        if (ft_check_map != WRONG_CHARACTER)
        {
            //calculer la taille de mon tableau à double entrée
            map[y] = ft_strdup(line);
            y++;
        }
        else
            printf("Error\n map is not properly defined.");
     }
     return (map);
}

void ft_flood_fill()

