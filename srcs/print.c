#include "ls.h"

void	ft_prtlst(t_list *elem)
{
	t_ls *ls;

	ls = (t_ls *)elem->content;
	if (ls->path)
		ft_printf("%s\n", (ft_strrchr(ls->path, '/')) ? ft_strrchr(ls->path, '/') + 1 : ls->path);
	// ft_printf("l1 = %jd\n", (intmax_t)ls->st->st_mtime);
}

void	ft_prtnodevice(t_ls *ls, struct	passwd *pw, struct	group *grp, char buf[])
{
	char	*tmp;

	tmp = ft_itoa(ls->st->st_gid);
	ft_printf("%c%s  %*u ",
	ft_gettypec(ls->st->st_mode),
		buf,
		ls->link,
		ls->st->st_nlink);
	(pw) ?
	ft_printf("%-*s  ", ls->lenusr, pw->pw_name) :
	ft_printf("%-*u  ", ls->lenusr, ls->st->st_uid);
	ft_printf("%-*s  %*u %.12s %s", ls->lengrp,
		(grp) ? grp->gr_name : tmp,
		ls->space,
		ls->st->st_size,
		ctime(&ls->st->st_ctime) + 4,
		(ft_strrchr(ls->path, '/') && !ls->only) ? ft_strrchr(ls->path, '/') + 1 : ls->path);
		if (tmp)
			free(tmp);
}

void	ft_prtdevice(t_ls *ls, struct	passwd *pw, struct	group *grp, char buf[])
{
	char	*tmp;

	tmp = ft_itoa(ls->st->st_gid);
	ft_printf("%c%s  %*u %-*s  %-*s %4u,%4u %.12s %s",
	ft_gettypec(ls->st->st_mode),
	buf,
	ls->link,
	ls->st->st_nlink,
	(pw) ? ls->lenusr : 0,
	(pw) ? pw->pw_name : "",
	ls->lengrp,
	(grp) ? grp->gr_name : tmp,
	ls->st->st_rdev >> 24,
	ls->st->st_rdev & 0xFF,
	ctime(&ls->st->st_ctime) + 4,
	(ft_strrchr(ls->path, '/') && !ls->only) ? ft_strrchr(ls->path, '/') + 1 : ls->path);
	if (tmp)
		free(tmp);
}

void	ft_prtl(t_list *elem)
{
	t_ls *ls;
	struct	passwd	*pw;
	struct	group	*grp;
	char	buf[256];

	if (!(ls = (t_ls *)elem->content))
		return ;
	ft_strmod(ls->st->st_mode, buf);
	pw = getpwuid(ls->st->st_uid);
	grp = (pw) ? getgrgid(pw->pw_gid) : NULL;
	((ls->st->st_mode & S_IFMT) == S_IFBLK || (ls->st->st_mode & S_IFMT) == S_IFCHR) ?
	ft_prtdevice(ls, pw, grp, buf) : ft_prtnodevice(ls, pw, grp, buf);
	if ((ls->st->st_mode & S_IFMT) == S_IFLNK)
		ft_dolnk(elem);
	ft_putchar('\n');
}
