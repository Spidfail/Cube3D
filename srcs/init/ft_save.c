#include "../../inc/pars.h"
#include "../../inc/build.h"
#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

static int	ft_unique_loop(t_rsrcs *rsrcs)
{
	ft_mlx_rotation(rsrcs);
	ft_keycode_movement(rsrcs->keycode, rsrcs);
	ft_init_calculate_plan_numerator(rsrcs);
	ft_init_calculate_ceil_floor_numerator(rsrcs);
	if (rsrcs->objlst->issprite == true)
		ft_init_calculate_sprites(rsrcs);
	if (ft_mlx_print_images(rsrcs) == E_ERROR)
		return (ft_error_print("[PRINT] An error occured while building image ",
				"ft_graphical_loop", E_ERROR));
	ft_put_minimap_to_image(rsrcs->threads->img, rsrcs->mlx->img_minimap,
		*rsrcs->mlx->minimap);
	ft_minimap_put_player(rsrcs);
	ft_make_bmp(rsrcs->mlx->bmp, rsrcs->threads->img, rsrcs);
	ft_kill_them_all(rsrcs, E_TRUE);
	exit(0);
	return (0);
}

static t_image	*ft_bmp_setup(t_rsrcs *rsrcs, char *bmp)
{
	if (ft_mlx_create(rsrcs, MLX_CREATE_INIT) == E_ERROR)
		return (NULL);
	if (ft_mlx_build_images(rsrcs) == E_ERROR)
		return (NULL);
	ft_minimap_events(rsrcs->map, rsrcs->dspl, rsrcs->mlx);
	if (ft_set_print_images(rsrcs->dspl, rsrcs->mlx) == E_ERROR)
		return (NULL);
	rsrcs->threads->img = rsrcs->mlx->print1;
	rsrcs->mlx->bmp = bmp;
	mlx_loop_hook(rsrcs->mlx->init, ft_unique_loop, rsrcs);
	mlx_loop(rsrcs->mlx->init);
	return (rsrcs->threads->img);
}

static t_rsrcs	*ft_transfert_parts(t_map **map, t_displ **dspl,
t_objlst **objlst, t_rsrcs **rsrcs)
{
	(*rsrcs)->dspl = *dspl;
	(*rsrcs)->map = *map;
	(*rsrcs)->objlst = *objlst;
	return (*rsrcs);
}

t_error	ft_save_cub3d(char *cub, char *bmp)
{
	t_rsrcs		*rsrcs;

	rsrcs = ft_calloc(1, sizeof(t_rsrcs));
	if (ft_allocate_root(rsrcs) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	if (ft_init_pars(rsrcs, cub) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	if (ft_init_objects(rsrcs) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	if (ft_init_player(rsrcs->player, rsrcs->dspl, rsrcs->map) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	ft_init_threads(rsrcs);
	ft_init_calculate_plan_numerator(rsrcs);
	ft_transfert_parts(&rsrcs->map, &rsrcs->dspl, &rsrcs->objlst, &rsrcs);
	if (ft_bmp_setup(rsrcs, bmp) == NULL)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	return (ft_kill_them_all(rsrcs, E_TRUE));
}
