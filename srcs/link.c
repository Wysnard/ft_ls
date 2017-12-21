#include "ls.h"

void	ft_dolnk(t_list *elem)
{
	char	buf[LCONT(elem)->st->st_size + 1];
	size_t	ret;

	ft_bzero(buf, (size_t)LCONT(elem)->st->st_size);
	ret = readlink(LCONT(elem)->path, buf, LCONT(elem)->st->st_size);
	buf[ret] = '\0';
	ft_printf(" -> %s", buf);
}
