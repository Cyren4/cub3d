/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:57:36 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/18 03:02:03 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 30

static int	check_n(char *line)
{
	int i;

	i = 0;
	if (line == NULL)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}

static int		get_clean(char *tmp)
{
	if (tmp != NULL)
		free(tmp);
	return (-1);
}

static char	*lks(char *tmp)
{
	char		*leaks;

	leaks = tmp;
	tmp = ft_substr(tmp, check_n(tmp) + 1, ft_strlen(tmp));
	free(leaks);
	return (tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			r;

	r = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = NULL;
	while (check_n(tmp) < 0)
	{
		if ((r = read(fd, buf, BUFFER_SIZE)) == -1)
			return (get_clean(tmp));
		buf[r] = '\0';
		tmp = ft_strjoin2(tmp, buf);
		if (r == 0 && check_n(tmp) < 0)
		{
			*line = ft_substr(tmp, 0, ft_strlen(tmp));
			free(tmp);
			tmp = NULL;
			return (0);
		}
	}
	*line = ft_substr(tmp, 0, check_n(tmp));
	tmp = lks(tmp);
	return (1);
}
