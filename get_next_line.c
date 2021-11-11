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

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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

int	checkbuff(char *buff, int *size)
{
	int	i;
	int	flag;

	i = 0;
	if (size != 0)
		i = *size;
	flag = i;
	*size = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			*size = i + 1;
			if (buff[i + 1] == '\0')
				return (flag);
			else
				return (flag);
		}
		i++;
	}
	return (flag);
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
		flag = checkbuff(buff, &size);
		if (size != 0)
		{
			add_back(buff, &list, size, flag);
			if (buff[size] == '\0')
				size = 0;
			break ;
		}
		else
			add_back(buff, &list, size, flag);
	}
	str = ft_str(ft_count(list), &list);
	if (str == NULL)
		free(str);
	return (str);
}
/*int main()
{
    int fd;
    fd = open("input.txt", O_RDONLY);
    printf ("%s", get_next_line(fd));
    printf ("%s", get_next_line(fd));
  printf ("%s", get_next_line(fd));
printf ("%s", get_next_line(fd));
 	printf ("%s", get_next_line(fd));
  	printf ("%s", get_next_line(fd));
 	printf ("%s", get_next_line(fd));
 	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
}*/