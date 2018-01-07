/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:16:50 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:17:29 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

size_t	ft_modechri(mode_t *str, mode_t c, size_t len)
{
	size_t	i;

	if (!str || !len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (i);
}

char	ft_gettypec(mode_t d_type)
{
	if ((d_type & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((d_type & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((d_type & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((d_type & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((d_type & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((d_type & S_IFMT) == S_IFREG)
		return ('-');
	else if ((d_type & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return (' ');
}

void	ft_strmod(mode_t mode, char *buf)
{
	static	char	mod[] = "rwxrwxrwx";
	size_t			i;

	i = 0;
	while (i < 9)
	{
		buf[i] = mode & (1 << (8 - i)) ? mod[i] : '-';
		i++;
	}
	buf[9] = '\0';
}
