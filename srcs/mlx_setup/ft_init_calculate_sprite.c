#include "../../inc/mlx_setup.h"

static void	ft_calculate_v(t_sprite *sprite, t_player *player)
{
	sprite->v.x = sprite->plan_ray->point_xy[0] - player->ply_pos[0];
	sprite->v.y = sprite->plan_ray->point_xy[1] - player->ply_pos[1];
	sprite->v.z = sprite->plan_ray->point_xy[2] - player->ply_pos[2];
}

static void	ft_calculate_sprite_plan(t_sprite *sprite)
{
	sprite->plan_ray->nvector[0] = sprite->v.x;
	sprite->plan_ray->nvector[1] = sprite->v.y;
	sprite->plan_ray->nvector[2] = 0;
	sprite->plan_ray->d = (-sprite->v.x) * sprite->plan_ray->point_xy[0]
		- sprite->v.y * sprite->plan_ray->point_xy[1];
}

static void	ft_calculate_v_prime(t_sprite *sprite)
{
	sprite->v_prime.x = sprite->v.y;
	sprite->v_prime.y = -sprite->v.x;
	sprite->v_prime.z = sprite->v.z;
	sprite->v_prime.norm = ft_calculate_vect_norme(sprite->v_prime);
}

t_error	ft_init_calculate_sprites(t_rsrcs *rsrcs)
{
	int			i;
	t_sprite	**sp_lst;

	i = -1;
	sp_lst = rsrcs->objlst->things;
	if (sp_lst == NULL)
		return (ft_error_print(" [MLX SETUP] Wrong sprite array value ",
				"ft_init_calculate_sprites", E_ERROR));
	while (++i <= rsrcs->objlst->sp_max)
	{
		sp_lst[i]->plan_ray->point_xy[2] = 0.5;
		sp_lst[i]->plan_ray->numerator = ft_calculate_numerator(rsrcs->player,
				sp_lst[i]->plan_ray);
		ft_calculate_v(sp_lst[i], rsrcs->player);
		sp_lst[i]->sgn_scalar = ft_scalar(rsrcs->player->v_dir, &sp_lst[i]->v);
		ft_calculate_sprite_plan(sp_lst[i]);
		ft_calculate_v_prime(sp_lst[i]);
		if (sp_lst[i]->v_prime.norm == 0)
			return (ft_error_print(" [MLX SETUP] A division per 0 occured ",
					"ft_init_calculate_sprites", E_ERROR));
		ft_normalized_vect(&sp_lst[i]->v2, sp_lst[i]->v_prime);
	}
	return (E_TRUE);
}
