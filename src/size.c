/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebucur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 13:07:42 by ebucur            #+#    #+#             */
/*   Updated: 2017/03/19 13:11:38 by ebucur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_size_errorh(t_size *size, t_elem *elem)
{
	if (getpwuid(elem->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(elem->st_uid)->pw_name) \
			> size->userspace ? (int)ft_strlen(getpwuid(elem->st_uid)->pw_name)\
			: size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(elem->st_uid)) \
			> size->userspace ? (int)ft_strlen(ft_itoa(elem->st_uid)) \
			: size->userspace;
	if (getgrgid(elem->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(elem->st_gid)->gr_name) \
			> size->groupspace ? \
			(int)ft_strlen(getgrgid(elem->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = (int)ft_strlen(ft_itoa(elem->st_gid)) \
			> size->groupspace ? (int)ft_strlen(ft_itoa(elem->st_gid)) \
			: size->groupspace;
}

void	get_size_q(t_size *size, t_elem *elem)
{
	size->linkspace = (int)ft_strlen(ft_itoa(elem->st_nlink)) > \
		size->linkspace ? (int)ft_strlen(ft_itoa(elem->st_nlink)) \
		: size->linkspace;
	size->maj = (int)ft_strlen(ft_itoa(major(elem->st_rdev))) > size->maj \
		? (int)ft_strlen(ft_itoa(major(elem->st_rdev))) : size->maj;
	size->min = (int)ft_strlen(ft_itoa(minor(elem->st_rdev))) > size->min ? \
		(int)ft_strlen(ft_itoa(minor(elem->st_rdev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(elem->st_size)) > size->size ? \
		(int)ft_strlen(ft_itoa(elem->st_size)) : size->size;
	size->total += elem->st_blocks;
}

t_size	get_size(t_opt arg, t_elem *files)
{
	t_elem	*elem;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	elem = files;
	while (elem)
	{
		if (!(arg.a == 0 && elem->name[0] == '.'))
		{
			get_size_q(&size, elem);
			get_size_errorh(&size, elem);
		}
		elem = elem->next;
	}
	return (size);
}
