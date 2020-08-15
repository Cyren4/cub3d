/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 11:55:00 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/31 22:24:26 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int     check_text(t_conf *conf, int  *check)
{
    int i;
    int ret;

    i = 0;
    ret = 1;
    while (i < 5)
    {
        if (ft_strcmp(conf->text[i] + ft_strlen(conf->text[i]) - 4, ".xpm") != 0)
        {
            write(1, "Error\nTextures need to be a *.xpm file\n", 40);
            check[i + 1] = -1;
            ret = -1;
        }
      //  else if (open(conf->text[i], O_RDONLY) == -1)
      //  {
      //      write(1, "Error\nError opening texture\n", 29);
      //      ret = -1;
      //  }
        i++;
    }
    return (ret);
}

static int     check_col(t_conf *conf, int  *check)
{
    int i;
    int ret;

    i = 0;
    ret = 1;
    while (i < 3 && ret != -1)
    {
        if (conf->col[0][i] < 0 || conf->col[0][i] > 255)
            check[6] = -1;
        if (conf->col[1][i] < 0 || conf->col[1][i] > 255)
            check[7] = -1;
        i++;
    }
    if (check[6] == -1 || check[7] == -1)
    {
        ret = -1;
        write(1, "Error\nColors need to be in range [0, 255]\n", 43);
    }
    return (ret);
}

int     all_valid(t_conf *conf, int *check)
{
    int ret;

    ret = 1;
    if (check_text(conf, check) != 1)
        ret = -1;
    if (check_col(conf, check) != 1)
        ret = -1;
    return (ret);
}
