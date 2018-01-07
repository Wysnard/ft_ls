/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:17:37 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:17:40 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

size_t	ft_total(t_list *list)
{
	size_t	total;

	total = 0;
	while (list)
	{
		total += LCONT(list)->st->st_blocks;
		list = list->next;
	}
	return (total);
}
