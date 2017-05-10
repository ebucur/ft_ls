/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:49:04 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:49:05 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	unsigned int	i;

	i = 0;
	ret = (void *)malloc(size);
	if (!ret)
		return (NULL);
	while (i < size)
	{
		*(char *)(ret + i) = 0;
		i++;
	}
	return (ret);
}
