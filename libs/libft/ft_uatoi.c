/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:45:04 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 08:28:02 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** uatoi takes a str with positive number ; so a '-' before any number
** return 0. '+' is still checked.
*/

static int	ft_check_intmax(unsigned long int rtn)
{
	if (rtn > UINT_MAX)
		return (1);
	else
		return (0);
}

unsigned int	ft_uatoi(const char *str)
{
	size_t				i;
	unsigned long int	rtn;

	i = 0;
	rtn = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		if (ft_check_intmax(rtn))
			return (0);
		i++;
	}
	return (rtn);
}
