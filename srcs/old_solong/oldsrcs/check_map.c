/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:36:32 by cramdani          #+#    #+#             */
/*   Updated: 2020/06/21 14:56:04 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     show_map(t_map *map)
{
    int j = 0;
    while (map->map[j] != NULL)
    {
        printf("|%s|\n", map->map[j]);
        j++;
    }
}

static int      valid_char(char *c, t_map *map)
{
    if (*c == 'S')
        map->start++;
    else if (*c == ' ')
        *c = '1';
    if (!(*c == ' ' || *c == '0' || *c == '1' || *c == '2' || *c == 'S'))
    {
        map->valid = 1;
        return (1);
    }
    return (-1);

}

static int     error_map(t_map *map, int line)
{
    if (map->valid == -1)
        write(1, "Error\nError getting the map.\n", 30);
    if (map->valid == 0)
        write(1, "Error\nInvalid character in map.\n", 33);
    if (map->start > 1)
        write(1, "Error\nDuplicate start point.\n", 30);
    return (-1);
}

int     new_line(char *line, t_map *map, int nb_line)
{
    int i;

    i = 0;
    if (!(map->map[nb_line] = malloc(sizeof(char) * (ft_strlen(line) + 1))))
        return (-1);
    while (line && line[i] != 0)
    {
        if (valid_char(&line[i], map) == 0 || map->start > 1)
            return (error_map(map, ++i));
        map->map[nb_line][i] = line[i] == ' '? '1' : line[i];
        ++i;
    }
    map->map[nb_line][i] = '\0';
    map->map[nb_line + 1] = NULL;
    return (1);
}

char    **get_map(int fd, char **line, t_map *map)
{
    int ret;
    int i;

    i = 1;
    if (!(map->map = malloc(sizeof(char*) * (map->height + 1))))
        return (NULL);
    map->map[0] = strdup(*line);
    map->map[i] = NULL;
    while ((ret = get_next_line(fd, line)) != 0)
     {  
        if (ft_strcmp(*line, "") == 0)
        {
            map->map[i] = NULL;
            return (map->map);
        }
        if (ret == -1 || (map->map[i] = strdup(*line)) == NULL)
        {
            clean(map->map);
            return (NULL);
        }
        map->map[++i] = NULL;
    }
    map->map[i] = strdup(*line);
    map->map[++i] = NULL;
    return (map->map);
}

int     validMap(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j] != '\0')
        {
            if ((i == 0 || map->map[i + 1] == NULL || j == 0)\
            && (map->map[i][j] != '1' && map->map[i][j] != ' '))
            {
                printf("not closed");
                return (-1);
            }
            else if (map->map[i][j] != '1')
            j++;
        }
        i++;
    }
    return (1);
}

int     check_map(int fd, char **line, t_map *map)
{
    int ret;
    int check; //0 : only valid char; 1 one starting; 2 close map; 3

    
    map->map = get_map(fd, line, map);
    if (map->map == NULL || validMap(map) != 1)
        return (error_map(map, 0));

    show_map(map);
    printf("%s", map->map[0]);
    write(1, "checkmap end\n", 14);
    return (1);
} 