/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/25 15:00:08 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     init(int *conf)
{
    int i;
    
    i = 0;
    conf[8] = NULL;
    while (i < 8 && conf[i] != NULL)
    {
        conf[i] = 0;
        ++i;
    }
}

static int      all_good(int *conf)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (conf[i] != 1)
            return (0);
        ++i;
    }
    return (1);
}

int     check_conf(int fd, char **line, t_conf *conf)
{
    int *check;
    int ret;
    
    init(check);
    while ((ret = get_next_line(fd, line)) != 0 && all_conf(conf, check) == 0)
    {
        if ((check_line(*line, conf) == -1) || (ret == -1))
            return (-1);
    }
    if ((check_line(*line, conf) == -1) || (ret == -1))
            return (-1);
    if (all_conf(conf, check) == 1)
        return (1);
    else
        return (0);
}
int     check_cub(char *av, t_conf *conf, t_map *map)
{
    char *line;
    int fd;
    int ret;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        return (-1);
    if (check_conf(fd, &line, conf) == -1)
        return (-1);
    if (check_map(line, conf) == -1)
        return (-1);
    return (1);
}

/*int         check_conf(int fd, char **line)
{
    int check_conf[9];
    int ret;
    t_conf *conf;

    init(check_conf);
    while (((ret = get_next_line(fd, line)) > 0) && all_good(check_conf) != 1)
    {
        if (check_line(*line, conf) == -1)
            return (-1);
        else if (check_line(*line, conf) == 1)
            get_conf(*line, conf);
    }
    if (all_good(check_conf) != 1)
        write(1, "Error\nconfig is missing", 24);
    free(check_conf);
    return (all_good(check_conf));
}

typedef struct  s_map
{
    char **map;
    ma

}               t_map;

int     check_line(char *line, t_map *map)
{}

int     check_map(int fd, char *line)
{
    t_map *map;

    while (get_next_line(fd, &line) > 0)
    {
        if (check_line(line) == 1)
        else if (check_line(line) == -1)
            return
    }

}*/