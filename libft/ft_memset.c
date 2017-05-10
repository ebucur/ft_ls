/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:51:17 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:51:19 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t l)
{
	while (l > 0)
	{
		l--;
		((unsigned char *)ptr)[l] = (unsigned char)c;
	}
	return (ptr);
}
