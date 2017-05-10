/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:51:08 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:51:10 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	void		*ret;

	ret = dest;
	if (dest < src)
		while ((unsigned char)(dest - ret) < num)
			*(char *)dest++ = *(char *)src++;
	else
		while (num-- > 0)
			((char *)dest)[num] = ((char *)src)[num];
	return (ret);
}
