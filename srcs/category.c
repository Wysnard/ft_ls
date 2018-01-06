/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:36:06 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:36:37 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_initfile(t_list *elem)
{
	LCONT(elem)->only = 1;
}

int		ft_category(char *path)
{
	DIR				*fd;
	struct dirent	*dir;
	int				category;

	category = 1;
	if (!(fd = opendir(path)))
	{
		if (errno == ENOTDIR)
			return (-1);
		else if (errno == EACCES)
			return (1);
		ft_openerr(path, "");
		return (-2);
	}
	dir = readdir(fd);
	category = (dir->d_type == DT_DIR) ? 1 : 0;
	closedir(fd);
	return (category);
}
