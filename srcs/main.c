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
		ft_managearg(argc, argv, opt);
		// while (i < argc)
		// {
		// 	if (nbarg > 1 && *argv[i] != '-')
		// 		ft_printf("%s:\n", argv[i]);
		// 	if (*argv[i] != '-')
		// 		ft_ls(argv[i], opt);
		// 	if (nbarg > 1 && *argv[i] != '-')
		// 		ft_putchar('\n');
		// 	i++;
		// }
	}
	free(opt);
	return (0);
}
