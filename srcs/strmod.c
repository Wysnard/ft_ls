#include "ls.h"

char	ft_gettypec(unsigned char d_type)
{
	static	unsigned char	type[] = {
		DT_BLK, DT_CHR, DT_DIR, DT_FIFO, DT_LNK, DT_REG, DT_SOCK, DT_UNKNOWN
	};
	static	char	res[] = "bcdpl-s ";
	return(res[ft_strchri((char *)type, d_type)]);
}

void	ft_strmod(mode_t mode, char *buf)
{
	static	char	mod[] = "rwxrwxrwx";
	size_t	i;

	i = 0;
	while (i < 9)
	{
		buf[i] = mode & (1 << (8 - i)) ? mod[i] : '-';
		i++;
	}
	buf[9] = '\0';
}
