/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:56:23 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 16:13:10 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/pars.h"
#include "../../libs/ulyss/ulyss.h"

static t_error	ft_pars_getinfo(t_displ *dspl, t_map *map, int fd)
{
	size_t	i;
	t_error	e;

	i = 0;
	e = E_TRUE;
	while (e == E_TRUE)
	{
		if (!ft_parsing_gnl_info(fd, dspl))
			return (ft_clean_gnl(E_ERROR, &dspl->buff, NULL));
		if (!ft_pars_skip_empty_line(fd, &dspl->buff, &dspl->lnu))
			ft_error_node(PS_MAP, EM_WEOF, 0, "ft_pars_skip_empty_line");
		i = ft_space_escape(dspl->buff, i);
		e = ft_getinfo_node_parsing(i, dspl, e);
		i = 0;
	}
	ft_getinfo_skip_id_lines(fd, dspl);
	map->buff = ft_strdup(dspl->buff);
	if (e == E_ERROR)
		return (ft_clean_gnl(e, &dspl->buff, NULL));
	return (ft_clean_gnl(E_TRUE, &dspl->buff, NULL));
}

static t_error	ft_pars_getmap(t_map *map, int fd)
{
	t_error		e;
	bool		berr;

	e = E_TRUE;
	berr = true;
	while (e == E_TRUE)
	{
		map->i = 0;
		e = ft_parsing_gnl_map(fd, &map->buff, map, &berr);
		if (e == E_TRUE)
			e = ft_getmap_line_exam(map->buff, map, &berr);
		if (e == E_TRUE && berr == true)
		{
			map->i = ft_space_escape(map->buff, map->i);
			e = ft_getmap_set_positions(map, map->buff, map->i, &berr);
			if (e && berr == true)
				e = ft_getmap_chained_map(map, map->buff);
		}
		ft_clean_gnl(e, &map->buff, NULL);
	}
	if (e == E_ERROR || berr == false)
		return (ft_clean_gnl(E_ERROR, &map->buff, &(map->lstmap)));
	return (ft_clean_gnl(e, &map->buff, NULL));
}

static t_error	ft_pars_node(t_map *map, t_displ *dspl, int fd, t_error *e)
{
	*e = ft_pars_getinfo(dspl, map, fd);
	if (*e == E_TRUE || *e == E_STOP)
		*e = ft_pars_checkinfo(dspl);
	if (*e == E_TRUE || *e == E_STOP)
		*e = ft_pars_skip_empty_line(fd, &map->buff, NULL);
	if (*e == E_TRUE)
		*e = ft_pars_getmap(map, fd);
	return (*e);
}

t_error	ft_pars(t_map *map, t_displ *dspl, char *s)
{
	int				fd;
	t_error			e;

	e = 0;
	fd = ft_check_path(s, PTH_MAP);
	if (fd == -1)
		return (ft_parsclean(ft_error_node(PS_INF, EI_WFD, 0, NULL),
				map, dspl));
	e = ft_pars_node(map, dspl, fd, &e);
	if (close(fd) != 0)
		return (ft_parsclean(ft_error_node(PS_INF, EI_WFD, 0, NULL),
				map, dspl));
	if (e == E_ERROR)
		return (ft_parsclean(E_ERROR, map, dspl));
	ft_parsclean(E_TRUE, map, dspl);
	map->map = ft_map_copy_list(map, &map->lstmap);
	if (map->map == NULL)
		return (ft_parsclean(E_ERROR, map, dspl));
	if (ft_map_transform(map) == E_ERROR)
		return (ft_parsclean(E_ERROR, map, dspl));
	return (E_TRUE);
}
