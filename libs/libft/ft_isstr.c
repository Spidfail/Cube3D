/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:22:50 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/02 17:59:05 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isfct(int c, t_is id)
{
	int		(*is[6])(int);

	is[0] = &ft_isalnum;
	is[1] = &ft_isalpha;
	is[2] = &ft_isascii;
	is[3] = &ft_isdigit;
	is[4] = &ft_isprint;
	is[5] = &ft_isspace;
	return (is[id](c));
}

int	ft_isstr(char *s, t_is id)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (!ft_isfct(s[i], id))
			return (0);
		i++;
	}
	return (1);
}
