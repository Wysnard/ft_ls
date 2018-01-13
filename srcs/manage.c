/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:48:44 by vlay              #+#    #+#             */
/*   Updated: 2018/01/13 15:50:54 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_procarg(t_list **file, char *opt)
{
	ft_lstiter(*file, &ft_initfile);
	if (!ft_strchr(opt, 'f'))
		(ft_strchr(opt, 't')) ?
		ft_lstmergesort(file, &ft_lstsorttime)
		: ft_lstmergesort(file, &ft_lstcompare);
	if (ft_strchr(opt, 'r'))
		ft_lstrev(file);
	ft_getspace(*file);
	ft_usrspace(*file);
}

void	ft_argdir(t_list *dir, char *opt, int len)
{
	t_list	*tmp;

	tmp = dir;
	ft_procarg(&tmp, opt);
	while (tmp)
	{
		if (len > 1)
			ft_printf("%s:\n", LCONT(tmp)->path);
		ft_ls(LCONT(tmp)->path, opt);
		if (tmp->next)
			ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	ft_managearg(int argc, char **argv, char *opt, int len)
{
	static	t_list	*dir = NULL;
	static	t_list	*file = NULL;
	static	int		i = 1;
	static	int		cat = 0;

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
		if (dir)
			ft_putchar('\n');
	}
	ft_argdir(dir, opt, len);
	ft_lstdel(&dir, &ft_lstd);
}
