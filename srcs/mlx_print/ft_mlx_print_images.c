#include "../../inc/mlx_setup.h"

static void	*ft_mlx_print_pixel_1(void *rsrcs)
{
	int		i;
	int		x;
	int		y;

	i = ((t_rsrcs *)rsrcs)->threads->pthread1 - 1;
	x = i % ((t_rsrcs *)rsrcs)->player->cust_res[0];
	y = i / ((t_rsrcs *)rsrcs)->player->cust_res[0];
	while (++i < ((t_rsrcs *)rsrcs)->threads->pth_max1)
	{
		if (ft_set_pixel_node(((t_rsrcs *)rsrcs), i, x, y) == E_ERROR)
			return (NULL);
		if (++x == ((t_rsrcs *)rsrcs)->player->cust_res[0])
		{
			y++;
			x = 0;
		}
	}
	return (NULL);
}

static void	*ft_mlx_print_pixel_2(void *rsrcs)
{
	int		i;
	int		x;
	int		y;

	i = ((t_rsrcs *)rsrcs)->threads->pthread2 - 1;
	x = i % ((t_rsrcs *)rsrcs)->player->cust_res[0];
	y = i / ((t_rsrcs *)rsrcs)->player->cust_res[0];
	while (++i < ((t_rsrcs *)rsrcs)->threads->pth_max2)
	{
		if (ft_set_pixel_node(((t_rsrcs *)rsrcs), i, x, y) == E_ERROR)
			return (NULL);
		if (++x == ((t_rsrcs *)rsrcs)->player->cust_res[0])
		{
			y++;
			x = 0;
		}
	}
	return (NULL);
}

static void	*ft_mlx_print_pixel_3(void *rsrcs)
{
	int		i;
	int		x;
	int		y;

	i = ((t_rsrcs *)rsrcs)->threads->pthread3 - 1;
	x = i % ((t_rsrcs *)rsrcs)->player->cust_res[0];
	y = i / ((t_rsrcs *)rsrcs)->player->cust_res[0];
	while (++i < ((t_rsrcs *)rsrcs)->threads->pth_max3)
	{
		if (ft_set_pixel_node(((t_rsrcs *)rsrcs), i, x, y) == E_ERROR)
			return (NULL);
		if (++x == ((t_rsrcs *)rsrcs)->player->cust_res[0])
		{
			y++;
			x = 0;
		}
	}
	return (NULL);
}

static void	*ft_mlx_print_pixel_4(void *rsrcs)
{
	int		i;
	int		x;
	int		y;

	i = ((t_rsrcs *)rsrcs)->threads->pthread4 - 1;
	x = i % ((t_rsrcs *)rsrcs)->player->cust_res[0];
	y = i / ((t_rsrcs *)rsrcs)->player->cust_res[0];
	while (++i < ((t_rsrcs *)rsrcs)->threads->pth_max4)
	{
		if (ft_set_pixel_node(((t_rsrcs *)rsrcs), i, x, y) == E_ERROR)
			return (NULL);
		if (++x == ((t_rsrcs *)rsrcs)->player->cust_res[0])
		{
			y++;
			x = 0;
		}
	}
	return (NULL);
}

t_error	ft_mlx_print_images(t_rsrcs *rsrcs)
{
	rsrcs->threads->erno1 = pthread_create(&rsrcs->threads->th1, NULL,
			ft_mlx_print_pixel_1, rsrcs);
	rsrcs->threads->erno2 = pthread_create(&rsrcs->threads->th2, NULL,
			ft_mlx_print_pixel_2, rsrcs);
	rsrcs->threads->erno3 = pthread_create(&rsrcs->threads->th3, NULL,
			ft_mlx_print_pixel_3, rsrcs);
	rsrcs->threads->erno4 = pthread_create(&rsrcs->threads->th4, NULL,
			ft_mlx_print_pixel_4, rsrcs);
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
