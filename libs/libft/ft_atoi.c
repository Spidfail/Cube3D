/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:32:12 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 08:22:31 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_max(long int nb, int sgn)
{
	if (sgn > 0)
	{
		if (nb > INT_MAX)
			return (INT_MAX);
	}
	else if (sgn < 0)
		if ((nb * -1) < INT_MIN)
			return (INT_MIN);
	return (1);
}

static int	ft_build_number(const char *str, size_t i, int sgn)
{
	long int	rtn;

	rtn = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		if (ft_check_max(rtn, sgn) == INT_MIN)
			return (INT_MIN);
		else if (ft_check_max(rtn, sgn) == INT_MAX)
			return (INT_MAX);
		i++;
	}
	return (rtn * sgn);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sgn;

	i = 0;
	sgn = 1;
	if (str == NULL)
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn *= -1;
		i++;
	}
	return (ft_build_number(str, i, sgn));
}
