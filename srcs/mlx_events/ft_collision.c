#include "../../inc/mlx_setup.h"

static void	ft_set_plan_param(t_rlist *plan_ray, t_rlist *ray)
{
	if ((ray->id == PL_NO || ray->id == PL_SO) && ray->x > 0)
		*plan_ray = (t_rlist){0.3, 0, 0.5, 0, 0, 0, {0, 0, 0}, 0};
	else if ((ray->id == PL_NO || ray->id == PL_SO)
		&& (ray->x < 0 || ray->x == 0))
		*plan_ray = (t_rlist){-0.3, 0, 0.5, 0, 0, 0, {0, 0, 0}, 0};
	else if ((ray->id == PL_WE || ray->id == PL_EA) && ray->y > 0)
		*plan_ray = (t_rlist){0, 0.3, 0.5, 0, 0, 0, {0, 0, 0}, 0};
	else if ((ray->id == PL_WE || ray->id == PL_EA)
		&& (ray->y < 0 || ray->y == 0))
		*plan_ray = (t_rlist){0, -0.3, 0.5, 0, 0, 0, {0, 0, 0}, 0};
	return ;
}

static t_error	ft_calculate_new_position(t_rsrcs *rsrcs, t_rlist *ray)
{
	t_rlist		ab;
	t_rlist		plan_ray;
	int			pos[3];

	ft_set_plan_param(&plan_ray, ray);
	ab.x = (rsrcs->player->ply_pos[0] - ray->inters_pt[0]) + plan_ray.x;
	ab.y = (rsrcs->player->ply_pos[1] - ray->inters_pt[1]) + plan_ray.y;
	rsrcs->player->ply_pos[0] += ab.x;
	rsrcs->player->ply_pos[1] += ab.y;
	pos[0] = rsrcs->player->ply_pos[0];
	pos[1] = rsrcs->player->ply_pos[1];
	pos[2] = rsrcs->player->ply_pos[2];
	if (rsrcs->map->map[pos[1]][pos[0]] == 'F'
			|| rsrcs->map->map[pos[1]][pos[0]] == 'O'
			|| rsrcs->map->map[pos[1]][pos[0]] == 'N'
			|| rsrcs->map->map[pos[1]][pos[0]] == 'S'
			|| rsrcs->map->map[pos[1]][pos[0]] == 'E'
			|| rsrcs->map->map[pos[1]][pos[0]] == 'W')
	{
		return (E_TRUE);
	}
	return (E_ERROR);
}

static t_error	ft_set_collision_movement(t_rsrcs *rsrcs, t_rlist *ray)
{
	t_tp_thread		*thread;

	thread = ft_calloc(1, sizeof(t_tp_thread));
	if (!thread)
		return (ft_error_print("[MVT] Failed to allocate temp thread structure",
				"ft_set_collision_movement", E_ERROR));
	thread->rsrcs = rsrcs;
	thread->ray = ray;
	ft_reset(thread);
	ft_copy_ray((&thread->tp_ray), thread->ray);
	if (ft_set_wall_node(thread, rsrcs->objlst, thread->ray) == E_ERROR)
		return (E_ERROR);
	free(thread);
	return (E_TRUE);
}

static t_error	ft_is_collision(t_rsrcs *rsrcs, double new_x, double new_y)
{
	char	**map;

	map = rsrcs->map->map;
	if (map[(int)new_y][(int)new_x] == '1'
			&& map[(int)new_y][(int)new_x] == '1')
		return (E_TRUE);
	else if (map[(int)new_y][(int)new_x] == '\0'
			&& map[(int)new_y][(int)new_x] == '\0')
		return (E_TRUE);
	else if (GODMOD == 0)
		if (map[(int)new_y][(int)new_x] == 'O'
				&& map[(int)new_y][(int)new_x] == 'O')
			return (E_ERROR);
	return (E_STOP);
}

t_error	ft_check_collision(t_rsrcs *rsrcs, double tmp_x, double tmp_y)
{
	double		new_x;
	double		new_y;
	t_rlist		v_tmp;

	new_x = rsrcs->player->ply_pos[0];
	new_y = rsrcs->player->ply_pos[1];
	if (ft_is_collision(rsrcs, new_x, new_y) == E_ERROR)
		rsrcs->mlx->exit = TMEXIT;
	else if (new_x > 0 && new_y > 0
		&& ft_is_collision(rsrcs, new_x, new_y) == E_TRUE)
	{
		rsrcs->player->ply_pos[0] = tmp_x;
		rsrcs->player->ply_pos[1] = tmp_y;
		v_tmp.x = new_x - tmp_x;
		v_tmp.y = new_y - tmp_y;
		v_tmp.z = 0.5;
		if (ft_set_collision_movement(rsrcs, &v_tmp) == E_ERROR)
			return (E_ERROR);
		if (ft_calculate_new_position(rsrcs, &v_tmp) == E_TRUE)
			return (E_TRUE);
		rsrcs->player->ply_pos[0] = tmp_x;
		rsrcs->player->ply_pos[1] = tmp_y;
	}
	return (E_TRUE);
}
