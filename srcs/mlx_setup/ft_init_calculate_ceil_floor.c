#include "../../inc/mlx_setup.h"

void	ft_init_calculate_ceil_floor_numerator(t_rsrcs *rsrcs)
{
	rsrcs->objlst->plan_ceil->numerator = -(rsrcs->player->ply_pos[2]
			* rsrcs->objlst->plan_ceil->nvector[2]
			+ rsrcs->objlst->plan_ceil->d);
	rsrcs->objlst->plan_floor->numerator = -(rsrcs->player->ply_pos[2]
			* rsrcs->objlst->plan_floor->nvector[2]
			+ rsrcs->objlst->plan_floor->d);
	return ;
}
