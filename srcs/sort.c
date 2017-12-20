#include "ls.h"

int	ft_lstcompare(void *s1, void *s2)
{
	t_ls	*l1;
	t_ls	*l2;

	l1 = (t_ls *)s1;
	l2 = (t_ls *)s2;
	return (ft_strcmp(l1->dir->d_name, l2->dir->d_name));
}

int	ft_lstsorttime(void *s1, void *s2)
{
	t_ls	*l1;
	t_ls	*l2;

	l1 = (t_ls *)s1;
	l2 = (t_ls *)s2;
	if (l2->st->st_ctime > l1->st->st_ctime)
		return (1);
	else if (l2->st->st_ctime <= l1->st->st_ctime)
		return (-1);
	return (l1->st->st_ctime - l2->st->st_ctime);
}
