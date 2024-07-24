/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo_txtfc.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:56:03 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/09 17:43:10 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/pars.h"

t_error	ft_get_wtxt(void **stct, char *s)
{
	int		i;

	i = -1;
	if (s == NULL)
		return (E_ERROR);
	if (ft_strnstr_nb(s, " ./", ft_strlen(s)) != 1)
		return (E_STOP);
	while (s[++i] != '.')
	{
	}
	*stct = ft_strdup(&s[i]);
	if (*stct == NULL)
		return (E_ERROR);
	return (E_TRUE);
}
