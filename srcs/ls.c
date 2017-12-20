#include "ls.h"

void	ft_lstd(void *content, size_t content_size)
{
	t_ls *ls;

	(void)content_size;
	if (!(ls = (t_ls *)content))
		return ;
	free(ls->dir);
	free(ls->st);
	free(ls);
}

t_ls	*ft_registerls(struct dirent *dir, char *path)
{
	t_ls	*ls;

	if (!(ls = (t_ls *)malloc(sizeof(*ls))))
		return (NULL);
	ls->dir = ft_direntdup(dir);
	ls->st = ft_statcpy(path, dir->d_type);
	// ft_printf("%d\n", ls->st->st_ctime);
	return (ls);
}

static	void ft_rec(const char *path, t_list *list, char *opt)
{
	char	*keep;

	if (ft_strchr(opt, 'R'))
	{
		while (list)
		{
			if (LCONT(list)->dir->d_type == DT_DIR)
			{
				ft_ls(keep = ft_strmultijoin(3, path, "/", LCONT(list)->dir->d_name), opt);
				free(keep);
				ft_putchar('\n');
			}
			list = list->next;
		}
	}
}

void	ft_ls(const char *path, char *opt)
{
	t_list	*list;
	DIR	*fd;
	struct dirent	*dir;
	char	*keep;
	size_t	mark;

	fd = opendir(path);
	list = NULL;
	mark = 0;
	while ((dir = readdir(fd)))
	{
		if (dir->d_type == DT_DIR)
			mark++;
		if (*dir->d_name != '.' || ft_strchr(opt, 'a'))
		{
			// ft_lstpushadd(&list, ft_lstsnew(ft_registerls(dir, keep = ft_strmultijoin(3, path, "/", dir->d_name)), sizeof(*dir)));
			ft_lstinsert(&list, ft_lstsnew(
				ft_registerls(dir, keep = ft_strmultijoin(3, path, "/", dir->d_name)), sizeof(*dir)),
					(ft_strchr(opt, 't')) ? &ft_lstsorttime : &ft_lstcompare);
			free(keep);
		}
	}
	if (ft_strchr(opt, 'R') && mark)
		ft_printf("%s:\n", path);
	ft_getspace(list);
	ft_lstiter(list, (ft_strchr(opt, 'l')) ? &ft_prtl : &ft_prtlst);
	ft_rec(path, list, opt);
	ft_lstdel(&list, &ft_lstd);
	closedir(fd);
}
