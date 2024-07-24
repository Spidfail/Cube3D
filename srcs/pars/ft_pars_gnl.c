/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:12:31 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 16:21:17 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pars.h"
#include "../../inc/global_error.h"

t_error	ft_parsing_gnl_info(int fd, t_displ *dspl)
{
	ssize_t		grtn;

	dspl->buff = ft_free(dspl->buff);
	grtn = get_next_line(fd, &dspl->buff);
	if (grtn == -1)
		return (ft_error_node(PS_INF, EI_WFD, 0, NULL));
	else if (grtn == 0)
		return (ft_error_node(PS_INF, EI_WEOF, 0, NULL));
	dspl->lnu++;
	return (E_TRUE);
}

t_error	ft_pars_skip_empty_line(int fd, char **s, size_t *lnu)
{
	ssize_t		grtn;

	grtn = 1;
	while (ft_isemptyline(*s) == E_TRUE && grtn == 1)
	{
		*s = ft_free(*s);
		grtn = get_next_line(fd, s);
		if (lnu)
			(*lnu)++;
	}
	if (-1 == grtn)
		return (ft_error_node(PS_GEN, 4, 0, "ft_pars_skip_line"));
	return (E_TRUE);
}

t_error	ft_parsing_gnl_map(int fd, char **s, t_map *map, bool *berr)
{
	ssize_t		grtn;

	if (*s != NULL)
		return (E_TRUE);
	grtn = get_next_line(fd, s);
	if (grtn == -1)
		return (ft_error_node(PS_MAP, EM_WFD, 0, NULL));
	if (grtn == 0)
	{
		if (map->plyor == 0 && *berr == true)
			return (ft_error_node(PS_MAP, EM_WEOF, 0, NULL));
		return (E_STOP);
	}
	map->lnu++;
	return (E_TRUE);
}

int	ft_check_path(char *s, t_path path)
{
	size_t		i;
	int			fd;

	i = ft_strlen(s);
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (ft_error_print("[PARS] Incorrect file name [-.cub] ",
				"ft_check_path", E_ERROR));
	if (path == PTH_MAP)
	{
		if ((i > 5 && i < 255)
			&& 0 == ft_strncmp(&s[ft_strlen(s) - 4], ".cub", 4))
			if (ft_isstr(s, IS_PRINT))
				return (fd);
		return (E_ERROR);
	}
	return (E_ERROR);
}
