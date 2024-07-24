#include "../../inc/mlx_setup.h"

t_error	ft_mlx_build_images_ceil_floor(t_rsrcs *rsrcs)
{
	if (rsrcs->dspl->ceilg)
	{
		rsrcs->mlx->img_ceilg = ft_calloc(1, sizeof(t_image));
		if (!rsrcs->mlx->img_ceilg)
			return (E_ERROR);
		if (ft_build_choosen_texture(rsrcs->mlx->init, rsrcs->dspl->ceilg,
				rsrcs->mlx->img_ceilg) == E_ERROR)
			return (ft_error_node(5, 2, 0, rsrcs->dspl->floor));
	}
	if (rsrcs->dspl->floor)
	{
		rsrcs->mlx->img_floor = ft_calloc(1, sizeof(t_image));
		if (!rsrcs->mlx->img_floor)
			return (E_ERROR);
		if (ft_build_choosen_texture(rsrcs->mlx->init, rsrcs->dspl->floor,
				rsrcs->mlx->img_floor) == E_ERROR)
			return (ft_error_node(5, 2, 0, rsrcs->dspl->floor));
	}
	return (E_TRUE);
}
