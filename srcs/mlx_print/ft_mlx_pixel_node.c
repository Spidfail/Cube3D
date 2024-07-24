#include "../../inc/mlx_setup.h"

static t_error	ft_is_minimap(int xt, int yt, t_minimap *minimap)
{
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;

	xmin = minimap->fst_pos_x + minimap->nb_pix_sqrt;
	ymin = minimap->fst_pos_y + minimap->nb_pix_sqrt;
	xmax = minimap->size_x_max + (minimap->fst_pos_x
			- minimap->nb_pix_sqrt) + 2;
	ymax = minimap->size_y_max + (minimap->fst_pos_y
			- minimap->nb_pix_sqrt) + 2;
	if (xt > xmin && xt < xmax && yt > ymin && yt < ymax)
		return (E_TRUE);
	return (E_STOP);
}

static unsigned int	ft_shade_apply(int color, double distance, double mod)
{
	unsigned int	new_color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	new_color = 0x00000000;
	r = (0x00FF0000 & color) >> 16;
	g = (0x0000FF00 & color) >> 8;
	b = 0x000000FF & color;
	r -= ((distance * 0.5) * mod) * r;
	g -= ((distance * 0.5) * mod) * g;
	b -= ((distance * 0.5) * mod) * b;
	if (r > 0x000000FF)
		r = 0x00000001;
	if (g > 0x000000FF)
		g = 0x00000001;
	if (b > 0x000000FF)
		b = 0x00000001;
	r = r << 16;
	g = g << 8;
	new_color = (((new_color ^ r) ^ g) ^ b);
	if (new_color >= 0xFF000000 && new_color <= 0xFFFFFFFF)
		new_color = 0x00000001;
	return (new_color);
}

static void	ft_put_scaled_pixel(t_rsrcs *rsrcs, t_rlist *ray, int xt, int yt)
{
	ray->color = ft_shade_apply(ray->color, ray->distance, SHADE);
	ft_pixel_put(rsrcs->threads->img, ray->color, xt, yt);
	ft_pixel_put(rsrcs->threads->img, ray->color, xt, yt + 1);
	ft_pixel_put(rsrcs->threads->img, ray->color, xt + 1, yt);
	ft_pixel_put(rsrcs->threads->img, ray->color, xt + 1, yt + 1);
	return ;
}

t_error	ft_set_pixel_node(t_rsrcs *rsrcs, int position, int xt, int yt)
{
	t_rlist		old_ray;
	int			old_x;

	old_x = xt;
	xt *= 2;
	yt *= 2;
	if (!ft_is_minimap(xt, yt, ((t_rsrcs *)rsrcs)->mlx->minimap))
	{
		ft_copy_ray(&old_ray, rsrcs->player->rays_area[position]);
		ft_application_of_matrix(rsrcs->player,
			rsrcs->player->rays_area[position], 2);
		ft_application_of_matrix(rsrcs->player,
			rsrcs->player->rays_area[position], 0);
		if (ft_set_pixel(rsrcs, rsrcs->player->rays_area[position]) == E_ERROR)
			return (E_ERROR);
		if (old_x < rsrcs->player->cust_res[0] - 1)
			ft_put_scaled_pixel(rsrcs, rsrcs->player->rays_area[position],
				xt, yt);
		ft_copy_ray(rsrcs->player->rays_area[position], &old_ray);
	}
	return (E_TRUE);
}
