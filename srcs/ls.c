/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:44:16 by vlay              #+#    #+#             */
/*   Updated: 2018/01/10 20:26:40 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_lstd(void *content, size_t content_size)
{
	t_ls *ls;

	(void)content_size;
	if (!(ls = (t_ls *)content))
		return ;
	if (ls->path)
		free(ls->path);
	if (ls->dir)
		free(ls->dir);
	if (ls->st)
		free(ls->st);
	free(ls);
}

t_ls	*ft_registerls(struct dirent *dir, char *path, char *opt)
{
	t_ls	*ls;

	(void)opt;
	if (!(ls = (t_ls *)malloc(sizeof(*ls))))
		return (NULL);
	ls->path = (path) ? ft_strdup(path) : NULL;
	ls->dir = (dir) ? ft_direntdup(dir) : dir;
	ls->st = (path) ? ft_statcpy(path) : NULL;
	ls->only = 0;
	return (ls);
}

void	ft_rec(const char *path, t_list **list, char *opt)
{
	char	*keep;
	t_list	*next;

	if (!list || !(*list))
		return ;
	if (ft_strchr(opt, 'R'))
	{
		while (*list)
		{
			next = (*list)->next;
			if (LCONT((*list))->dir->d_type == DT_DIR
			&& !ft_strequ(LCONT((*list))->dir->d_name, ".")
			&& !ft_strequ(LCONT((*list))->dir->d_name, ".."))
			{
				ft_putchar('\n');
				ft_ls(keep = ft_strmultijoin(3, path, "/",
					LCONT((*list))->dir->d_name), opt);
				free(keep);
			}
			ft_lstd((*list)->content, (*list)->content_size);
			free(*list);
			*list = next;
		}
	}
}

void	ft_applyflags(const char *path, char *opt, t_list **list)
{
	if (ft_strchr(opt, 'R') && ft_strcmp(path, "."))
		ft_printf("%s:\n", path);
	if (!ft_strchr(opt, 'f'))
		(ft_strchr(opt, 't')) ?
		ft_lstmergesort(list, &ft_lstsorttime)
		: ft_lstmergesort(list, &ft_lstcompare);
	if (ft_strchr(opt, 'r'))
		ft_lstrev(list);
	if (ft_strchr(opt, 'l') && ft_printf("total %u\n", ft_total(*list)))
	{
		ft_getspace(*list);
		ft_usrspace(*list);
	}
	*list = ft_lstfilter(*list, (ft_strchr(opt, 'l')) ? &ft_lstdirl
			: &ft_lstdir, &ft_lstd);
	ft_rec(path, list, opt);
}

void	ft_ls(const char *path, char *opt)
{
	t_list			*list;
	DIR				*fd;
	struct dirent	*dir;
	char			*keep;

	if (!(fd = opendir(path)))
	{
		ft_openerr(path, opt);
		return ;
	}
	list = NULL;
	while ((dir = readdir(fd)))
		if (*dir->d_name != '.' || ft_strchr(opt, 'a') || ft_strchr(opt, 'f'))
		{
			ft_lstpushadd(&list, ft_lstsnew(
				ft_registerls(dir,
				keep = ft_strmultijoin(3, path, "/", dir->d_name), opt)
				, sizeof(*dir)));
			free(keep);
		}
	ft_applyflags(path, opt, &list);
	if (list)
		ft_lstdel(&list, &ft_lstd);
	closedir(fd);
}
