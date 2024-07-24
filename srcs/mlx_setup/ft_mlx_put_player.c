#include "../../inc/mlx_setup.h"

static void	ft_draw_player(t_rsrcs *rsrcs, int x, int y)
{
	int		s_max;
	int		i;
	int		j;

	i = -1;
	s_max = rsrcs->mlx->minimap->nb_pix_sqrt;
	y -= rsrcs->mlx->minimap->nb_pix_sqrt / 2;
	x -= rsrcs->mlx->minimap->nb_pix_sqrt / 2;
	while (++i <= s_max)
	{
		j = -1;
		while (++j <= s_max)
			ft_pixel_put(rsrcs->threads->img, rsrcs->mlx->minimap->color_plyr,
				x + j, y + i);
	}
}

void	ft_minimap_put_player(t_rsrcs *rsrcs)
{
	double		x;
	double		y;

	x = (rsrcs->player->ply_pos[0] - rsrcs->map->m_x[0])
		* rsrcs->mlx->minimap->nb_pix_sqrt + rsrcs->mlx->minimap->fst_pos_x;
	y = (rsrcs->player->ply_pos[1] - rsrcs->map->m_y[0])
		* rsrcs->mlx->minimap->nb_pix_sqrt + rsrcs->mlx->minimap->fst_pos_y;
	ft_draw_player(rsrcs, x, y);
	return ;
}
