#include "../../inc/mlx_setup.h"

t_error	ft_print_pixel(t_image *img_src, t_rlist *ray, t_displ *dspl)
{
	long int	coord_x;
	long int	coord_y;

	coord_x = 0;
	coord_y = 0;
	if (ray->id == -1)
		return (E_ERROR);
	if (ray->id == PL_C && dspl->ceilg == NULL && !img_src)
	{
		ray->color = dspl->chex;
		return (E_TRUE);
	}
	if (ray->id == PL_F && dspl->floor == NULL && !img_src)
	{
		ray->color = dspl->fhex;
		return (E_TRUE);
	}
	ft_set_img_wall_floor_coordinate(ray, &coord_x, &coord_y, img_src);
	ray->color = ft_get_pixel_color(img_src, coord_x, coord_y);
	return (E_TRUE);
}

void	ft_reset(t_tp_thread *thread)
{
	thread->ray->distance = DBL_MAX;
	thread->ray->color = 0x0;
	thread->ray->id = -1;
	thread->ray->inters_pt[0] = INT_MAX;
	thread->ray->inters_pt[1] = INT_MAX;
	thread->ray->inters_pt[2] = INT_MAX;
}

t_error	ft_set_pixel(t_rsrcs *rsrcs, t_rlist *ray)
{
	t_tp_thread		thread;
	t_error			e;

	e = 1;
	thread.rsrcs = rsrcs;
	thread.ray = ray;
	ft_reset(&thread);
	ft_copy_ray((&thread.tp_ray), thread.ray);
	e = ft_set_wall_node(&thread, rsrcs->objlst, thread.ray);
	if (e == E_ERROR)
		return (E_ERROR);
	if (rsrcs->objlst->issprite == true)
		if (ft_set_sprite_node(&thread, rsrcs->objlst) == E_ERROR)
			return (E_ERROR);
	if (thread.ray->id != PL_SPR)
		ft_print_pixel(thread.img, thread.ray, rsrcs->dspl);
	return (E_TRUE);
}
