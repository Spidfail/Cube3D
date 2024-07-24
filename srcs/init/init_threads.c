#include "../../inc/mlx_setup.h"

void	ft_init_threads(t_rsrcs *rsrcs)
{
	rsrcs->threads->res_qrt = rsrcs->player->cust_res[2] / 4;
	rsrcs->threads->pthread1 = 0;
	rsrcs->threads->pthread2 = rsrcs->threads->res_qrt + 1;
	rsrcs->threads->pthread3 = rsrcs->threads->res_qrt * 2 + 1;
	rsrcs->threads->pthread4 = rsrcs->threads->res_qrt * 3 + 1;
	rsrcs->threads->pth_max1 = rsrcs->threads->pthread2;
	rsrcs->threads->pth_max2 = rsrcs->threads->pthread3;
	rsrcs->threads->pth_max3 = rsrcs->threads->pthread4;
	rsrcs->threads->pth_max4 = rsrcs->player->cust_res[2];
}
