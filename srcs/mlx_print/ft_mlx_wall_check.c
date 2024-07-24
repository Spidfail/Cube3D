#include "../../inc/mlx_setup.h"

int	ft_define_ray_wall_north(t_tp_thread *thread, t_rlist *ray,
		int pos, t_plist **plan)
{
	double		denom;
	t_error		e;

	denom = 0;
	while (pos >= 0)
	{
		if (plan[pos])
		{
			denom = ray->y * plan[pos]->nvector[1];
			e = ft_calculate_intersection(ray, plan[pos], thread, denom);
			if (e == E_ERROR || e == E_TRUE)
				return (e);
		}
		pos--;
	}
	return (E_STOP);
}

int	ft_define_ray_wall_south(t_tp_thread *thread, t_rlist *ray,
		int pos, t_plist **plan)
{
	double		denom;
	t_error		e;

	denom = 0;
	while (pos > 0 && pos <= (int)thread->rsrcs->map->m_y[1])
	{
		if (plan[pos])
		{
			denom = ray->y * plan[pos]->nvector[1];
			e = ft_calculate_intersection(ray, plan[pos], thread, denom);
			if (e == E_ERROR || e == E_TRUE)
				return (e);
		}
		pos++;
	}
	return (E_STOP);
}

int	ft_define_ray_wall_east(t_tp_thread *thread, t_rlist *ray,
		int pos, t_plist **plan)
{
	double		denom;
	t_error		e;

	denom = 0;
	while (pos > 0 && pos <= (int)thread->rsrcs->map->m_x[1])
	{
		if (plan[pos])
		{
			denom = (ray->x * plan[pos]->nvector[0]);
			e = ft_calculate_intersection(ray, plan[pos], thread, denom);
			if (e == E_ERROR || e == E_TRUE)
				return (e);
		}
		pos++;
	}
	return (E_STOP);
}

int	ft_define_ray_wall_west(t_tp_thread *thread, t_rlist *ray,
		int pos, t_plist **plan)
{
	double		denom;
	t_error		e;

	denom = 0;
	while (pos >= 0)
	{
		if (plan[pos])
		{
			denom = (ray->x * plan[pos]->nvector[0]);
			e = ft_calculate_intersection(ray, plan[pos], thread, denom);
			if (e == E_ERROR || e == E_TRUE)
				return (e);
		}
		pos--;
	}
	return (E_STOP);
}

int	ft_define_ray_ceil_floor(t_tp_thread *thread, t_rlist *ray, t_plist *plan)
{
	double		denom;

	denom = ray->z * plan->nvector[2];
	if (denom != 0)
	{
		ray->distance = plan->numerator / denom;
		if (ray->distance >= 0)
		{
			ray->inters_pt[0] = thread->rsrcs->player->ply_pos[0]
				+ ray->x * ray->distance;
			ray->inters_pt[1] = thread->rsrcs->player->ply_pos[1]
				+ ray->y * ray->distance;
			ray->inters_pt[2] = thread->rsrcs->player->ply_pos[2]
				+ ray->z * ray->distance;
			ray->id = plan->id;
			return (E_TRUE);
		}
	}
	return (E_STOP);
}
