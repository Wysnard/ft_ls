#include "ls.h"

void	ft_getspace(t_list *list)
{
	uintmax_t	lensize;
	uintmax_t	lenln;
	off_t	maxsize;
	nlink_t	link;
	t_list	*tmp;

	if (!(tmp = list))
		return ;
	maxsize = LCONT(tmp)->st->st_size;
	link = LCONT(tmp)->st->st_nlink;
	while (tmp)
	{
		if (LCONT(tmp)->st->st_nlink > link)
			link = LCONT(tmp)->st->st_nlink;
		if (LCONT(tmp)->st->st_size > maxsize)
			maxsize = LCONT(tmp)->st->st_size;
		tmp = tmp->next;
	}
	tmp = list;
	lensize = ft_uintlen(maxsize, 10);
	lenln = ft_uintlen(link, 10);
	while (tmp)
	{
		LCONT(tmp)->link = lenln;
		LCONT(tmp)->space = lensize;
		tmp = tmp->next;
	}
}
