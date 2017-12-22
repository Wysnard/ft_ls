#include "ls.h"

struct stat	*ft_statcpy(char *path, unsigned char d_type)
{
	struct stat	st;
	struct stat	*cp;

	(d_type == DT_LNK) ? lstat(path, &st) : stat(path, &st);
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
