/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:39:21 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:39:27 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_dolnk(t_list *elem)
{
	char	buf[MAX_LINKSIZE];
	size_t	ret;

	ft_bzero(buf, MAX_LINKSIZE);
	ret = readlink(LCONT(elem)->path, buf, MAX_LINKSIZE);
	buf[ret] = '\0';
	ft_printf(" -> %s", buf);
}
