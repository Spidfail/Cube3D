#include "../../inc/mlx_setup.h"

static t_error	ft_mlx_create_init(t_mlxset *mlx, t_displ *dspl)
{
	if (dspl == NULL)
		return (E_ERROR);
	mlx->init = mlx_init();
	if (!mlx->init)
		return (ft_error_node(5, ME_INIT, 0, "ft_mlx_create"));
	return (E_TRUE);
}

static t_error	ft_mlx_create_window(t_mlxset *mlx, t_displ *dspl)
{
	mlx->window = mlx_new_window(mlx->init, dspl->res[0],
			dspl->res[1], "CUB -D- -D- -D-");
	if (mlx->window == NULL)
		return (ft_error_node(5, ME_WINDW, 0, "ft_mlx_create"));
	return (E_TRUE);
}

t_error	ft_mlx_create(t_rsrcs *rsrcs, t_mlxen id)
{
	t_error		(*arr[2])(t_mlxset *, t_displ *);

	arr[MLX_CREATE_INIT] = ft_mlx_create_init;
	arr[MLX_CREATE_WINDW] = ft_mlx_create_window;
	return (arr[id](rsrcs->mlx, rsrcs->dspl));
}
