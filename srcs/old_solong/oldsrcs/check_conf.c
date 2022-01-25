/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:05:59 by cramdani          #+#    #+#             */
/*   Updated: 2020/06/02 18:01:47 by cramdani         ###   ########.fr       */
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
        if ((ft_isnum(sep[1]) == 1 || (sep[1][0] == '-' && ft_isnum(sep[1] + 1) == 1 ))\
            && (ft_isnum(sep[2]) == 1 || (sep[2][0] == '-' && ft_isnum(sep[1] + 1))))
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

static void utils_col(int *ret, t_conf *conf, char **num, int check)
{
    int i;

    i = 0;
    num[0][0] = num[0][1];
    *ret = 0;
    while (num[i] != NULL && *ret != -1)
    {
        num[i] = ft_strtrim(num[i], " ");
        if (!(ft_isnum(num[i]) == 1 || (num[i][0] == '-' && ft_isnum(num[i] + 1) == 1)))
            *ret = -1;
        else
            conf->col[check - 6][i] = ft_atoi(num[i]);
        i++;
    }
    *ret = (num[i] == NULL && *ret == 0) ? 1 : -1;

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
            utils_col(&ret, conf, num, check);
    }
    all_c[check] = ret;
    return (ret);
}