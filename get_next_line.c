/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:50:08 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/09 17:33:49 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	add_back(char *c, t_list **list)
{
	t_list	*tmp;
	t_list	*p;

	tmp = *list;
	p = malloc(sizeof(t_list));
	if (!p)
		return ;
	p->c = ft_strdup(c);
	p->next = NULL;
	if (tmp == NULL)
		*list = p;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = p;
		
	}
}

char	*get_next_line(int fd)
{
	t_list			*list;
	int				size;
	int				flag;
	char			buff[BUFFER_SIZE + 1];
	char			*str;

	flag = 0;
	size = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	while (flag != -1)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag > 0)
		{
			buff[flag] = '\0';
			if (buff[0] == '\n')
			{
				add_back(&buff[0], &list);
				flag = -1;
			}
			else
				add_back(&buff[0], &list);
			size++;
		}
		else
			break ;
		size = 0;
	}
	size = ft_count(list);
	str = ft_str(size, &list);
	if (str == NULL)
		free(str);
	return (str);
}