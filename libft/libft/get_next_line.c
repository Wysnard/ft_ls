/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:20:33 by vlay              #+#    #+#             */
/*   Updated: 2017/12/19 15:47:06 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		ft_lstadd(list, ft_lstnew(NULL, fd));
		(*list)->content_size = fd;
		tmp = *list;
	}
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*buf;
	static	t_list	*list;
	t_list			*current;

	if (fd < 0 || GET_SIZE < 1 || !(buf = ft_strnew(GET_SIZE))
	|| read(fd, "", 0) < 0 || !(current = ft_lstfind(&list, fd)))
		return (-1);
	while ((ret = read(fd, buf, GET_SIZE)))
	{
		buf[ret] = '\0';
		current->content = ft_strjoinadd((char **)&current->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (!current->content || (ret < GET_SIZE && !ft_strlen(current->content)))
		return (0);
	*line = (current->content) ?
	ft_strndup(current->content, ft_strchri(current->content, '\n')) : NULL;
	(*line && ft_strlen(*line) < ft_strlen(current->content)) ?
	ft_strcpy(current->content, ft_strchr(current->content, '\n') + 1) :
	ft_strclr(current->content);
	return (1);
}
