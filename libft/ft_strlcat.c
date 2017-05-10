/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:57:46 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:57:47 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t num)
{
	size_t i;
	size_t j;

	if (num == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dest[i] && i < num)
		i++;
	while (src[j] && (i + j) < (num - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < num)
		dest[i + j] = 0;
	return (i + ft_strlen(src));
}
