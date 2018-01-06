/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:36:48 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 10:36:53 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

struct dirent	*ft_direntdup(struct dirent *dir)
{
	struct dirent	*cp;

	if (!(cp = (struct dirent *)malloc(sizeof(struct dirent))))
		exit(EXIT_FAILURE);
	cp->d_type = dir->d_type;
	ft_strcpy(cp->d_name, dir->d_name);
	return (cp);
}
