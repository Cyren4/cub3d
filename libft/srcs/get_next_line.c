/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 12:57:36 by cramdani          #+#    #+#             */
/*   Updated: 2022/01/25 12:56:43 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 32
# endif

char	*stock_str(char *buf, char *str)
{
	char *tmp;

	if (!str)
		str = ft_strdup(buf);
	else
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

char	*stock_line(char *str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i < (int)ft_strlen(str))
	{
		tmp = str;
		*line = ft_substr(str, 0, i);
		str = ft_substr(str, i + 1, ft_strlen(str));
		free(tmp);
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char *str;
	char		buf[BUFF_SIZE + 1];
	int			i;

	if ((BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		str = stock_str(buf, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (str)
		str = stock_line(str, line);
	if (str == NULL)
		return (0);
	return (1);
}
