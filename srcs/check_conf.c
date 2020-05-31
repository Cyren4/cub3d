/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:05:59 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/30 19:55:08 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static char	*ft_strdup_nofree(char *s1)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
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
/*
int     check_text(t_conf *conf, int  *check)
{
    int i;
    int ret;

    i = 0;
    ret = 1;
    while (i < 4)
    {
        if (ft_strcmp(conf->text[i] + ft_strlen(conf->text[i]) - 4, ".xpm") != 0)
            write(1, "Error\nTextures need to be a *.xpm file\n", 40);
        else if (open)
        i++;
    }
    return (ret);

}

int     all_valid(t_conf *conf, int *check)
{
    if (check_text(conf, check) != 1 || check_color(conf, check) != 1)
        return (-1);
    else
        return (1);
}
*/
/*int  clear(char **sep, int ret)
{
    int i;

	i = 0;
	while (sep[i] != NULL)
	{
		free(sep[i]);
		i++;
	}
    return (ret);
}*/

int         text(char **sep, t_conf *conf, int *all_c, int i)
{
    int ret;

    if (all_c[i] != 0)
        ret = 2;
    else if (sep[0] == NULL || sep[1] == NULL || sep[2] != NULL)
        ret = -1;
    else
    {
        conf->text[i - 1] = ft_strdup_nofree(sep[1]);
        if (conf->text[i - 1] == NULL)
            ret = -1;
        else
            ret = 1;
    }
    all_c[i] = ret;
    return (ret);
}

int         res(char **sep, t_conf *conf, int *all_c, int i)
{
    int *res;
    int ret;

    if (all_c[i] != 0)
        ret = 2;
    else if (len(sep) == 3) 
    {
        if (ft_isnum(sep[1]) == 1 && ft_isnum(sep[2]) == 1)
        {
            conf->resol[0] = ft_atoi(sep[1]);
            conf->resol[1] = ft_atoi(sep[2]);
            ret = 1;
        }
        else
            ret = -1;
    }
    else
        ret = -1;
    all_c[i] = ret;
    return (ret);
}

int         color(char *line, t_conf *conf, int *all_c, int check)
{
    int ret;
    char **num;
    int i;

    i = 0;
    if (all_c[check] != 0)
        ret = 2;
    else
    {
        num = ft_split(ft_strtrim(line, " "), ',');
        if ((check == 6 ?  **num != 'F' : **num != 'C') || len(num) != 3)
            ret = -1;
        else
        {
            num[0][0] = num[0][1];
            ret = 0;
            while (num[i] != NULL && ret != -1)
            {
                num[i] = ft_strtrim(num[i], " ");
                if (ft_isnum(num[i]) != 1)
                    ret = -1;
                else
                    conf->col[check - 6][i] = ft_atoi(num[i]);
                i++;
            }
            ret = (num[i] == NULL && ret == 0) ? 1 : -1;
        }
    }
    all_c[check] = ret;
    return (ret);
}