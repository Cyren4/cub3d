/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:21:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/14 20:42:13 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"


char	*ft_itoa_base(long unsigned nb, int base)
{
	char	*ret;
	char	*numbers;
	int		size;

	numbers = ft_strdup("0123456789abcdef");
	ret = NULL;
	size = ft_itoa_base_count(nb, base);
	if (!(ret = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size--] = '\0';
	while (size >= 0)
	{
		ret[size--] = numbers[nb % base];
		nb /= base;
	}
	free(numbers);
	return (ret);
}

int	ft_itoa_base_count(long unsigned nb, int base)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}
