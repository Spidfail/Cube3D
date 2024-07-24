#include "../../inc/mlx_setup.h"

void	ft_copy_ray(t_rlist *dst, t_rlist *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->inters_pt[0] = src->inters_pt[0];
	dst->inters_pt[1] = src->inters_pt[1];
	dst->inters_pt[2] = src->inters_pt[2];
	dst->id = src->id;
	dst->distance = src->distance;
	dst->color = src->color;
	dst->norm = src->norm;
	return ;
}

t_image	*ft_fix_all_images(int id, t_tp_thread *thread)
{
	t_image		*arr[7];

	arr[0] = thread->rsrcs->mlx->img_north;
	arr[1] = thread->rsrcs->mlx->img_south;
	arr[2] = thread->rsrcs->mlx->img_west;
	arr[3] = thread->rsrcs->mlx->img_east;
	arr[4] = thread->rsrcs->mlx->img_sprite;
	arr[5] = thread->rsrcs->mlx->img_floor;
	arr[6] = thread->rsrcs->mlx->img_ceilg;
	if (id < 7)
		return (arr[id]);
	else
		return (NULL);
}

void	ft_check_wall_priority(t_tp_thread *thread)
{
	if (thread->ray->distance > thread->tp_ray.distance)
		ft_copy_ray(thread->ray, &thread->tp_ray);
	return ;
}
