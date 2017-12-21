#include "ls.h"

int	ft_lstdir(t_list *list)
{
	t_ls	*ls;

	ls = LCONT(list);
	ft_prtlst(list);
	return ((ls->dir->d_type == DT_DIR) ? 1 : 0);
}

int	ft_lstdirl(t_list *list)
{
	t_ls	*ls;

	ls = LCONT(list);
	ft_prtl(list);
	return ((ls->dir->d_type == DT_DIR) ? 1 : 0);
}
