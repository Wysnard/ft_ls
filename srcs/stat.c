/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:16:39 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:16:41 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct stat	*ft_statcpy(char *path)
{
	struct stat	st;
	struct stat	*cp;

	lstat(path, &st);
	if (!(cp = (struct stat *)malloc(sizeof(struct stat))))
		exit(EXIT_FAILURE);
	cp->st_dev = st.st_dev;
	cp->st_rdev = st.st_rdev;
	cp->st_mode = st.st_mode;
	cp->st_nlink = st.st_nlink;
	cp->st_uid = st.st_uid;
	cp->st_gid = st.st_gid;
	cp->st_size = st.st_size;
	cp->st_blksize = st.st_blksize;
	cp->st_blocks = st.st_blocks;
	cp->st_atime = st.st_atime;
	cp->st_mtime = st.st_mtime;
	cp->st_ctime = st.st_ctime;
	return (cp);
}
