#include "ls.h"

struct dirent	*ft_direntdup(struct dirent *dir)
{
	struct dirent	*cp;

	if (!(cp = (struct dirent *)malloc(sizeof(struct dirent))))
		exit(EXIT_FAILURE);
	cp->d_type = dir->d_type;
	ft_strcpy(cp->d_name, dir->d_name);
	return (cp);
}
