/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/25 20:06:06 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     init(int *conf)
{
    int i;
    
    i = 0;
    while (i < 8)
    {
        conf[i] = 0;
        ++i;
    }
    conf[i] = NULL;
}

static int  which(char **sep, t_conf *conf, int *all_c)
{
    if (ft_strcmp(*sep, "SO") == 0)
        return (text(sep, conf->SO, all_c, 1));
    else if (ft_strcmp(*sep, "WE") == 0)
        return (text(sep, conf->WE, all_c, 2));
    else if (ft_strcmp(*sep, "EA") == 0)
        return (text(sep, conf->EA, all_c, 3));
    else if (ft_strcmp(*sep, "NO") == 0)
        return (text(sep, conf->NO, all_c, 4));
    else if (ft_strcmp(*sep, "R") == 0)
        return (res(sep, conf->resol, all_c, 0));
    else if (ft_strcmp(*sep, "S") == 0)
        return (text(sep, conf->split, all_c, 5));
    else if (ft_strcmp(*sep, "F") == 0)
        return (color(sep, conf->F, *all_c, 6));
    else if (ft_strcmp(*sep, "C") == 0)
        return (color(sep, conf->C, all_c, 7));
    else
        return (clear(sep, -1));
}

int     check_line(char *line, t_conf *conf, int *all_c)
{
    char **sep;

    if (line == "")
        return (0);
    else
    {
        if ((sep = ft_split(line, ' ')) == NULL)
            return (clear(sep, -1));
        else
            return (which(sep, conf, all_c));
    }
}

int     check_conf(int fd, char **line, t_conf *conf)
{
    int *check;
    int ret;
    
    init(check);
    while ((ret = get_next_line(fd, line)) != 0 && all_good(check) == 0)
    {
        if ((check_line(*line, conf, check) == -1) || (ret == -1))
            return (-1);
        free(line);
    }
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
    if (check_conf(fd, &line, conf) == -1 || check_map(fd, &line, map) == -1)
        return (-1);
    return (1);
}

/*

int    get_out(int fd, int ret)
{
    close(fd);
    return(ret);
}

int         check_conf(int fd, char **line)
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