#include "../../inc/build.h"

static t_error	ft_if_north_west_possible(t_oinfo *info, t_objlst *objlst,
		t_map *map)
{
	int		x;
	int		y;

	x = info->pos_x;
	y = info->pos_y;
	if (y + 1 <= (int)map->m_y[1] && (map->map[y + 1][x] == 'F'
		|| map->map[y + 1][x] == 'N'
			|| map->map[y + 1][x] == 'S' || map->map[y + 1][x] == 'E'
			|| map->map[y + 1][x] == 'W' || map->map[y + 1][x] == '0'
			|| map->map[y + 1][x] == 'O'))
		if (ft_build_north_wall(objlst, info) == E_ERROR)
			return (E_ERROR);
	if (x + 1 <= (int)map->m_x[1] && (map->map[y][x + 1] == 'F'
		|| map->map[y][x + 1] == 'N'
			|| map->map[y][x + 1] == 'S' || map->map[y][x + 1] == 'E'
			|| map->map[y][x + 1] == 'W' || map->map[y][x + 1] == '0'
			|| map->map[y][x + 1] == 'O'))
		if (ft_build_west_wall(objlst, info) == E_ERROR)
			return (E_ERROR);
	return (E_TRUE);
}

static t_error	ft_if_south_east_possible(t_oinfo *info, t_objlst *objlst,
		t_map *map)
{
	int		x;
	int		y;

	x = info->pos_x;
	y = info->pos_y;
	if (y - 1 >= 0 && (map->map[y - 1][x] == 'F'
		|| map->map[y - 1][x] == 'N'
			|| map->map[y - 1][x] == 'S' || map->map[y - 1][x] == 'E'
			|| map->map[y - 1][x] == 'W' || map->map[y - 1][x] == '0'
			|| map->map[y - 1][x] == 'O'))
		if (ft_build_south_wall(objlst, info) == E_ERROR)
			return (E_ERROR);
	if (x - 1 >= 0 && (map->map[y][x - 1] == 'F'
		|| map->map[y][x - 1] == 'N'
			|| map->map[y][x - 1] == 'S' || map->map[y][x - 1] == 'E'
			|| map->map[y][x - 1] == 'W' || map->map[y][x - 1] == '0'
			|| map->map[y][x - 1] == 'O'))
		if (ft_build_east_wall(objlst, info) == E_ERROR)
			return (E_ERROR);
	return (E_TRUE);
}

t_error	ft_build_wall_if_possible(t_oinfo *info, t_objlst *objlst, t_map *map)
{
	if (ft_if_north_west_possible(info, objlst, map) == E_ERROR)
		return (E_ERROR);
	if (ft_if_south_east_possible(info, objlst, map) == E_ERROR)
		return (E_ERROR);
	return (E_TRUE);
}
