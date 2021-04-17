/*int ft_check_map(char *str, t_data *data)
{
    while (str[i++] != '\0')
    {
        if (str[i] != 0 || str[i] != 1 || str[i] != 2 || str[data->i != 'N' || str[i] != 'S' || str[i] != 'W' || str[i] != 'E')
            return (0);
        return (1);
    }*/

        /*checker si la map existe*/
        /*checker si elle est bien fermée*/
    
int ft_copy_map(char *str, t_data *data)
{
     char **map;
     int x;
     int y;

     x = 0;
     y = 0;

     while (str[i])
     {
         map[y] = ft_strdup(str);
         y++;
     }
    
}