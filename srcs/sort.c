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
	// ft_printf("%s = %jd || %s = %jd >> %jd\n", l1->dir->d_name, l1->st->st_mtime, l2->dir->d_name, l2->st->st_mtime, l1->st->st_mtime - l2->st->st_mtime);
	return (l1->st->st_mtime - l2->st->st_mtime);
}

// void	ft_lstinserttime(t_list **alst, t_list *new)
// {
// 	t_list	*tmp;
//
// 	if (!alst)
// 		return ;
// 	if (!(tmp = *alst) || LCONT((*alst))->st->st_ctime >= LCONT(new)->st->st_ctime)
// 		ft_lstadd(alst, new);
// 	else
// 	{
// 		while (tmp->next && LCONT((*alst))->st->st_ctime < LCONT(new)->st->st_ctime)
// 			tmp = tmp->next;
// 		if ((new->next = tmp->next))
// 			new->next->prev = new;
// 		new->prev = tmp;
// 		tmp->next = new;
// 	}
// }
