/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:47:57 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:48:00 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int	ft_lstdir(t_list *list)
{
	t_ls	*ls;

	ls = LCONT(list);
	ft_prtlst(list);
	return ((ls->dir->d_type == DT_DIR) ? 1 : 0);
}

int	ft_lstdirl(t_list *list)
{
	t_ls	*ls;

	ls = LCONT(list);
	ft_prtl(list);
	return ((ls->dir->d_type == DT_DIR) ? 1 : 0);
}
