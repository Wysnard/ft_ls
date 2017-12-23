#include "ls.h"

int	ft_openerr(const char *path, char *opt)
{
	if (ft_strchr(opt, 'R'))
		ft_printf("%s:\n", path);
	ft_putstr_fd("ls: ", 2);
	perror(ft_strrchr(path, '/') ?  ft_strrchr(path, '/') + 1 : path);
	return (1);
}
