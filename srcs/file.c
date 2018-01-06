/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:37:38 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:38:00 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_lsfile	ft_filemax(t_list *list)
{
	t_lsfile		file;
	struct	stat	st;
	struct	passwd	*pw;
	struct	group	*grp;

	file.lengrp = 0;
	file.lenusr = 0;
	file.space = 0;
	while (list)
	{
		stat(list->content, &st);
		if (file.space < st.st_size)
			file.space = st.st_size;
		pw = getpwuid(st.st_uid);
		if (pw && (grp = getgrgid(pw->pw_gid)))
		{
			if (file.lenusr < ft_strlen(pw->pw_name))
				file.lenusr = ft_strlen(pw->pw_name);
			if (file.lengrp < ft_strlen(grp->gr_name))
				file.lengrp = ft_strlen(grp->gr_name);
		}
		list = list->next;
	}
	file.space = ft_uintlen(file.space, 10);
	return (file);
}

char		ft_typefile(struct stat st)
{
	char res;
	mode_t mask;

	res = 0;
	mask = st.st_mode & S_IFMT;
	if (mask == S_IFLNK)
		res = 'l';
	else if (mask == S_IFREG)
		res = '-';
	else if (mask == S_IFBLK)
		res = 'b';
	else if (mask == S_IFCHR)
		res = 'c';
	return (res);
}

void		ft_printfile(char *path, struct stat st, t_lsfile file)
{
	(void)st;
	(void)file;
	char buf[256];
	struct	passwd	*pw;
	struct	group	*grp;

	pw = getpwuid(st.st_uid);
	grp = (pw) ? getgrgid(pw->pw_gid) : NULL;
	ft_strmod(st.st_mode, buf);
	ft_printf("%c%s  %*u ",
	ft_typefile(st),
		buf,
		3,
		st.st_nlink);
	(pw) ?
	ft_printf("%-*s  ", file.lenusr, pw->pw_name) :
	ft_printf("%-*u  ", file.lenusr, st.st_uid);
	ft_printf("%-*s  %*u %.12s %s", file.lengrp,
		(grp) ? grp->gr_name : "_lpoperator",
		file.space,
		st.st_size,
		ctime(&st.st_ctime) + 4,
		path);
}
