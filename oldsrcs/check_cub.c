/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/06/20 16:39:30 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     show_conf(t_conf *conf)//need to be removed
{
    int i = -1;

    printf("res : |%d| |%d|\n", conf->resol[0], conf->resol[1]);
    while (++i < 5)
    {
        printf("|%d| : |%s|\n", i, conf->text[i]);
    }
    printf("floor : |%d| |%d| |%d|\n", conf->col[0][0], conf->col[0][1], conf->col[0][2]);
    printf("ceiling : |%d| |%d| |%d|\n", conf->col[1][0], conf->col[1][1], conf->col[1][2]);
}

static int     how_len(char *av)
{
    char **line;
    int ret;
    int i;
    int fd;

    fd = open(av, O_RDONLY);
    if (fd < 0)
        return (-1);
    i = 0;
    while ((ret = get_next_line(fd, line)) != -1)
    {
        free(*line);
        i++;
        if (ret == 0)
            break;
    }
    close(fd);
    return (i);
}



static void     init(int *check, t_conf *conf, t_map *map)
{
    int i;
    
    i = -1;
    while (++i < 9)
    {
        check[i] = 0;
        if (i < 5)
            conf->text[i] = NULL;
        if (i < 3)
        {
            conf->col[0][i] = 0;
            conf->col[1][i] = 0;
            if (i < 2)
                conf->resol[i] = 0;
        }
    }
    map->map = NULL;
    map->valid = 0;
    map->start = 0;
}


int     check_line(char *line, t_conf *conf, int *all_c)
{
    char **sep;
    int ret;

    if (ft_strcmp(line, "") == 0)
        ret = 0;
    else
    {
        if ((sep = ft_split(line, ' ')) == NULL)
            ret = -1;
        else
        {
            ret = which(sep, line, conf, all_c);
            clean(sep);
        }
    }
    return (ret);
}

static int  empty(int fd, char **line, int *ret)
{
    int i;

    i = 0;
    while ((*ret = get_next_line(fd, line)) == 1 && ft_strcmp(*line, "") == 0)
    {
        free(*line);
        i++;
    }
    return (i);
}

int     check_conf(int fd, char **line, t_conf *conf, t_map *map)
{
    int check[9];
    int ret;
    
    init(check, conf, map);
    while ((ret = get_next_line(fd, line)) != -1 && all_good(check) != 1)
     {  
        check[8]++;
        if (ret == -1 || check_line(*line, conf, check) == -1 || ret == 0)
        {
            free(*line);
            return (error_message(check, ret));
        }
        free(*line);
    }
    show_conf(conf);
    if (ret == -1 || all_good(check) != 1 || all_valid(conf, check) != 1)
        return (error_message(check, ret));
    if ((map->height -= (check[8] + empty(fd, line, &ret))) < 1 || ret < 1)
        return (error_message(check, ret));
    else
        return (check_map(fd, line, map)); 
   return (1);
}

int     check_cub(char *av, t_conf *conf, t_map *map)
{
    char *line;
    int fd;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        return (-1);
    map->height = how_len(av);
    if (check_conf(fd, &line, conf, map) == -1)
        return (-1);
    return (1);
}