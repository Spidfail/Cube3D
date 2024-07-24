#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"

t_error	ft_put_minimap_to_image(t_image *dst, t_image *src,
		t_minimap param)
{
	unsigned int	color;
	int				src_posx;
	int				src_posy;
	int				x_save;

	src_posx = 0;
	src_posy = 0;
	x_save = param.fst_pos_x;
	while (src_posy < param.nb_sqrt_y * param.nb_pix_sqrt)
	{
		while (src_posx < param.nb_sqrt_x * param.nb_pix_sqrt)
		{
			color = ft_get_pixel_color(src, src_posx, src_posy);
			if (color != 0x0)
				ft_pixel_put(dst, color, param.fst_pos_x, param.fst_pos_y);
			src_posx++;
			param.fst_pos_x++;
		}
		src_posx = 0;
		param.fst_pos_x = x_save;
		src_posy++;
		param.fst_pos_y++;
	}
	return (E_TRUE);
}

t_error	ft_set_print_images(t_displ *dspl, t_mlxset *mlx)
{
	mlx->print1 = ft_calloc(1, sizeof(t_image));
	if (mlx->print1 == NULL)
		return (ft_error_print("[MLX] Failed to allocate print images ",
				"ft_set_print_images", E_ERROR));
	mlx->print1->img_ptr = mlx_new_image(mlx->init, dspl->res[0], dspl->res[1]);
	if (mlx->print1->img_ptr == NULL)
	{
		ft_free((void **)&mlx->print1);
		return (ft_error_print("[MLX] Failed to generate print images ",
				"ft_set_print_images", E_ERROR));
	}
	mlx->print1->area = mlx_get_data_addr(mlx->print1->img_ptr,
			&mlx->print1->bit_pix, &mlx->print1->size_line,
			&mlx->print1->endian);
	mlx->print1->real_sline = mlx->print1->size_line / 4;
	return (E_TRUE);
}

static int	ft_graphical_loop(t_rsrcs *rsrcs)
{
	t_rlist		old_vdir;

	if (rsrcs->mlx->exit > 0)
		ft_kill(rsrcs);
	ft_copy_ray(&old_vdir, rsrcs->player->v_dir);
	ft_mlx_rotation(rsrcs);
	ft_keycode_movement(rsrcs->keycode, rsrcs);
	ft_init_calculate_plan_numerator(rsrcs);
	ft_init_calculate_ceil_floor_numerator(rsrcs);
	if (rsrcs->objlst->issprite == true)
		if (ft_init_calculate_sprites(rsrcs) == E_ERROR)
			return (E_ERROR);
	if (ft_mlx_print_images(rsrcs) == E_ERROR)
		return (ft_error_print("[PRINT] An error occured while building image ",
				"ft_graphical_loop", E_ERROR));
	ft_put_minimap_to_image(rsrcs->threads->img, rsrcs->mlx->img_minimap,
		*rsrcs->mlx->minimap);
	ft_minimap_put_player(rsrcs);
	mlx_put_image_to_window(rsrcs->mlx->init, rsrcs->mlx->window,
		rsrcs->threads->img->img_ptr, 0, 0);
	ft_copy_ray(rsrcs->player->v_dir, &old_vdir);
	return (0);
}

static t_error	ft_mlx_head_loop(t_rsrcs *rsrcs)
{
	if (ft_minimap_events(rsrcs->map, rsrcs->dspl, rsrcs->mlx) == NULL)
		return (E_ERROR);
	if (ft_set_print_images(rsrcs->dspl, rsrcs->mlx) == E_ERROR)
		return (E_ERROR);
	rsrcs->threads->img = rsrcs->mlx->print1;
	mlx_loop_hook(rsrcs->mlx->init, ft_graphical_loop, rsrcs);
	mlx_hook(rsrcs->mlx->window, 17, 1L << 17, ft_kill, rsrcs);
	mlx_hook(rsrcs->mlx->window, 2, 1L << 0, ft_mlx_keypress, rsrcs);
	mlx_hook(rsrcs->mlx->window, 3, 1L << 1, ft_mlx_keyrelease, rsrcs);
	mlx_do_key_autorepeatoff(rsrcs->mlx->init);
	if (mlx_loop(rsrcs->mlx->init) == E_ERROR)
		return (ft_error_print("[SETUP] Mlx loop failed ", "ft_mlx_head_loop",
				E_ERROR));
	return (E_TRUE);
}

t_error	ft_mlx_setup(t_rsrcs *rsrcs)
{
	rsrcs->mlx->exit = -3;
	if (ft_mlx_create(rsrcs, MLX_CREATE_INIT) == E_ERROR)
		return (E_ERROR);
	if (ft_mlx_build_images(rsrcs) == E_ERROR)
		return (ft_setup_clean_images(rsrcs->mlx, E_ERROR));
	if (ft_mlx_create(rsrcs, MLX_CREATE_WINDW) == E_ERROR)
		return (ft_setup_clean_images(rsrcs->mlx, E_ERROR));
	if (ft_mlx_head_loop(rsrcs) == E_ERROR)
		return (ft_setup_clean_images(rsrcs->mlx, E_ERROR));
	ft_setup_clean_images(rsrcs->mlx, E_TRUE);
	return (E_TRUE);
}
