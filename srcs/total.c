#include "ls.h"

size_t	ft_total(t_list *list)
{
	size_t	total;

	total = 0;
	while (list)
	{
		total += LCONT(list)->st->st_blocks;
		list = list->next;
	}
	return (total);
}
