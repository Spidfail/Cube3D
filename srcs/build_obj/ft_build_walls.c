#include "../../inc/build.h"

t_error	ft_build_north_wall(t_objlst *objlst, t_oinfo *info)
{
	t_plist		**plan;

	plan = &objlst->plan_north[(int)info->pos_y + 1];
	if (*plan)
		return (E_STOP);
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_create_wall"));
	ft_set_vector(*plan, info, WE_NORTH);
	(*plan)->id = PL_NO;
	return (E_TRUE);
}

t_error	ft_build_south_wall(t_objlst *objlst, t_oinfo *info)
{
	t_plist		**plan;

	plan = &objlst->plan_south[(int)info->pos_y];
	if (*plan)
		return (E_STOP);
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_create_wall"));
	ft_set_vector(*plan, info, WE_SOUTH);
	(*plan)->id = PL_SO;
	return (E_TRUE);
}

t_error	ft_build_east_wall(t_objlst *objlst, t_oinfo *info)
{
	t_plist		**plan;

	plan = &objlst->plan_east[(int)info->pos_x];
	if (*plan)
		return (E_STOP);
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_create_wall"));
	ft_set_vector(*plan, info, WE_EAST);
	(*plan)->id = PL_EA;
	return (E_TRUE);
}

t_error	ft_build_west_wall(t_objlst *objlst, t_oinfo *info)
{
	t_plist		**plan;

	plan = &objlst->plan_west[(int)info->pos_x + 1];
	if (*plan)
		return (E_STOP);
	*plan = ft_raylst_new();
	if (*plan == NULL)
		return (ft_error_node(4, 1, 0, "ft_create_wall"));
	ft_set_vector(*plan, info, WE_WEST);
	(*plan)->id = PL_WE;
	return (E_TRUE);
}
