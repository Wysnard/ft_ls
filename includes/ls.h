#ifndef LS_H
#define LS_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

# define OPT "lRart"
# define LCONT(L) ((t_ls *)L->content )

typedef struct	s_ls
{
	off_t	space;
	unsigned	link;
	struct dirent	*dir;
	struct stat	*st;
}					t_ls;

void	ft_prtl(t_list *elem);
void	ft_prtlst(t_list *elem);
char	ft_gettypec(unsigned char d_type);
void	ft_strmod(mode_t mode, char *buf);
int	ft_lstcompare(void *s1, void *s2);
int	ft_lstsorttime(void *s1, void *s2);
struct dirent	*ft_direntdup(struct dirent *dir);
struct stat	*ft_statcpy(char *path, unsigned char d_type);
void	ft_getspace(t_list *list);

void	ft_ls(const char *path, char *opt);

#endif
