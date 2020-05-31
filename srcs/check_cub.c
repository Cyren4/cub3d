/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:05 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/31 11:39:23 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     show(t_conf *conf)
{
    int i = -1;

    printf("res : |%d| |%d|\n", conf->resol[0], conf->resol[1]);
    while (++i < 4)
    {
        printf("|%d| : |%s|\n", i, conf->text[i]);
    }
    printf("floor : |%d| |%d| |%d|\n", conf->col[0][0], conf->col[0][1], conf->col[0][2]);
    printf("ceiling : |%d| |%d| |%d|\n", conf->col[1][0], conf->col[1][1], conf->col[1][2]);
}

static void     init(int *check, t_conf *conf)
{
    int i;
    
    i = -1;
    while (++i < 8)
    {
        check[i] = 0;
        if (i < 5)
            conf->text[i] = NULL;
    }
    i = -1;
    while (++i < 3)
    {
        conf->col[0][i] = 0;
        conf->col[1][i] = 0;
        if (i < 2)
            conf->resol[i] = 0;
    }
}

static void     clean(char **sep)
{
    int i;

    i = 0;
    while (sep[i] != NULL)
    {
        free(sep[i]);
        i++;
    }
    free(sep);
}

static int  which(char **sep, char *line, t_conf *conf, int *all_c)
{
    int ret;

    if (ft_strcmp(*sep, "SO") == 0)
        ret = text(sep, conf, all_c, 1);
    else if (ft_strcmp(*sep, "WE") == 0)
        ret = text(sep, conf, all_c, 2);
    else if (ft_strcmp(*sep, "EA") == 0)
        ret = text(sep, conf, all_c, 3);
    else if (ft_strcmp(*sep, "NO") == 0)
        ret = text(sep, conf, all_c, 4);
    else if (ft_strcmp(*sep, "R") == 0)
        ret = res(sep, conf, all_c, 0);
    else if (ft_strcmp(*sep, "S") == 0)
        ret = text(sep, conf, all_c, 5);
    else if (ft_strcmp(*sep, "F") == 0)
        ret = color(line, conf, all_c, 6);
    else if (ft_strcmp(*sep, "C") == 0)
        ret = color(line, conf, all_c, 7);
    else
        ret = -1;
    return (ret);
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
            ret = which(sep,line , conf, all_c);
            clean(sep);
        }
    }
    return (ret);
}

int     check_conf(int fd, char **line, t_conf *conf, t_map *map)
{
    int check[8];
    int ret;
    
    init(check, conf);
    while ((ret = get_next_line(fd, line)) == 1 && all_good(check) != 1 )
    {
        if (ret == -1 || check_line(*line, conf, check) == -1)
        {
            free(*line);
            return (error_message(check));
        }
        free(*line);
    }
    show(conf);
    if (all_good(check) != 1)
        return (error_message(check));
  //  else if (all_valid(conf, check) != 1)
    //    return (error_message(check));
    write(1, "checkmap\n", 10);
    return (1);
}

int     check_cub(char *av, t_conf *conf, t_map *map)
{
    char *line;
    int fd;
    int ret;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        return (-1);
    if (check_conf(fd, &line, conf, map) == -1)
        return (-1);
    return (1);
}

/*



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