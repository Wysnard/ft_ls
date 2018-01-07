/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:48:11 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:48:19 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;
	char	*opt;

	i = 1;
	opt = ft_opt(argc, argv, OPT);
	if (ft_morearg(argc, argv) == 0)
		ft_ls(".", opt);
	else
		ft_managearg(argc, argv, opt);
	free(opt);
	return (0);
}
