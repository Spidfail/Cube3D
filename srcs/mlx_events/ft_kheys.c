#include "../../inc/mlx_setup.h"

void	ft_keycode_movement(t_keycode *keycode, t_rsrcs *rsrcs)
{
	if (keycode->up || keycode->left || keycode->right || keycode->down)
		ft_mlx_movement(rsrcs);
	return ;
}

int	ft_exit_switch(t_rsrcs *rsrcs)
{
	rsrcs->mlx->exit = TMEXIT;
	return (0);
}

int	ft_mlx_keyrelease(int keycode, t_rsrcs *rsrcs)
{
	if (keycode == KEY_W)
		rsrcs->keycode->up = false;
	if (keycode == KEY_A)
		rsrcs->keycode->left = false;
	if (keycode == KEY_D)
		rsrcs->keycode->right = false;
	if (keycode == KEY_S)
		rsrcs->keycode->down = false;
	if (keycode == KEY_AR_RGT)
		rsrcs->keycode->rot_right = false;
	if (keycode == KEY_AR_LFT)
		rsrcs->keycode->rot_left = false;
	if (keycode == KEY_AR_UP)
		rsrcs->keycode->nod_up = false;
	if (keycode == KEY_AR_DWN)
		rsrcs->keycode->nod_down = false;
	return (0);
}

int	ft_mlx_keypress(int keycode, t_rsrcs *rsrcs)
{
	if (keycode == KEY_W)
		rsrcs->keycode->up = true;
	if (keycode == KEY_A)
		rsrcs->keycode->left = true;
	if (keycode == KEY_D)
		rsrcs->keycode->right = true;
	if (keycode == KEY_S)
		rsrcs->keycode->down = true;
	if (keycode == KEY_AR_LFT)
		rsrcs->keycode->rot_left = true;
	if (keycode == KEY_AR_RGT)
		rsrcs->keycode->rot_right = true;
	if (keycode == KEY_AR_UP)
		rsrcs->keycode->nod_up = true;
	if (keycode == KEY_AR_DWN)
		rsrcs->keycode->nod_down = true;
	if (keycode == KEY_ECHAP)
		ft_exit_switch(rsrcs);
	return (0);
}
