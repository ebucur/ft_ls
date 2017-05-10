/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 12:48:12 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 12:48:13 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*ret;
	t_list			*ret_f;

	if (lst && f)
	{
		ret = f(lst);
		if (ret)
		{
			ret_f = ret;
			while (lst->next)
			{
				lst = lst->next;
				ret->next = f(lst);
				ret = ret->next;
				if (!ret)
					return (NULL);
			}
			return (ret_f);
		}
	}
	return (NULL);
}
