#include "ls.h"

int	ft_category(char *path)
{
	DIR	*fd;
	struct dirent	*dir;
	int	category;

	category = 1;
	if (!(fd = opendir(path)))
		return ((errno == ENOENT) ? -2 : -1);
	dir = readdir(fd);
	category = (dir->d_type == DT_DIR) ?
	1 : 0;
	closedir(fd);
	return (category);
}
