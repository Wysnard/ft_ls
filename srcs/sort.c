/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:58:05 by vlay              #+#    #+#             */
/*   Updated: 2018/01/07 16:17:37 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	ft_lstcompare(void *s1, void *s2)
{
	t_ls	*l1;
	t_ls	*l2;

	l1 = (t_ls *)s1;
	l2 = (t_ls *)s2;
	return (ft_strcmp(l2->path, l1->path));
}

int	ft_lstsorttime(void *s1, void *s2)
{
	t_ls	*l1;
	t_ls	*l2;

	l1 = (t_ls *)s1;
	l2 = (t_ls *)s2;
	return (l1->st->st_mtime - l2->st->st_mtime);
}
