/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:50:08 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/17 18:15:47 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_back(char *c, t_list **list, int size, int flag)
{
	t_list	*tmp;
	t_list	*p;

	tmp = *list;
	p = malloc(sizeof(t_list));
	if (!p)
		return ;
	p->c = ft_strdup(c, size, flag);
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

int	checkbuff(char *buff, int **size)
{
	int	i;
	int	flag;

	i = 0;
	if (**size != 0)
		i = **size;
	flag = i;
	**size = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			**size = i + 1;
			return (flag);
		}
		i++;
	}
	return (flag);
}

t_list	*newl(char *buff, int *size, t_list *list, int *nl)
{
	int	flag;

	*nl = 0;
	flag = checkbuff(buff, &size);
	add_back(buff, &list, *size, flag);
	if (*size != 0)
	{
		if (buff[*size] == '\0')
			*size = 0;
		*nl = -1;
	}
	return (list);
}

char	*get_next_line(int fd)
{
	t_list		*list;
	static int	size;
	int			flag;
	static char	buff[BUFFER_SIZE + 1];
	char		*str;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	while (1)
	{
		if (size == 0)
		{
			flag = read(fd, buff, BUFFER_SIZE);
			buff[flag] = '\0';
		}
		if (ft_strlen(buff) == 0)
			break ;
		list = newl(buff, &size, list, &flag);
		if (flag == -1)
			break ;
	}
	str = ft_str(ft_count(list), &list);
	return (str);
}