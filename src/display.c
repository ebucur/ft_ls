/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:03:08 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:03:11 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_color(mode_t mode, t_opt arg)
{
	if (arg.upper_g)
	{
		S_ISBLK(mode) ? ft_putstr(C_GRAY) : NULL;
		S_ISCHR(mode) ? ft_putstr(C_BLUE) : NULL;
		S_ISDIR(mode) ? ft_putstr(C_CYAN) : NULL;
		S_ISFIFO(mode) ? ft_putstr(C_BROWN) : NULL;
		S_ISREG(mode) ? ft_putstr(C_NONE) : NULL;
		S_ISLNK(mode) ? ft_putstr(C_GREEN) : NULL;
		S_ISSOCK(mode) ? ft_putstr(C_MAGENTA) : NULL;
	}
}

void	ls_simple(t_opt arg, t_elem *files)
{
	t_elem	*elem;

	elem = files;
	while (elem)
	{
		if (!(arg.a == 0 && elem->name[0] == '.'))
		{
			ft_color(elem->st_mode, arg);
			ft_putendl(elem->name);
			arg.upper_g ? ft_putstr(C_NONE) : NULL;
		}
		elem = elem->next;
	}
}

void	print_sym(t_elem *elem, t_opt arg)
{
	char	*buf;

	buf = (char *)malloc(elem->st_size + 1);
	if (readlink(elem->path, buf, elem->st_size + 1) == -1)
		basicerror("ft_ls:", elem->name, 1);
	buf[elem->st_size] = '\0';
	ft_putstr(elem->name);
	arg.upper_g ? ft_putstr(C_NONE) : NULL;
	ft_putstr(" -> ");
	ft_putendl(buf);
}

void	ls_long_file(t_opt arg, t_elem *elem, t_size size)
{
	print_access(elem);
	print_int(elem->st_nlink, size.linkspace);
	if (arg.g == 0)
	{
		if (getpwuid(elem->st_uid))
			print_str(getpwuid(elem->st_uid)->pw_name, size.userspace);
		else
			print_str(ft_itoa(elem->st_uid), size.userspace);
	}
	if (getgrgid(elem->st_gid))
		print_str(getgrgid(elem->st_gid)->gr_name, size.groupspace);
	else
		print_str(ft_itoa(elem->st_gid), size.groupspace);
	if (S_ISCHR(elem->st_mode) || S_ISBLK(elem->st_mode))
		print_majmin(elem, size);
	else
		print_int(elem->st_size, size.size);
	display_date(elem->date);
	ft_color(elem->st_mode, arg);
	S_ISLNK(elem->st_mode) ? print_sym(elem, arg) : ft_putendl(elem->name);
	arg.upper_g ? ft_putstr(C_NONE) : NULL;
}

void	ls_long(t_opt arg, t_elem *files, int fileordir)
{
	t_elem	*elem;
	t_size	size;

	elem = files;
	size = get_size(arg, files);
	if (fileordir && ft_puttotal(elem, arg))
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	while (elem)
	{
		if (!(arg.a == 0 && elem->name[0] == '.'))
			ls_long_file(arg, elem, size);
		elem = elem->next;
	}
}
