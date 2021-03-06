/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:58:48 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:16:26 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_p1(t_list *tmp, off_t maxsize, nlink_t link)
{
	while (tmp)
	{
		LCONT(tmp)->link = ft_uintlen(link, 10);
		LCONT(tmp)->space = ft_uintlen(maxsize, 10);
		tmp = tmp->next;
	}
}

void	ft_getspace(t_list *list)
{
	off_t	maxsize;
	nlink_t	link;
	t_list	*tmp;

	if (!(tmp = list))
		return ;
	maxsize = LCONT(tmp)->st->st_size;
	link = LCONT(tmp)->st->st_nlink;
	while (tmp)
	{
		if (LCONT(tmp)->st->st_nlink > link)
			link = LCONT(tmp)->st->st_nlink;
		if ((LCONT(tmp)->st->st_mode & S_IFMT) == S_IFBLK
		|| (LCONT(tmp)->st->st_mode & S_IFMT) == S_IFCHR)
			maxsize = 90000000;
		else if (LCONT(tmp)->st->st_size > maxsize)
			maxsize = LCONT(tmp)->st->st_size;
		tmp = tmp->next;
	}
	ft_p1(list, maxsize, link);
}

void	ft_p2(t_list *tmp, size_t lengrp, size_t lenusr)
{
	while (tmp)
	{
		LCONT(tmp)->lenusr = lenusr;
		LCONT(tmp)->lengrp = (lengrp) ? lengrp
			: ft_intlen(LCONT(tmp)->st->st_uid, 10);
		tmp = tmp->next;
	}
}

void	ft_usrspace(t_list *list)
{
	size_t			lengrp;
	size_t			lenusr;
	struct passwd	*pw;
	struct group	*grp;
	t_list			*tmp;

	if (!(tmp = list))
		return ;
	lenusr = 0;
	lengrp = 0;
	while (tmp)
	{
		if ((pw = getpwuid(LCONT(tmp)->st->st_uid))
			&& (grp = getgrgid(pw->pw_gid)))
		{
			if (lenusr < ft_strlen(pw->pw_name))
				lenusr = ft_strlen(pw->pw_name);
			if (lengrp < ft_strlen(grp->gr_name))
				lengrp = ft_strlen(grp->gr_name);
		}
		else if (lenusr < ft_uintlen(LCONT(tmp)->st->st_uid, 10))
			lenusr = ft_uintlen(LCONT(tmp)->st->st_uid, 10);
		tmp = tmp->next;
	}
	ft_p2(list, lengrp, lenusr);
}
