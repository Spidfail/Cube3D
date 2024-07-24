#include "../../inc/mlx_setup.h"
#include "../../inc/leader.h"
#include "../../inc/global_error.h"

t_error	ft_clean_minimap(t_mlxset *mlx, t_error e)
{
	mlx->img_minimap = ft_free(mlx->img_minimap);
	mlx->minimap = ft_free(mlx->minimap);
	return (e);
}

t_error	ft_free_player(t_player *player, t_error e)
{
	int		i;

	i = -1;
	if (!player)
		return (e);
	if (player->rays_area)
	{
		while (player->rays_area[++i])
			player->rays_area[i] = ft_free(player->rays_area[i]);
		player->rays_area = ft_free(player->rays_area);
	}
	player->v_dir = ft_free(player->v_dir);
	return (e);
}

t_error	ft_release_rsrcs(t_rsrcs *rsrcs, t_error e)
{
	if (!rsrcs)
		return (ft_error_print("[ROOT] Failed to allocate ressources struct ",
				"ft_allocate_root", E_ERROR));
	rsrcs->dspl = ft_free(rsrcs->dspl);
	rsrcs->map = ft_free(rsrcs->map);
	rsrcs->objlst = ft_free(rsrcs->objlst);
	rsrcs->mlx = ft_free(rsrcs->mlx);
	rsrcs->player = ft_free(rsrcs->player);
	rsrcs->threads = ft_free(rsrcs->threads);
	rsrcs->keycode = ft_free(rsrcs->keycode);
	return (e);
}

t_error	ft_kill_them_all(t_rsrcs *rsrcs, t_error e)
{
	if (rsrcs->mlx->window)
		mlx_destroy_window(rsrcs->mlx->init, rsrcs->mlx->window);
	ft_kill_all_objects(rsrcs->objlst, rsrcs->map, e);
	ft_setup_clean_images(rsrcs->mlx, e);
	ft_clean_minimap(rsrcs->mlx, E_STOP);
	ft_parsclean(E_STOP, rsrcs->map, rsrcs->dspl);
	ft_free_player(rsrcs->player, e);
	ft_release_rsrcs(rsrcs, e);
	rsrcs = ft_free(rsrcs);
	return (e);
}
