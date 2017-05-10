/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:57:34 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:57:35 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	if (s1 != NULL && s2 != NULL)
		ret = ft_strnew(2 + ft_strlen(s1) + ft_strlen(s2));
	if (s2 == NULL && s1 != NULL)
		ret = ft_strnew(1 + ft_strlen(s1));
	if (s1 == NULL && s2 != NULL)
		ret = ft_strnew(1 + ft_strlen(s2));
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (ret == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strcpy(ret, s1);
	if (s2 != NULL && s1 != NULL)
		ft_strcat(ret, s2);
	if (s1 == NULL)
		ft_strcpy(ret, s2);
	return (ret);
}
