#include "ls.h"

void	ft_prtlst(t_list *elem)
{
	t_ls *ls;

	ls = (t_ls *)elem->content;
	ft_printf("%s\n", ls->dir->d_name);
}

void	ft_prtl(t_list *elem)
{
	t_ls *ls;
	struct	passwd	*pw;
	struct	group	*grp;
	char	buf[10];

	if (!(ls = (t_ls *)elem->content))
		return ;
	ft_strmod(ls->st->st_mode, buf);
	if (!(pw = getpwuid(ls->st->st_uid)) || !(grp = getgrgid(pw->pw_gid)))
		return ;
	ft_printf("%c%s  %*u %s  %s  %*u %.12s %s\n",
	ft_gettypec(ls->dir->d_type),
	buf,
	ls->link,
	ls->st->st_nlink,
	pw->pw_name,
	grp->gr_name,
	LCONT(elem)->space,
	ls->st->st_size,
	ctime(&ls->st->st_ctime) + 4,
	ls->dir->d_name);
}
