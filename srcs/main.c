#include "ls.h"

int	ft_morearg(int argc, char **argv)
{
	int	i;
	int	ct;

	i = 1;
	ct = 0;
	while (i < argc)
	{
		if (*argv[i] != '-')
			ct++;
		i++;
	}
	return (ct);
}

int	ft_lstlsapplyfile(t_list *list, char *opt, int mode, int saut, t_lsfile file)
{
	int	ret;

	ret = 0;
	if (saut)
		ft_putchar('\n');
	while (list)
	{
		ret = 1;
		if (mode == 1)
			ft_printf("%s:\n", list->content);
		ft_lsfile(list->content, opt, file);
		if (list->next && mode != 2)
			ft_putchar('\n');
		list = list->next;
	}
	return (ret);
}

int	ft_lstlsapply(t_list *list, char *opt, int mode, int saut)
{
	int	ret;

	ret = 0;
	if (saut)
		ft_putchar('\n');
	while (list)
	{
		ret = 1;
		if (mode == 1)
			ft_printf("%s:\n", list->content);
		ft_ls(list->content, opt);
		if (list->next && mode != 2)
			ft_putchar('\n');
		list = list->next;
	}
	return (ret);
}

int	ft_lstcmpcont(void *s1, void *s2)
{
	return (ft_strcmp((char *)s2, (char *)s1));
}

void	ft_managearg(int argc, char **argv, char *opt)
{
	static	t_list	*noexist = NULL;
	static	t_list	*file = NULL;
	static	t_list	*dir = NULL;
	static	t_list	*error = NULL;
	int	i;
	int	cat;
	t_lsfile		lsfile;

	i = 1;
	while (i < argc)
	{
		if (*argv[i] != '-')
		{
			cat = ft_category(argv[i]);
		if (cat == -2)
			ft_lstpushadd(&noexist, ft_lstsnew(ft_strdup(argv[i]), sizeof(char)));
		else if (cat == -1)
			ft_lstpushadd(&error, ft_lstsnew(ft_strdup(argv[i]), sizeof(char)));
		else if (cat == 0)
			ft_lstpushadd(&file, ft_lstsnew(ft_strdup(argv[i]), sizeof(char)));
		else
			ft_lstpushadd(&dir, ft_lstsnew(ft_strdup(argv[i]), sizeof(char)));
		}
		i++;
	}
	if (!ft_strchr(opt, 'f'))
	{
		ft_lstmergesort(&noexist, &ft_lstcmpcont);
		ft_lstmergesort(&error, &ft_lstcmpcont);
		ft_lstmergesort(&file, &ft_lstcmpcont);
		ft_lstmergesort(&dir, &ft_lstcmpcont);
	}
	lsfile = ft_filemax(error);
	cat = ft_lstlsapply(file, opt, 0, 0);
	cat = (ft_strchr(opt, 'r')) ? ft_lstlsapply(error, opt, 1, cat) : ft_lstlsapply(dir, opt, 1, cat);
	(ft_strchr(opt, 'r')) ? ft_lstlsapply(dir, opt, 1, cat) : ft_lstlsapply(error, opt, 1, cat);
}

int	main(int argc, char **argv)
{
	int	i;
	char	*opt;
	int		nbarg;

	i = 1;
	opt = ft_opt(argc, argv, OPT);
	if ((nbarg = ft_morearg(argc, argv)) == 0)
		ft_ls(".", opt);
	else
	{
		// ft_managearg(argc, argv, opt);
		while (i < argc)
		{
			if (nbarg > 1)
				ft_printf("%s:\n", argv[i]);
			if (*argv[i] != '-')
				ft_ls(argv[i], opt);
			if (nbarg > 1)
				ft_putchar('\n');
			i++;
		}
	}
	free(opt);
	return (0);
}
