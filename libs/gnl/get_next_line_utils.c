/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:35:57 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/10 10:06:54 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_memoire_chr(void *s, int c, size_t n)
{
	size_t		k;

	k = 0;
	while (k < n)
	{
		if (((char *)s)[k] == (char)c)
		{
			k++;
			return (k);
		}
		k++;
	}
	return (0);
}

void	*ft_memoire_cpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_copy_alloc(size_t count, size_t size)
{
	size_t		i;
	char		*pt;

	i = 0;
	pt = malloc(size * count);
	if (pt == NULL)
		return (pt);
	while (i < size * count)
	{
		pt[i] = 0;
		i++;
	}
	return (pt);
}

void	*ft_memoire_dup(void *src, size_t len)
{
	char	*mem;

	mem = ft_copy_alloc(len + 1, sizeof(char));
	if (!mem)
		return (NULL);
	ft_memoire_cpy(mem, src, len);
	return (mem);
}

void	*ft_memoire_join(void *m1, void *m2, size_t size1, size_t size2)
{
	char	*mem;

	mem = NULL;
	if ((m1 && size1 > 0) && (m2 != NULL && size2 > 0))
	{
		mem = ft_copy_alloc((size1 + size2 + 1), sizeof(char));
		if (!mem)
			return (NULL);
		ft_memoire_cpy(mem, m1, (size1));
		ft_memoire_cpy(&mem[size1], m2, (size2));
	}
	else if ((m1 == NULL && size1 == 0) && (m2 != NULL && size2 > 0))
		mem = ft_memoire_dup(m2, size2);
	else
		mem = ft_memoire_dup(m1, size1);
	return (mem);
}
