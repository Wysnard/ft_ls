#include "ls.h"

void	ft_prtlst(t_list *elem)
{
	t_ls *ls;

	ls = (t_ls *)elem->content;
	ft_printf("%s\n", ls->dir->d_name);
	// ft_printf("l1 = %jd\n", (intmax_t)ls->st->st_mtime);
}

void	ft_prtnodevice(t_ls *ls, struct	passwd *pw, struct	group *grp, char buf[])
{
	ft_printf("%c%s  %*u %-*s  %-*s  %*u %.12s %s",
	ft_gettypec(ls->dir->d_type),
	buf,
	ls->link,
	ls->st->st_nlink,
	ls->lenusr,
	pw->pw_name,
	ls->lengrp,
	grp->gr_name,
	ls->space,
	ls->st->st_size,
	ctime(&ls->st->st_ctime) + 4,
	ls->dir->d_name);
}

void	ft_prtdevice(t_ls *ls, struct	passwd *pw, struct	group *grp, char buf[])
{
	ft_printf("%c%s  %*u %-*s  %-*s %4u,%4u %.12s %s",
	ft_gettypec(ls->dir->d_type),
	buf,
	ls->link,
	ls->st->st_nlink,
	ls->lenusr,
	pw->pw_name,
	ls->lengrp,
	grp->gr_name,
	ls->st->st_rdev >> 24,
	ls->st->st_rdev & 0xFF,
	ctime(&ls->st->st_ctime) + 4,
	ls->dir->d_name);
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
	if (!(pw = getpwuid(ls->st->st_uid)) || !(grp = getgrgid(pw->pw_gid)))
		return ;
	(ls->dir->d_type == DT_BLK || ls->dir->d_type == DT_CHR) ?
	ft_prtdevice(ls, pw, grp, buf) : ft_prtnodevice(ls, pw, grp, buf);
	if (ls->dir->d_type == DT_LNK)
		ft_dolnk(elem);
	ft_putchar('\n');
}
