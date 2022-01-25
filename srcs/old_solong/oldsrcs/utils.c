/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:58:35 by cramdani          #+#    #+#             */
/*   Updated: 2020/06/01 17:10:41 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  pb_line(int *all_c)
{

    write(1, "Error\nInvalid line : ", 22);
    ft_putnbr_fd(all_c[8], 1);
    write(1, "\n", 1);
    return (-1);
}

int     which(char **sep, char *line, t_conf *conf, int *all_c)
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
        ret = pb_line(all_c);
    return (ret);
}

void     clean(char **sep)
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

int     len(char **sep)
{
    int i;

    i = 0;
    while (sep[i] != NULL)
        ++i;
    return (i);
}

int      all_good(int *conf)
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

void    end_clean(t_conf *conf)
{
    int i;

    i = 0;
    while (i < 4)
    {
        free(conf->text[i]);
        i++;
    }
}
