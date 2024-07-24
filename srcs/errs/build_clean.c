#include "../../inc/build.h"

static t_error	ft_clean_linked_list(t_objlst *objlst, t_error e)
{
	ft_lstclear(&objlst->lst_thgs, free);
	return (e);
}

static t_error	ft_clean_object_array(t_plist **arr, int size, t_error e)
{
	int		i;

	i = -1;
	if (arr == NULL)
		return (e);
	while (++i < size)
		arr[i] = ft_free(arr[i]);
	arr = ft_free(arr);
	return (e);
}

t_error	ft_free_things(t_objlst *objlst, int i, int tmp_i, t_error e)
{
	if (!objlst->things && e != E_ERROR)
		return (ft_error_print("[ERRS] ERROR, sprites array aren't allocated ",
				"ft_free_things", E_ERROR));
	else if (!objlst->things)
		return (E_ERROR);
	else if (e == E_ERROR)
		return (ft_error_print("[INIT] Failed to allocate things structs ",
				"ft_free_things", E_ERROR));
	while (--tmp_i > i)
	{
		objlst->things[tmp_i]->plan_ray
			= ft_free(objlst->things[tmp_i]->plan_ray);
		objlst->things[tmp_i] = ft_free(objlst->things[tmp_i]);
	}
	objlst->things = ft_free(objlst->things);
	return (e);
}

t_error	ft_kill_all_objects(t_objlst *objlst, t_map *map, t_error e)
{
	int		size_x;
	int		size_y;

	size_x = map->m_x[1] + 1;
	size_y = map->m_y[1] + 1;
	ft_clean_object_array(objlst->plan_north, size_y, e);
	ft_clean_object_array(objlst->plan_south, size_y, e);
	ft_clean_object_array(objlst->plan_west, size_x, e);
	ft_clean_object_array(objlst->plan_east, size_x, e);
	objlst->plan_ceil = ft_free(objlst->plan_ceil);
	objlst->plan_floor = ft_free(objlst->plan_floor);
	if (objlst->issprite == true)
		ft_free_things(objlst, -1, objlst->sp_max + 1, e);
	if (objlst->lst_thgs)
		ft_clean_linked_list(objlst, e);
	return (e);
}
