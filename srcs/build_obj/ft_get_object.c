#include "../../inc/build.h"

static t_error	ft_build_ceil(t_objlst *objlst)
{
	t_plist		**plan;

	plan = &objlst->plan_ceil;
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_build_ceil_floor"));
	ft_set_vector_clfl(*plan, WE_CEIL);
	(*plan)->id = PL_C;
	return (E_TRUE);
}

static t_error	ft_build_floor(t_objlst *objlst)
{
	t_plist		**plan;

	plan = &objlst->plan_floor;
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_build_ceil_floor"));
	ft_set_vector_clfl(*plan, WE_FLOOR);
	(*plan)->id = PL_F;
	return (E_TRUE);
}

static t_error	ft_build_if_possible(t_oinfo *info, t_objlst *objlst,
		t_map *map)
{
	if (map->map[(int)info->pos_y][(int)info->pos_x] == '1')
		return (ft_build_wall_if_possible(info, objlst, map));
	else if (map->map[(int)info->pos_y][(int)info->pos_x] == 'O')
		return (ft_build_sprite_if_possible(info, objlst));
	return (E_STOP);
}

t_error	ft_get_objects(t_map *map, t_objlst *objlst)
{
	static t_oinfo		info;

	ft_bzero(&info, sizeof(t_oinfo));
	while ((size_t)info.pos_y <= map->m_y[1])
	{
		info.pos_x = 0;
		while ((size_t)info.pos_x <= map->m_x[1])
		{
			if (ft_build_if_possible(&info, objlst, map) == E_ERROR)
				return (ft_kill_all_objects(objlst, map, E_ERROR));
			info.pos_x++;
		}
		info.pos_y++;
	}
	if (ft_build_ceil(objlst) == E_TRUE)
		if (ft_build_floor(objlst) == E_TRUE)
			return (E_TRUE);
	return (ft_kill_all_objects(objlst, map, E_ERROR));
}
