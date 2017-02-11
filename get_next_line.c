/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:22:27 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 18:39:14 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_buffer(int fd, char **result)
{
	char			*result2;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	ret = 1;
	while (ft_strsrchi(*result, '\n') == -1 && ret)
	{
		result2 = *result;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*result = ft_strjoin(result2, buf);
		ft_strdel((char**)&result2);
	}
	if (ret == 0 && *result[0] == 0)
	{
		ft_strdel(result);
		return (0);
	}
	return (1);
}

char	**backremain(int fd, t_list **tmp, t_list **list)
{
	t_gnl	*gnl;
	t_list	*link;

	*tmp = *list;
	while (*tmp != NULL && fd != ((t_gnl*)((*tmp)->content))->fd)
		*tmp = (*tmp)->next;
	if (*tmp == NULL)
	{
		link = ft_lstnew(&gnl, sizeof(t_gnl));
		ft_lstadd(list, link);
		*tmp = *list;
		(((t_gnl *)((*tmp)->content))->fd) = fd;
		(((t_gnl *)((*tmp)->content))->remain) = NULL;
	}
	return (&(((t_gnl *)((*tmp)->content))->remain));
}

void	free_list(t_list **tmp, t_list **list)
{
	t_list		*tmp2;

	tmp2 = *list;
	while (tmp2 != *tmp && *tmp != tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = (*tmp)->next;
	if (tmp2 == *tmp)
		*list = (*tmp)->next;
	ft_memdel((void**)(&((*tmp)->content)));
	ft_memdel((void**)(tmp));
}

/*
** stock = Contain the return value of read_buffer AND browse result.
** result = Result of buf and tmp->content->remain.
** stock + 1 = index / &ret + 1 = pointer starting at ret+1 to keep the string.
** sizeof(t_gnl) = int + char * = 12.
*/

int		get_next_line(const int fd, char **line)
{
	int				stock;
	char			*result;
	static t_list	*list = NULL;
	t_list			*tmp;
	char			**remain;

	remain = backremain(fd, &tmp, &list);
	result = (*remain == NULL) ? ft_strnew(0) : ft_strdup(*remain);
	ft_strdel(remain);
	if ((stock = read_buffer(fd, &result)) != 1)
	{
		free_list(&tmp, &list);
		return (stock);
	}
	stock = 0;
	while (result[stock] != '\0' && result[stock] != '\n')
		stock++;
	*line = ft_strsub(result, 0, stock);
	if (result[stock] == '\n')
		*remain = ft_strdup(&result[stock + 1]);
	ft_strdel((char**)&result);
	return (1);
}
