/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbubblesort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:29:50 by vlay              #+#    #+#             */
/*   Updated: 2018/01/14 15:31:01 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstbubblesort(t_list **list, int (*cmpf)(void *, void *))
{
	t_list	*tmp;
	void	*save;
	int	swap;

	if (!list || !*list)
		return ;
	swap = 1;
	while (swap)
	{
		swap = 0;
		tmp = *list;
		while (tmp->next)
		{
			if (cmpf(tmp->content, tmp->next->content) < 0)
			{
				save = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = save;
				swap = 1;
			}
			tmp = tmp->next;
		}
	}
}
