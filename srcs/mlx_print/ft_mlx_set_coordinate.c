#include "../../inc/mlx_setup.h"

static void	ft_set_img_wall_west_south_coordinate(t_rlist *ray,
		long int *coord_x, long int *coord_y, t_image *img)
{
	if (ray->id == PL_WE)
	{
		*coord_x = (1 - (ray->inters_pt[1] - (long int)ray->inters_pt[1]))
			* (img->size[0] - 1);
		*coord_y = img->size[1] - 1 - (ray->inters_pt[2]
				- (long int)ray->inters_pt[2]) * (img->size[1] - 1);
	}
	else if (ray->id == PL_SO)
	{
		*coord_x = (1 - (ray->inters_pt[0] - (long int)ray->inters_pt[0]))
			* (img->size[0] - 1);
		*coord_y = img->size[1] - 1 - (ray->inters_pt[2]
				- (long int)ray->inters_pt[2]) * (img->size[1] - 1);
	}
}

void	ft_set_img_wall_floor_coordinate(t_rlist *ray,
		long int *coord_x, long int *coord_y, t_image *img)
{
	if (ray->id == PL_NO)
	{
		*coord_x = (ray->inters_pt[0] - (long int)ray->inters_pt[0])
			* (img->size[0] - 1);
		*coord_y = img->size[1] - 1 - (ray->inters_pt[2]
				- (long int)ray->inters_pt[2]) * (img->size[1] - 1);
	}
	else if (ray->id == PL_WE || ray->id == PL_SO)
		ft_set_img_wall_west_south_coordinate(ray, coord_x, coord_y, img);
	else if (ray->id == PL_EA)
	{
		*coord_x = (ray->inters_pt[1] - (long int)ray->inters_pt[1])
			* (img->size[0] - 1);
		*coord_y = img->size[1] - 1 - (ray->inters_pt[2]
				- (long int)ray->inters_pt[2]) * (img->size[1] - 1);
	}
	else if (ray->id == PL_C || ray->id == PL_F)
	{
		*coord_x = (ray->inters_pt[0] - (long int)ray->inters_pt[0])
			* (img->size[0] - 1);
		*coord_y = img->size[1] - 1 - (ray->inters_pt[1]
				- (long int)ray->inters_pt[1]) * (img->size[1] - 1);
	}
}

void	ft_set_img_sprite_coordinate(t_rlist *ray, t_sprite *sprite,
		t_image *img)
{
	long int	x;
	long int	y;

	x = (sprite->r - (long int)sprite->r) * img->size[0];
	y = img->size[1] - (ray->inters_pt[2] - (long int)ray->inters_pt[2])
		* img->size[1];
	ray->color = ft_get_pixel_color(img, x, y);
	return ;
}
