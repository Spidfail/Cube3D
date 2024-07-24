#include "../../inc/mlx_setup.h"

t_error	ft_destroy_images(t_mlxset *mlx, t_error e)
{
	if (mlx->img_north && mlx->img_north->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_north->img_ptr);
	if (mlx->img_south && mlx->img_south->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_south->img_ptr);
	if (mlx->img_west && mlx->img_west->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_west->img_ptr);
	if (mlx->img_east && mlx->img_east->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_east->img_ptr);
	if (mlx->img_sprite && mlx->img_sprite->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_sprite->img_ptr);
	if (mlx->img_floor && mlx->img_floor->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_floor->img_ptr);
	if (mlx->img_ceilg && mlx->img_ceilg->img_ptr)
		mlx_destroy_image(mlx->init, mlx->img_ceilg->img_ptr);
	if (mlx->print1 && mlx->print1->img_ptr)
		mlx_destroy_image(mlx->init, mlx->print1->img_ptr);
	return (e);
}

t_error	ft_setup_clean_images(t_mlxset *mlx, t_error e)
{
	ft_destroy_images(mlx, E_ERROR);
	if (mlx->img_north)
		mlx->img_north = ft_free(mlx->img_north);
	if (mlx->img_south)
		mlx->img_south = ft_free(mlx->img_south);
	if (mlx->img_west)
		mlx->img_west = ft_free(mlx->img_west);
	if (mlx->img_east)
		mlx->img_east = ft_free(mlx->img_east);
	if (mlx->img_sprite)
		mlx->img_sprite = ft_free(mlx->img_sprite);
	if (mlx->img_floor)
		mlx->img_floor = ft_free(mlx->img_floor);
	if (mlx->img_ceilg)
		mlx->img_ceilg = ft_free(mlx->img_ceilg);
	if (mlx->print1)
		mlx->print1 = ft_free(mlx->print1);
	return (e);
}
