/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:58:21 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/08 20:58:24 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcreate(char *dst, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (*src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

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
	str[0] = '\0';
	tmp = *list;
	while (tmp != NULL)
	{
		str = ft_strcreate(str, tmp->c);
		*list = (*list)->next;
		free(tmp->c);
		free(tmp);
		tmp = *list;
		i++;
	}
	return (str);
}

int	ft_count(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i += ft_strlen(list->c);
		list = list->next;
	}
	return (i);
}
