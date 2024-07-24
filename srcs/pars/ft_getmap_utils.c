#include "../../inc/pars.h"

size_t	ft_map_width(char **map)
{
	int		i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
		i++;
	return (i);
}

t_error	ft_getmap_size(t_mpars mapenum, t_map *map, size_t x, size_t y)
{
	if (mapenum == M_1)
	{
		if (x > map->m_x[1])
			map->m_x[1] = x;
		if (map->lock_x == false)
		{
			map->lock_x = true;
			map->m_x[0] = x;
		}
		else if (map->m_x[0] > x && map->lock_x == true)
			map->m_x[0] = x;
		if (y > map->m_y[1])
			map->m_y[1] = y;
		if (map->lock_y == false)
		{
			map->lock_y = true;
			map->m_y[0] = y;
		}
		else if (map->m_y[0] > y && map->lock_y == true)
			map->m_y[0] = y;
	}
	return (E_TRUE);
}

int	ft_get_enum_map(char c)
{
	int		i;
	char	arrp[7];

	i = 0;
	arrp[0] = '0';
	arrp[1] = '1';
	arrp[2] = '2';
	arrp[3] = 'N';
	arrp[4] = 'W';
	arrp[5] = 'S';
	arrp[6] = 'E';
	while (i < 7)
	{
		if (arrp[i] == c)
			return (i);
		i++;
	}
	return (i);
}
