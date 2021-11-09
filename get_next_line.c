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

char	*ft_str(int size, t_list **list)
{
	char	*str;
	int		i;
	t_list	*tmp;

	i = 0;
	if (size == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (NULL == str)
		return (NULL);
	tmp = *list;
	while (tmp != NULL)
	{
		str[i] = (tmp)->c;
		*list = (*list)->next;
		free(tmp);
		tmp = *list;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_count(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	add_back(char c, t_list **list)
{
	t_list	*tmp;
	t_list	*p;

	tmp = *list;
	p = malloc(sizeof(t_list));
	if (!p)
		return ;
	p->next = NULL;
	p->c = c;
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
	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	while (flag != -1)
	{
		flag = read(fd, buff, BUFFER_SIZE);
		if (flag > 0)
		{
			buff[flag + size] = '\0';
			while (buff[size] != '\0')
			{
				if (buff[size] == '\n')
				{
					add_back(buff[size], &list);
					flag = -1;
				}
				else
					add_back(buff[size], &list);
				size++;
			}
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
