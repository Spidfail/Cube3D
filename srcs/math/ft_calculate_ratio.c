#include "../../inc/leader.h"

void	ft_calculate_ratio(t_player *player)
{
	if (player->cust_res[0] < player->cust_res[1])
	{
		player->hratio = (tan((60 * (M_PI / 180)) / 2) * 2)
			/ (double)player->cust_res[1];
	}
	else
		player->hratio = (tan((60 * (M_PI / 180)) / 2) * 2)
			/ (double)player->cust_res[0];
	player->vratio = player->hratio;
}
