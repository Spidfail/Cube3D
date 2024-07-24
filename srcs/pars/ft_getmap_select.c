/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap_select.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:49:37 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 15:04:34 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/leader.h"
#include "../../inc/pars.h"

t_error	ft_getmap_chained_map(t_map *map, char *s)
{
	t_list		*nlist;

	if (s == NULL)
		return (E_ERROR);
	nlist = ft_lstnew(ft_strdup(s));
	if (map->lstmap)
		ft_lstadd_back(&map->lstmap, nlist);
	else
		map->lstmap = nlist;
	nlist = map->lstmap;
	if (map->lstmap == NULL || ft_lstlast(nlist) == NULL)
		return (ft_error_node(PS_MAP, EM_WSTP, 0, "ft_getmap_chained_map"));
	return (E_TRUE);
}

static t_error	ft_getmap_player_position(t_map *map, size_t x, size_t y)
{
	if (map->plyor != 0)
		return ((ft_error_node(PS_MAP, EM_WSTP, 0, "ft_getmap_chk")));
	map->plyxy[0] = x;
	map->plyxy[1] = y;
	map->plyor = map->buff[x];
	return (E_TRUE);
}

t_error	ft_getmap_set_positions(t_map *map, char *s, size_t i, bool *berr)
{
	t_mpars		mapenum;

	mapenum = ft_get_enum_map(s[i]);
	while ((mapenum != M_OUT || s[i] == ' ') && s[i])
	{
		if (mapenum == M_1)
			ft_getmap_size(mapenum, map, i, map->lnu);
		if (mapenum >= M_NO && mapenum <= M_EA)
		{
			if (ft_getmap_player_position(map, i, map->lnu) == E_ERROR)
			{
				*berr = false;
				printf("\n");
				ft_print_line(map->buff, map->lnu + 1);
				return (ft_error_node(PS_MAP, 0, 0, "ft_getmap_set_positions"));
			}
		}
		i++;
		mapenum = ft_get_enum_map(s[i]);
	}
	return (E_TRUE);
}
