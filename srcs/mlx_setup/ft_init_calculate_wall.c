#include "../../inc/mlx_setup.h"

static void	*ft_init_numerator_north(void *rsrcs)
{
	t_plist	**north;
	int		i;

	i = -1;
	north = ((t_rsrcs *)rsrcs)->objlst->plan_north;
	while (++i <= (int)((t_rsrcs *)rsrcs)->map->m_y[1])
	{
		if (north[i])
			north[i]->numerator = -(((t_rsrcs *)rsrcs)->player->ply_pos[1]
					* north[i]->nvector[1] + north[i]->d);
	}
	return (NULL);
}

static void	*ft_init_numerator_south(void *rsrcs)
{
	t_plist	**south;
	int		i;

	i = -1;
	south = ((t_rsrcs *)rsrcs)->objlst->plan_south;
	while (++i <= (int)((t_rsrcs *)rsrcs)->map->m_y[1])
	{
		if (south[i])
			south[i]->numerator = -(((t_rsrcs *)rsrcs)->player->ply_pos[1]
					* south[i]->nvector[1] + south[i]->d);
	}
	return (NULL);
}

static void	*ft_init_numerator_west(void *rsrcs)
{
	t_plist	**west;
	int		i;

	i = -1;
	west = ((t_rsrcs *)rsrcs)->objlst->plan_west;
	while (++i <= (int)((t_rsrcs *)rsrcs)->map->m_x[1])
	{
		if (west[i])
			west[i]->numerator = -(((t_rsrcs *)rsrcs)->player->ply_pos[0]
					* west[i]->nvector[0] + west[i]->d);
	}
	return (NULL);
}

static void	*ft_init_numerator_east(void *rsrcs)
{
	t_plist	**east;
	int		i;

	i = -1;
	east = ((t_rsrcs *)rsrcs)->objlst->plan_east;
	while (++i <= (int)((t_rsrcs *)rsrcs)->map->m_x[1])
	{
		if (east[i])
			east[i]->numerator = -(((t_rsrcs *)rsrcs)->player->ply_pos[0]
					* east[i]->nvector[0] + east[i]->d);
	}
	return (NULL);
}

t_error	ft_init_calculate_plan_numerator(t_rsrcs *rsrcs)
{
	rsrcs->threads->erno1 = pthread_create(&rsrcs->threads->th1, NULL,
			ft_init_numerator_north, rsrcs);
	rsrcs->threads->erno2 = pthread_create(&rsrcs->threads->th2, NULL,
			ft_init_numerator_south, rsrcs);
	rsrcs->threads->erno3 = pthread_create(&rsrcs->threads->th3, NULL,
			ft_init_numerator_east, rsrcs);
	rsrcs->threads->erno4 = pthread_create(&rsrcs->threads->th4, NULL,
			ft_init_numerator_west, rsrcs);
	if (rsrcs->threads->erno1 || rsrcs->threads->erno2
		|| rsrcs->threads->erno3 || rsrcs->threads->erno4)
		return (ft_error_pthread(rsrcs->threads,
				"[THREADS] Failed to launch and finish a Thread",
				NULL, E_ERROR));
	rsrcs->threads->erno1_j = pthread_join(rsrcs->threads->th1, NULL);
	rsrcs->threads->erno2_j = pthread_join(rsrcs->threads->th2, NULL);
	rsrcs->threads->erno3_j = pthread_join(rsrcs->threads->th3, NULL);
	rsrcs->threads->erno4_j = pthread_join(rsrcs->threads->th4, NULL);
	if (rsrcs->threads->erno1_j || rsrcs->threads->erno2_j
		|| rsrcs->threads->erno3_j || rsrcs->threads->erno4_j)
		return (ft_error_pthread(rsrcs->threads,
				"[THREADS] Failed to launch and finish a Thread",
				NULL, E_ERROR));
	return (E_TRUE);
}
