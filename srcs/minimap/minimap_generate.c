#include "../../inc/minimap.h"

static t_error	ft_minimap_generate_img(t_image *image, t_minimap *param,
t_mlxset *mlx)
{
	image->img_ptr = mlx_new_image(mlx->init, param->size_back,
			param->size_back);
	if (image->img_ptr == NULL)
		return (ft_error_print("[MLX] Failed to generate minimap image ",
				"ft_minimap_generate", E_ERROR));
	image->area = mlx_get_data_addr(image->img_ptr, &image->bit_pix,
			&image->size_line, &image->endian);
	image->real_sline = image->size_line / 4;
	return (E_TRUE);
}

t_error	ft_print_square(t_image *image, t_minimap *param,
		t_sqrt sqrt, unsigned int c)
{
	int		interv;
	int		xsave;
	int		ysave;

	xsave = sqrt.pos_x;
	ysave = sqrt.pos_y;
	interv = 1 * param->ratio;
	sqrt.pos_y += interv;
	while ((sqrt.pos_y - ysave) < param->nb_pix_sqrt)
	{
		sqrt.pos_x += interv;
		while ((sqrt.pos_x - xsave) < param->nb_pix_sqrt)
		{
			ft_pixel_put(image, c, sqrt.pos_x, sqrt.pos_y);
			sqrt.pos_x++;
		}
		sqrt.pos_x = xsave;
		sqrt.pos_y++;
	}
	return (E_TRUE);
}

static t_error	ft_minimap_draw_front(t_image *image, t_minimap *param,
		t_map *map)
{
	static t_sqrt	sqrt = {0};
	int				i;
	int				k;

	k = map->m_y[0] - 1;
	i = map->m_x[0] - 1;
	while (++k < (int)map->m_y[1] + 1)
	{
		while (++i < (int)map->m_x[1] + 1)
		{
			sqrt.pos_x = (i - map->m_x[0]) * param->nb_pix_sqrt;
			sqrt.pos_y = (k - map->m_y[0]) * param->nb_pix_sqrt;
			if (map->map[k][i] == '1')
				ft_print_square(image, param, sqrt, param->color_wall);
			else if (map->map[k][i] && !ft_isspace(map->map[k][i]))
				ft_print_square(image, param, sqrt, param->color_floor);
		}
		i = map->m_x[0] - 1;
	}
	return (E_TRUE);
}

static void	ft_minimap_set_drawsize(t_minimap *param, t_map *map)
{
	param->nb_sqrt_x = map->m_x[1] - map->m_x[0] + 1;
	param->nb_sqrt_y = map->m_y[1] - map->m_y[0] + 1;
	if (param->nb_sqrt_x >= param->nb_sqrt_y)
		param->nb_pix_sqrt = param->size_back / param->nb_sqrt_x;
	else if (param->nb_sqrt_x < param->nb_sqrt_y)
		param->nb_pix_sqrt = param->size_back / param->nb_sqrt_y;
	param->size_x_max = param->nb_sqrt_x * param->nb_pix_sqrt;
	param->size_y_max = param->nb_sqrt_y * param->nb_pix_sqrt;
	return ;
}

t_image	*ft_minimap_generate(t_mlxset *mlx, t_map *map)
{
	t_image		*image;
	t_minimap	*param;

	image = mlx->img_minimap;
	param = mlx->minimap;
	if (ft_minimap_generate_img(image, param, mlx) == E_ERROR)
		return (NULL);
	ft_minimap_set_drawsize(param, map);
	ft_minimap_draw_front(image, param, map);
	return (image->img_ptr);
}
