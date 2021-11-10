/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:29:05 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/09 17:36:23 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
typedef struct	s_list
{
	char			*c;
	struct s_list	*next;
}				t_list;
char	*ft_strcreate(char *dst, char *src);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_str(int size, t_list **list);
int		ft_count(t_list *list);
char	*get_next_line(int fd);
#endif