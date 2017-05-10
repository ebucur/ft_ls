/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:47:16 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:47:18 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_n_size(int n)
{
	int		size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		x;
	int		neg;

	neg = 1;
	x = ft_n_size(n);
	str = (char *)malloc(sizeof(char *) * x + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[x] = '\0';
	if (n < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	x--;
	while (n)
	{
		str[x] = (((n % 10) * neg) + '0');
		x--;
		n = n / 10;
	}
	return (str);
}
