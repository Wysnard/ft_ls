#include "ls.h"

void	ft_dolnk(t_list *elem)
{
	char	buf[MAX_LINKSIZE];
	size_t	ret;

	ft_bzero(buf, MAX_LINKSIZE);
	ret = readlink(LCONT(elem)->path, buf, MAX_LINKSIZE);
	buf[ret] = '\0';
	ft_printf(" -> %s", buf);
}
