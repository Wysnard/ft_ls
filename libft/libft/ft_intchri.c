#include "libft.h"

size_t	ft_intchri(int *str, int c, size_t len)
{
	size_t	i;

	if (!str || !len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i += 1;
	}
	return (i);
}
