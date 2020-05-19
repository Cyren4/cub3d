/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramdani <cramdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:57:37 by cramdani          #+#    #+#             */
/*   Updated: 2020/05/18 02:57:06 by cramdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
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
	if (s1)
		free(s1);
	return (str);
}
