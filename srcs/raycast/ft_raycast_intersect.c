#include "../../inc/leader.h"

static t_error	ft_sprite_references(t_rlist *ray, t_plist *plan,
		t_tp_thread *thread, double denom)
{
	if (denom == 0)
		return (E_STOP);
	ray->distance = plan->numerator / denom;
	if (ray->distance >= 0 && ray->distance < thread->ray->distance)
	{
		ray->inters_pt[2] = thread->rsrcs->player->ply_pos[2]
			+ ray->z * ray->distance;
		if (ray->inters_pt[2] >= 1 || ray->inters_pt[2] < 0)
			return (E_STOP);
		ray->inters_pt[0] = thread->rsrcs->player->ply_pos[0]
			+ ray->x * ray->distance;
		ray->inters_pt[1] = thread->rsrcs->player->ply_pos[1]
			+ ray->y * ray->distance;
		return (E_TRUE);
	}
	return (E_STOP);
}

t_error	ft_calculate_sprite_intersection(t_rlist *ray, t_sprite *sprite,
		t_tp_thread *thread, double denom)
{
	t_error		e;
	t_sprite	tmp;

	e = ft_sprite_references(ray, sprite->plan_ray, thread, denom);
	if (e == E_STOP)
		return (e);
	ft_calculate_u(&tmp, sprite, ray);
	tmp.r = ft_scalar(&tmp.u, &sprite->v2) + 0.5;
	ft_set_img_sprite_coordinate(ray, &tmp, thread->rsrcs->mlx->img_sprite);
	if (ray->color <= 0xFFFFFFFF && ray->color >= 0xFF000000)
		return (E_STOP);
	else if (0 <= tmp.r && tmp.r < 1)
	{
		ray->id = PL_SPR;
		ft_copy_ray(thread->ray, &thread->tp_ray);
		return (E_TRUE);
	}
	return (E_STOP);
}

t_error	ft_calculate_intersection(t_rlist *ray, t_plist *plan,
		t_tp_thread *thread, double denom)
{
	if (denom == 0)
		return (E_STOP);
	ray->distance = plan->numerator / denom;
	if (ray->distance >= 0)
	{
		ray->inters_pt[2] = thread->rsrcs->player->ply_pos[2]
			+ ray->z * ray->distance;
		if (ray->inters_pt[2] >= 1 || ray->inters_pt[2] < 0)
			return (E_ERROR);
		ray->inters_pt[0] = thread->rsrcs->player->ply_pos[0]
			+ ray->x * ray->distance;
		ray->inters_pt[1] = thread->rsrcs->player->ply_pos[1]
			+ ray->y * ray->distance;
		if (ft_is_impact(ray, thread->rsrcs->map, '1', plan))
		{
			ray->id = plan->id;
			return (E_TRUE);
		}
	}
	return (E_STOP);
}
