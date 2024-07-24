#include "../../inc/pars.h"
#include "../../inc/build.h"
#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

static void	ft_ray_builder(t_player *player, t_rlist **vect, double i, double j)
{
	(*vect)->x = (i - player->cust_res[0] * 0.5) * player->hratio;
	(*vect)->y = -1;
	(*vect)->z = (player->cust_res[1] * 0.5 - j) * player->vratio;
	(*vect)->norm = ft_calculate_vect_norme(**vect);
	return ;
}

static t_error	ft_rays_generate(t_player *player)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (j < player->cust_res[1])
	{
		i = 0;
		while (i < player->cust_res[0])
		{
			player->rays_area[k] = ft_calloc(1, sizeof(t_rlist));
			if (!player->rays_area[k])
				return (ft_error_print("[RAYCAST] Allocation failed ",
						"ft_rays_generate", E_ERROR));
			ft_ray_builder(player, &player->rays_area[k], i, j);
			i++;
			k++;
		}
		j++;
	}
	return (E_TRUE);
}

static t_error	ft_build_rays(t_player *player)
{
	player->rays_area = ft_calloc(player->cust_res[2] + 2, sizeof(t_rlist *));
	if (!player->rays_area)
		return (ft_error_print("[RAYCAST] Failed to allocate rays array ",
				"ft_raybuilding", E_ERROR));
	player->rays_area[player->cust_res[2] + 1] = NULL;
	ft_rays_generate(player);
	player->v_dir = ft_calloc(1, sizeof(t_rlist));
	if (!player->v_dir)
		return (ft_error_print("[RAYCAST] Failed to allocate v_direction ",
				"ft_build_rays", E_ERROR));
	player->v_dir->x = 0;
	player->v_dir->y = -1;
	player->v_dir->z = 0;
	player->v_dir->norm = ft_calculate_vect_norme(*player->v_dir);
	return (E_TRUE);
}

static t_error	ft_init_rotation_angle(t_player *player, char or)
{
	player->nod_angle = 0;
	if (or != 'N' && or != 'S' && or != 'W' && or != 'E')
		return (ft_error_print("[INIT] Player orientation is incorrect ",
				"ft_init_rotation_angle", E_ERROR));
	if (or == 'N')
		player->rotation_angle = 0;
	else if (or == 'S')
		player->rotation_angle = M_PI;
	else if (or == 'W')
		player->rotation_angle = (3 * M_PI) / 2;
	else if (or == 'E')
		player->rotation_angle = M_PI / 2;
	return (E_TRUE);
}

t_error	ft_init_player(t_player *player, t_displ *dspl, t_map *map)
{
	player->ply_pos[0] = ((double)map->plyxy[0]) + 0.5;
	player->ply_pos[1] = ((double)map->plyxy[1]) + 0.5;
	player->ply_pos[2] = 0.5;
	player->cust_res[0] = dspl->res[0] / 2;
	player->cust_res[1] = dspl->res[1] / 2;
	player->cust_res[2] = player->cust_res[0] * player->cust_res[1];
	if (player->cust_res[0] % 2 != 0)
		player->is_even = false;
	else
		player->is_even = true;
	if (ft_init_rotation_angle(player, map->plyor) == E_ERROR)
		return (ft_free_player(player, E_ERROR));
	ft_calculate_ratio(player);
	if (ft_build_rays(player) == E_ERROR)
		return (ft_free_player(player, E_ERROR));
	return (E_TRUE);
}
