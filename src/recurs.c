/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:07:27 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:07:30 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	do_recursion(t_opt arg, char *path)
{
	t_elem	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (elemget(&files, readdir(dir), \
					ft_strjoin(path, "/"), arg) != 0)
			;
		closedir(dir);
		if (files)
			display_file(arg, files, 1);
		files = NULL;
	}
	else
		basicerror("ft_ls: ", path, 0);
}

void	recursion(t_opt arg, t_elem *files)
{
	t_elem	*elem;

	elem = files;
	while (elem)
	{
		if (elem->name && elem->path && \
				S_ISDIR(elem->st_mode) && \
				ft_strcmp(".", elem->name) && \
				ft_strcmp("..", elem->name) && \
				!(arg.a == 0 && elem->name[0] == '.'))
			do_recursion(arg, elem->path);
		elem = elem->next;
	}
}
