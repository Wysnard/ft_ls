/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:37:00 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:37:32 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	ft_openerr(const char *path, char *opt)
{
	if (ft_strchr(opt, 'R'))
		ft_printf("%s:\n", path);
	ft_putstr_fd("ls: ", 2);
	perror(ft_strrchr(path, '/') ? ft_strrchr(path, '/') + 1 : path);
	return (1);
}
