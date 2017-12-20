#include "libft.h"

char	*ft_strmulticat(char *dest, size_t nbarg, ...)
{
	va_list	ap;
	size_t	i;

	i = 0;
	va_start(ap, nbarg);
	while (i < nbarg)
	{
		ft_strcat(dest, va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	return (dest);
}

char *ft_strmultijoin(size_t nbarg, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;
	va_list	aq;
	char	*str;

	i = 0;
	len = 0;
	if (nbarg == 0)
		return (NULL);
	va_copy(aq, ap);
	va_start(ap, nbarg);
	while (i < nbarg)
	{
		len += ft_strlen(va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	str = ft_strnew(len);
	va_start(aq, nbarg);
	i = 0;
	while (i < nbarg)
	{
		ft_strcat(str, va_arg(aq, char *));
		i++;
	}
	va_end(aq);
	return (str);
}
