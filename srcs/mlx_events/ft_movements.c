#include "../../inc/mlx_setup.h"

static int	ft_mlx_go_up(t_rsrcs *rsrcs)
{
	rsrcs->player->ply_pos[0] += rsrcs->player->v_dir->x * MVT;
	rsrcs->player->ply_pos[1] += rsrcs->player->v_dir->y * MVT;
	return (0);
}

static int	ft_mlx_go_left(t_rsrcs *rsrcs)
{
	rsrcs->player->ply_pos[0] += rsrcs->player->v_dir->y * MVT;
	rsrcs->player->ply_pos[1] -= rsrcs->player->v_dir->x * MVT;
	return (0);
}

static int	ft_mlx_go_right(t_rsrcs *rsrcs)
{
	rsrcs->player->ply_pos[0] -= rsrcs->player->v_dir->y * MVT;
	rsrcs->player->ply_pos[1] += rsrcs->player->v_dir->x * MVT;
	return (0);
}

static int	ft_mlx_go_down(t_rsrcs *rsrcs)
{
	rsrcs->player->ply_pos[0] -= rsrcs->player->v_dir->x * MVT;
	rsrcs->player->ply_pos[1] -= rsrcs->player->v_dir->y * MVT;
	return (0);
}

void	ft_mlx_movement(t_rsrcs *rsrcs)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = rsrcs->player->ply_pos[0];
	tmp_y = rsrcs->player->ply_pos[1];
	if (rsrcs->keycode->up)
		ft_mlx_go_up(rsrcs);
	if (rsrcs->keycode->left)
		ft_mlx_go_left(rsrcs);
	if (rsrcs->keycode->right)
		ft_mlx_go_right(rsrcs);
	if (rsrcs->keycode->down)
		ft_mlx_go_down(rsrcs);
	ft_check_collision(rsrcs, tmp_x, tmp_y);
}
