/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsvchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:55:59 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/25 15:33:30 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** This function is nearly identical to strchr, but instead of searching
** one char, you can check several others. The char are listed in 'chcmp'
** parameter by the user.
*/

char	*ft_strsvchr(const char *s, char *chcmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (chcmp == NULL)
		return (NULL);
	while (s[i])
	{
		while (chcmp[j])
		{
			if (s[i] == chcmp[j])
				return (&chcmp[j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
