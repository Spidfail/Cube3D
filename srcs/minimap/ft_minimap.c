#include "../../inc/minimap.h"

void	ft_minimap_set_colors(t_mlxset *mlx)
{
	mlx->minimap->color_back = 0x264d00;
	mlx->minimap->color_plyr = 0x00e600;
	mlx->minimap->color_floor = 0xc2c2a3;
	mlx->minimap->color_wall = 0x993300;
}

static void	ft_minimap_calculate_size(t_mlxset *mlx, int ratio_x, int ratio_y)
{
	int		base_sqrt;

	base_sqrt = 125;
	if (ratio_x <= ratio_y)
	{
		mlx->minimap->size_back = base_sqrt * ratio_x;
		mlx->minimap->ratio = ratio_x;
	}
	else if (ratio_x > ratio_y)
	{
		mlx->minimap->size_back = base_sqrt * ratio_y;
		mlx->minimap->ratio = ratio_y;
	}
	return ;
}

static void	ft_minimap_calculate_position(t_mlxset *mlx, int ratio_x,
		int ratio_y)
{
	int		base_pos;

	base_pos = 25;
	mlx->minimap->fst_pos_x = base_pos * ratio_x;
	mlx->minimap->fst_pos_y = base_pos * ratio_y;
	return ;
}

t_minimap	*ft_minimap_events(t_map *map, t_displ *dspl, t_mlxset *mlx)
{
	int		ratio_x;
	int		ratio_y;

	ratio_x = round(ft_proportion(640, dspl->res[0]));
	ratio_y = round(ft_proportion(360, dspl->res[1]));
	mlx->minimap = ft_calloc(1, sizeof(t_minimap));
	mlx->img_minimap = ft_calloc(1, sizeof(t_image));
	if (mlx->minimap == NULL || mlx->img_minimap == NULL)
	{
		ft_error_print("[MINIMAP] Allocation failed ",
			"ft_minimap_events", E_ERROR);
		ft_clean_minimap(mlx, E_ERROR);
		return (NULL);
	}
	ft_minimap_calculate_size(mlx, ratio_x, ratio_y);
	ft_minimap_calculate_position(mlx, ratio_x, ratio_y);
	ft_minimap_set_colors(mlx);
	if (!ft_minimap_generate(mlx, map))
	{
		ft_clean_minimap(mlx, E_ERROR);
		return (NULL);
	}
	return (mlx->minimap);
}
