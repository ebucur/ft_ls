/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:01:02 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:01:03 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *rez;

	rez = (char *)str + ft_strlen(str);
	while (*rez != c)
	{
		if (rez == str)
			return (NULL);
		rez--;
	}
	return (rez);
}
