/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:01:27 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:01:29 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*c1;
	char	*c2;
	int		i;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			c1 = (char *)(str1 + i);
			c2 = (char *)str2;
			while (*c1 && *c2 && *c1 == *c2)
			{
				c1++;
				c2++;
			}
			if (!*c2)
				return ((char *)(str1 + i));
		}
		i++;
	}
	return (0);
}
