#include "../../inc/mlx_setup.h"

t_error	ft_decide_if_floor_or_ceil(t_tp_thread *thread)
{
	if (thread->tp_ray.inters_pt[2] >= 1)
		return (ft_define_ray_ceil_floor(thread, &thread->tp_ray,
				thread->rsrcs->objlst->plan_ceil));
	else if (thread->tp_ray.inters_pt[2] < 0)
		return (ft_define_ray_ceil_floor(thread, &thread->tp_ray,
				thread->rsrcs->objlst->plan_floor));
	return (E_ERROR);
}

static t_error	ft_decide_which_side(t_tp_thread *thread, t_plist **planlist,
		int posx, int posy)
{
	if (planlist == thread->rsrcs->objlst->plan_east)
		return (ft_define_ray_wall_east(thread, &thread->tp_ray,
				posx, planlist));
	else if (planlist == thread->rsrcs->objlst->plan_south)
		return (ft_define_ray_wall_south(thread, &thread->tp_ray,
				posy, planlist));
	else if (planlist == thread->rsrcs->objlst->plan_north)
		return (ft_define_ray_wall_north(thread, &thread->tp_ray,
				posy + 1, planlist));
	else if (planlist == thread->rsrcs->objlst->plan_west)
		return (ft_define_ray_wall_west(thread, &thread->tp_ray,
				posx + 1, planlist));
	return (E_ERROR);
}

static t_error	ft_intersect_wall_node(t_tp_thread *thread,
		t_plist **w1, t_plist **w2)
{
	if (w1)
	{
		if (ft_decide_which_side(thread, w1, thread->rsrcs->player->ply_pos[0],
				thread->rsrcs->player->ply_pos[1]) == E_ERROR)
			ft_decide_if_floor_or_ceil(thread);
		ft_check_wall_priority(thread);
	}
	if (w2)
	{
		if (ft_decide_which_side(thread, w2, thread->rsrcs->player->ply_pos[0],
				thread->rsrcs->player->ply_pos[1]) == E_ERROR)
			ft_decide_if_floor_or_ceil(thread);
		ft_check_wall_priority(thread);
	}
	thread->img = ft_fix_all_images(thread->ray->id, thread);
	return (E_TRUE);
}

t_error	ft_set_wall_node(t_tp_thread *thread, t_objlst *objlst, t_rlist *ray)
{
	if (ray->x > 0 && ray->y > 0)
		return (ft_intersect_wall_node(thread, objlst->plan_south,
				objlst->plan_east));
	else if (ray->x > 0 && ray->y < 0)
		return (ft_intersect_wall_node(thread, objlst->plan_north,
				objlst->plan_east));
	else if (ray->x < 0 && ray->y > 0)
		return (ft_intersect_wall_node(thread, objlst->plan_south,
				objlst->plan_west));
	else if (ray->x < 0 && ray->y < 0)
		return (ft_intersect_wall_node(thread, objlst->plan_north,
				objlst->plan_west));
	else if (ray->x == 0 && ray->y < 0)
		return (ft_intersect_wall_node(thread, objlst->plan_north, NULL));
	else if (ray->x == 0 && ray->y > 0)
		return (ft_intersect_wall_node(thread, objlst->plan_south, NULL));
	else if (ray->x < 0 && ray->y == 0)
		return (ft_intersect_wall_node(thread, NULL, objlst->plan_west));
	else if (ray->x > 0 && ray->y == 0)
		return (ft_intersect_wall_node(thread, NULL, objlst->plan_east));
	return (E_ERROR);
}
