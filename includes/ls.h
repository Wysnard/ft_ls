/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:33:01 by vlay              #+#    #+#             */
/*   Updated: 2018/01/07 17:47:53 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <sys/xattr.h>

# define OPT "lRartf"
# define LCONT(L) ((t_ls *)L->content)
# define OPENERR "ls: cannot open directory '"
# define MAX_LINKSIZE 4096
# define XATTR_MAXSIZE 1337

typedef struct		s_ls
{
	char			*path;
	off_t			space;
	size_t			lengrp;
	size_t			lenusr;
	unsigned		link;
	struct dirent	*dir;
	struct stat		*st;
	char			only;
}					t_ls;

void				ft_prtl(t_list *elem);
void				ft_prtlst(t_list *elem);
char				ft_gettypec(mode_t d_type);
void				ft_strmod(mode_t mode, char *buf);
int					ft_lstcompare(void *s1, void *s2);
int					ft_lstsorttime(void *s1, void *s2);
struct dirent		*ft_direntdup(struct dirent *dir);
struct stat			*ft_statcpy(char *path);
void				ft_getspace(t_list *list);
int					ft_openerr(const char *path, char *opt);
int					ft_lstdir(t_list *list);
int					ft_lstdirl(t_list *list);
size_t				ft_total(t_list *list);
void				ft_dolnk(t_list *elem);
void				ft_usrspace(t_list *list);
int					ft_category(char *path);
t_ls				*ft_registerls(struct dirent *dir, char *path, char *opt);
void				ft_lstd(void *content, size_t content_size);
size_t				ft_intchri(int *str, int c, size_t len);
void				ft_initfile(t_list *elem);
void				ft_managearg(int argc, char **argv, char *opt);
int					pxattr(const char *path);

void				ft_ls(const char *path, char *opt);

#endif
