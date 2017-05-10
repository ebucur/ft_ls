/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:09:41 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:09:44 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_adddash(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (path);
	else
		return (ft_strjoin(path, "/"));
}

int		checklink(char *path, t_opt arg)
{
	struct stat		stats;

	lstat(path, &stats);
	if (arg.l == 0)
		return (0);
	return (S_ISLNK(stats.st_mode));
}

int		ft_puttotal(t_elem *elem, t_opt arg)
{
	t_elem	*elem1;

	if (arg.a)
		return (1);
	elem1 = elem;
	while (elem1)
	{
		if (elem1->name[0] != '.')
			return (1);
		elem1 = elem1->next;
	}
	return (0);
}

DIR		*checkcond(t_list *path, t_opt arg)
{
	DIR		*ret;

	if (checklink(path->content, arg))
		return (NULL);
	ret = opendir(path->content);
	if (arg.l == 0)
	{
		arg.l = 1;
		if (checklink(path->content, arg) && ret == NULL)
			errno = 0;
		arg.l = 0;
	}
	return (ret);
}

void	repeat_sort(t_elem **list, t_opt arg)
{
	t_elem	*a;
	t_elem	*b;
	int		k;

	k = arg.t;
	while (k)
	{
		k = 0;
		a = *list;
		while (a)
		{
			b = a->next;
			if (b && a->date == b->date && cmp_alpha(a, b) > 0)
			{
				k = 1;
				swap_elem(&a, &b);
			}
			a = a->next;
		}
	}
}
