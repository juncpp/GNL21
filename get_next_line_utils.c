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
/*
static void	ft_inic(size_t *k, size_t *j, size_t *i)
{
	*k = 0;
	*j = 0;
	*i = 0;
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	tmp;

	ft_inic(&k, &j, &i);
	tmp = dstsize;
	while (src[k] != '\0')
		k++;
	while (dst[i] != '\0' && tmp != 0)
	{
		i++;
		tmp--;
	}
	if (tmp == 0)
		return (dstsize + k);
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (k + i - j);
}
*/
