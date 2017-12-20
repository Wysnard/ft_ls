#include "libft.h"

size_t	ft_uintlen(uintmax_t nb, unsigned base)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= base;
	}
	return (i);
}
