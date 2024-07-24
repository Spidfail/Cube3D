#include "../../inc/mlx_setup.h"

static void	ft_keycode_rotation(t_rsrcs *rsrcs)
{
	double		mpi;

	mpi = 0;
	if (rsrcs->keycode->rot_left)
	{
		mpi = 2 * M_PI;
		rsrcs->player->rotation_angle -= ROT_SPEED;
		if (rsrcs->player->rotation_angle < 0)
			rsrcs->player->rotation_angle += mpi;
	}
	else if (rsrcs->keycode->rot_right)
	{
		mpi = 2 * M_PI;
		rsrcs->player->rotation_angle += ROT_SPEED;
		if (rsrcs->player->rotation_angle > mpi)
			rsrcs->player->rotation_angle -= mpi;
	}
	rsrcs->player->or_cos = cos(rsrcs->player->rotation_angle);
	rsrcs->player->or_sin = sin(rsrcs->player->rotation_angle);
}

static void	ft_keycode_nod(t_rsrcs *rsrcs)
{
	if (rsrcs->keycode->nod_up)
	{
		rsrcs->player->nod_angle -= NOD_SPEED;
		if (rsrcs->player->nod_angle <= -0.70)
			rsrcs->player->nod_angle = -0.70;
	}
	else if (rsrcs->keycode->nod_down)
	{
		rsrcs->player->nod_angle += NOD_SPEED;
		if (rsrcs->player->nod_angle >= 0.70)
			rsrcs->player->nod_angle = 0.70;
	}
	rsrcs->player->nod_cos = cos(rsrcs->player->nod_angle);
	rsrcs->player->nod_sin = sin(rsrcs->player->nod_angle);
}

void	ft_mlx_rotation(t_rsrcs *rsrcs)
{
	ft_keycode_rotation(rsrcs);
	ft_keycode_nod(rsrcs);
	ft_application_of_matrix(rsrcs->player, rsrcs->player->v_dir, 0);
	return ;
}
