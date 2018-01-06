#include "ls.h"

void	ft_procarg(t_list **file, char *opt)
{
	ft_lstiter(*file, &ft_initfile);
	if (!ft_strchr(opt, 'f'))
		(ft_strchr(opt, 't')) ?
		ft_lstmergesort(file, &ft_lstsorttime) : ft_lstmergesort(file, &ft_lstcompare);
	if (ft_strchr(opt, 'r'))
		ft_lstrev(file);
	ft_getspace(*file);
	ft_usrspace(*file);
}

void	ft_argdir(t_list *dir, char *opt)
{
	ft_procarg(&dir, opt);
	while (dir)
	{
		if (!ft_strchr(opt, 'R'))
			ft_printf("%s:\n", LCONT(dir)->path);
		ft_ls(LCONT(dir)->path, opt);
		if (dir->next)
			ft_putchar('\n');
		dir = dir->next;
	}
}

void	ft_managearg(int argc, char **argv, char *opt)
{
	static	t_list	*dir = NULL;
	static	t_list	*file = NULL;
	int	i;
	int	cat;

	i = 1;
	cat = 0;
	while (i < argc)
	{
		if (*argv[i] != '-' && (cat = ft_category(argv[i])) > 0)
			ft_lstpushadd(&dir, ft_lstsnew(
				ft_registerls(NULL, argv[i], opt), sizeof(t_ls)));
		else if (*argv[i] != '-' && cat == -1)
			ft_lstpushadd(&file, ft_lstsnew(
				ft_registerls(NULL, argv[i], opt), sizeof(t_ls)));
		i++;
	}
	ft_procarg(&file, opt);
	ft_lstiter(file, (ft_strchr(opt, 'l')) ? &ft_prtl : &ft_prtlst);
	if (file)
	{
		ft_lstdel(&file, &ft_lstd);
		ft_putchar('\n');
	}
	ft_argdir(dir, opt);
	if (dir)
		ft_lstdel(&dir, &ft_lstd);
}
