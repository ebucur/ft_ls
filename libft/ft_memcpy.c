/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:50:45 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:50:46 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned int	i;
	void			*ret;

	ret = dest;
	i = 0;
	while (i < num)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		i++;
	}
	return (ret);
}
