/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:47:19 by vlay              #+#    #+#             */
/*   Updated: 2018/01/10 18:46:05 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_opt(int argc, char **arg)
{
	int		i;
	int		j;
	char	*res;
	char	save[2];

	i = 0;
	res = NULL;
	save[1] = '\0';
	if (!arg)
		return (NULL);
	while (i < argc)
	{
		j = 0;
		if (arg && arg[i] && *arg[i] == '-')
			while (arg[i][j])
			{
				if (!res || !ft_strchr(res, (save[0] = arg[i][j])))
					res = ft_strjoinadd(&res, save);
				j++;
			}
		i++;
	}
	return (res);
}
