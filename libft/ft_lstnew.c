/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:48:29 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:48:31 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;
	void	*cpy;

	cpy = NULL;
	if (!content)
		content_size = 0;
	else
	{
		cpy = ft_memalloc(content_size);
		if (cpy == NULL)
			return (NULL);
		cpy = ft_memcpy(cpy, content, content_size);
	}
	ret = (t_list *)ft_memalloc(sizeof(t_list));
	if (ret != NULL)
	{
		ret->content = cpy;
		ret->content_size = content_size;
		ret->next = NULL;
		return (ret);
	}
	return (NULL);
}
