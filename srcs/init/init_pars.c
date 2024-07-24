#include "../../inc/pars.h"
#include "../../inc/build.h"
#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

static t_error	ft_map_checker(t_map *map)
{
	if (map->m_x[1] > 100 || map->m_y[1] > 100)
		return (ft_error_print(" [PARS] Size max of the map [100 x 100]",
				"ft_map_checker", E_ERROR));
	if (map->m_y[1] < 2 || map->m_x[1] < 2)
		return (ft_error_print(" [PARS] Size min of the map [3 x 3]",
				"ft_map_checker", E_ERROR));
	return (E_TRUE);
}

static t_error	ft_reset_map_begining(t_map *map)
{
	size_t		x;
	size_t		y;
	size_t		max_y;
	size_t		max_x;

	y = -1;
	x = -1;
	max_y = map->m_y[1];
	max_x = map->m_x[1];
	map->m_y[1] = 0;
	map->m_x[1] = 0;
	while (++y <= max_y)
	{
		while (++x <= max_x)
			if (map->map[y][x] == '1')
				ft_getmap_size(M_1, map, x, y);
		x = -1;
	}
	return (E_TRUE);
}

t_error	ft_init_pars(t_rsrcs *rsrcs, char *cub)
{
	rsrcs->map->lock_x = false;
	rsrcs->map->lock_y = false;
	if (ft_pars(rsrcs->map, rsrcs->dspl, cub) == E_ERROR)
		return (E_ERROR);
	rsrcs->map->lock_x = false;
	rsrcs->map->lock_y = false;
	ft_reset_map_begining(rsrcs->map);
	return (ft_map_checker(rsrcs->map));
}
