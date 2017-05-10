/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:06:10 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:06:24 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_opt arg, t_elem *files, int ord)
{
	t_elem	*elem;

	elem = files;
	elem = sort_elem(elem, arg);
	(arg.l == 1 || arg.g == 1) ? \
			ls_long(arg, elem, ord) : ls_simple(arg, elem);
	arg.upper_r == 1 ? recursion(arg, elem) : NULL;
}

void	do_ls_dir(t_opt arg, t_elem *dirlist, int multidir)
{
	DIR		*dir;
	t_elem	*files;
	int		first;

	first = 0;
	files = NULL;
	while (dirlist)
	{
		dir = opendir(dirlist->name);
		while (elemget(&files, readdir(dir), \
			ft_adddash(dirlist->path), arg) != 0)
			;
		closedir(dir);
		if (files)
		{
			first == 1 ? ft_putchar('\n') : NULL;
			multidir ? ft_putendl(ft_strjoin(dirlist->name, ":")) : NULL;
			first = 1;
			display_file(arg, files, 1);
		}
		files = NULL;
		dirlist = dirlist->next;
	}
}

void	ls_dir(t_opt arg, t_list *path, int multidir)
{
	t_list	*elem;
	t_elem	*dirlist;

	elem = path;
	dirlist = NULL;
	while (elem)
	{
		elemgetfiles(&dirlist, elem->content, "", arg);
		elem = elem->next;
	}
	dirlist = sort_elem(dirlist, arg);
	do_ls_dir(arg, dirlist, multidir);
}

void	ls_file(t_opt arg, t_list *path)
{
	t_list	*elem;
	t_elem	*files;

	elem = path;
	files = NULL;
	arg.a = 1;
	while (elem)
	{
		elemgetfiles(&files, elem->content, "", arg);
		elem = elem->next;
	}
	if (files)
		display_file(arg, files, 0);
}

void	core(t_opt arg, t_list *path, int multidir)
{
	DIR		*dir;
	t_list	*file;
	t_list	*directory;
	t_list	*elem;

	file = NULL;
	directory = NULL;
	elem = path;
	while (elem)
	{
		if ((dir = checkcond(elem, arg)) == NULL)
			(errno != 0 && errno != ENOTDIR) ? basicerror("ft_ls: ",
				elem->content, 0) : ft_lstpushback(&file,
					elem->content, elem->content_size);
		else
		{
			ft_lstpushback(&directory, elem->content, elem->content_size);
			if (closedir(dir) == -1)
				basicerror("ft_ls: ", elem->content, 0);
		}
		elem = elem->next;
	}
	file ? ls_file(arg, file) : NULL;
	file && directory ? ft_putchar('\n') : NULL;
	directory ? ls_dir(arg, directory, multidir) : NULL;
}
