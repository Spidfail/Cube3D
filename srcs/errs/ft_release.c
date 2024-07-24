/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_release.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:01:32 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/23 12:53:17 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/pars.h"

t_error	ft_dblfree(void **pt, int nb)
{
	int		i;

	i = 0;
	if (pt == NULL || nb == 0)
		return (E_ERROR);
	while (i <= nb)
	{
		pt[i] = ft_free(pt[i]);
		i++;
	}
	pt = ft_free(pt);
	return (E_ERROR);
}

t_error	ft_clean_dsplcomplete(t_displ *dspl)
{
	dspl->buff = ft_free(dspl->buff);
	dspl->no = ft_free(dspl->no);
	dspl->we = ft_free(dspl->we);
	dspl->ea = ft_free(dspl->ea);
	dspl->so = ft_free(dspl->so);
	dspl->spr = ft_free(dspl->spr);
	dspl->ceilg = ft_free(dspl->ceilg);
	dspl->floor = ft_free(dspl->floor);
	dspl->title = ft_free(dspl->title);
	dspl->res[0] = 0;
	dspl->res[1] = 0;
	dspl->fhex = 0;
	dspl->chex = 0;
	dspl->lnu = 0;
	return (E_ERROR);
}

t_error	ft_clean_mapcomplete(t_map *map)
{
	if (map->map)
		ft_dblfree((void **)map->map, map->m_y[1]);
	map->buff = ft_free(map->buff);
	map->name = ft_free(map->buff);
	if (map->lstmap)
	{
		ft_lstclear(&(map->lstmap), free);
		map->lstmap = NULL;
	}
	map->m_y[0] = 0;
	map->m_y[1] = 0;
	map->m_x[0] = 0;
	map->m_x[1] = 0;
	map->plyxy[0] = 0;
	map->plyxy[1] = 0;
	map->plyor = 0;
	map->i = 0;
	map->lnu = 0;
	return (E_ERROR);
}

t_error	ft_parsclean(t_error e, t_map *map, t_displ *dspl)
{
	if (e == E_ERROR || e == E_STOP)
	{
		ft_clean_dsplcomplete(dspl);
		ft_clean_mapcomplete(map);
	}
	else
	{
		dspl->buff = ft_free(dspl->buff);
		dspl->i = 0;
		dspl->lnu = 0;
		map->buff = ft_free(map->buff);
		map->i = 0;
		dspl->lnu = 0;
	}
	return (e);
}

t_error	ft_clean_gnl(t_error e, char **s, t_list **lst)
{
	if (*s)
		*s = ft_free(*s);
	if (lst)
	{
		ft_lstclear(lst, free);
		lst = NULL;
	}
	return (e);
}
