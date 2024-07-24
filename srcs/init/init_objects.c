#include "../../inc/build.h"
#include "../../inc/leader.h"

static t_error	ft_set_get_objects(t_map *map, t_objlst *objlst)
{
	objlst->lst_thgs = NULL;
	objlst->plan_north = ft_calloc(map->m_y[1] + 4, sizeof(t_plist *));
	objlst->plan_south = ft_calloc(map->m_y[1] + 4, sizeof(t_plist *));
	if (!objlst->plan_north || !objlst->plan_south)
	{
		ft_kill_all_objects(objlst, map, E_ERROR);
		return (ft_error_print("[OBJ BUILD] Failed to allocate horizontal obj ",
				"ft_set_get_objects", E_ERROR));
	}
	objlst->plan_west = ft_calloc(map->m_x[1] + 4, sizeof(t_plist *));
	objlst->plan_east = ft_calloc(map->m_x[1] + 4, sizeof(t_plist *));
	if (!objlst->plan_east || !objlst->plan_west)
	{
		ft_kill_all_objects(objlst, map, E_ERROR);
		return (ft_error_print("[OBJ BUILD] Failed to allocate vertical obj ",
				"ft_set_get_objects", E_ERROR));
	}
	objlst->plan_north[map->m_y[1] + 2] = NULL;
	objlst->plan_south[map->m_y[1] + 2] = NULL;
	objlst->plan_west[map->m_x[1] + 2] = NULL;
	objlst->plan_east[map->m_x[1] + 2] = NULL;
	return (E_TRUE);
}

static t_error	ft_set_me(t_objlst *objlst, t_list *tmp, int i)
{
	if (!tmp)
		return (ft_error_print("[INIT] The sprite list hasn't been allocated ",
				"ft_transform_things_list", E_ERROR));
	objlst->things = ft_calloc(i + 1, sizeof(t_sprite *));
	if (!objlst->things)
		return (ft_error_print("[OBJ BUILD] Failed to allocate things' array ",
				"ft_set_get_objects", E_ERROR));
	objlst->things[i] = NULL;
	objlst->sp_max = i - 1;
	objlst->issprite = true;
	return (E_TRUE);
}

static t_error	ft_transform_things_list(t_objlst *objlst)
{
	int		i;
	t_list	*tmp;

	i = ft_lstsize(objlst->lst_thgs);
	if (i == 0)
	{
		objlst->issprite = false;
		return (E_STOP);
	}
	tmp = objlst->lst_thgs;
	if (ft_set_me(objlst, tmp, i) == E_ERROR)
		return (E_ERROR);
	while (--i > -1 && tmp)
	{
		objlst->things[i] = ft_calloc(1, sizeof(t_sprite));
		if (!objlst->things[i])
			return (ft_free_things(objlst, i,
					ft_lstsize(objlst->lst_thgs), E_ERROR));
		objlst->things[i]->plan_ray = tmp->content;
		tmp = tmp->next;
	}
	ft_lstcleanlst(&objlst->lst_thgs, free);
	return (E_TRUE);
}

static t_error	ft_check_objects(t_map *map, t_objlst *objlst)
{
	size_t		i;

	i = -1;
	while (++i <= map->m_y[1] + 1)
		printf(" NORTH = %p -----  %zu\n", objlst->plan_north[i], i);
	i = -1;
	while (++i <= map->m_y[1] + 1)
		printf(" SOUTH = %p -----  %zu\n", objlst->plan_south[i], i);
	i = -1;
	while (++i <= map->m_x[1] + 1)
		printf(" WEST = %p -----  %zu\n", objlst->plan_west[i], i);
	i = -1;
	while (++i <= map->m_x[1] + 1)
		printf(" EAST = %p -----  %zu\n", objlst->plan_east[i], i);
	i = -1;
	while (objlst->things[++i])
		printf(" THINGS = %p -----  x = %f  y = %f\n", objlst->things[i],
			objlst->things[i]->plan_ray->point_xy[0],
			objlst->things[i]->plan_ray->point_xy[1]);
	return (E_TRUE);
}

t_error	ft_init_objects(t_rsrcs *rsrcs)
{
	t_error		e;

	e = E_TRUE;
	if (ft_set_get_objects(rsrcs->map, rsrcs->objlst) == E_ERROR)
		return (E_ERROR);
	if (ft_get_objects(rsrcs->map, rsrcs->objlst) == E_ERROR)
		return (E_ERROR);
	e = ft_transform_things_list(rsrcs->objlst);
	if (e == E_STOP || e == E_ERROR)
		return (e);
	if (ISDEBUG == 1)
		ft_check_objects(rsrcs->map, rsrcs->objlst);
	return (E_TRUE);
}
