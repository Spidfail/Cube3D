#include "ulyss.h"

static t_error	ft_ulysses_compass(unsigned short xt, unsigned short yt,
		unsigned short *xrtn, unsigned short *yrtn)
{
	if (xt == USHRT_MAX || yt == USHRT_MAX)
		return (E_ERROR);
	*xrtn = xt;
	*yrtn = yt;
	return (E_TRUE);
}

static t_error	ft_ulysses_retains_memories(char **dst, char **src,
		unsigned short y, unsigned short x)
{
	src[y][x] = dst[y][x];
	return (E_TRUE);
}

static t_error	ft_ulysses_kills_pretender(char **map, unsigned short y,
		unsigned short x, char *member)
{
	if (map[y][x] == '0')
		map[y][x] = member[0];
	else if (map[y][x] == '2')
		map[y][x] = member[1];
	else
		return (E_STOP);
	return (E_TRUE);
}

static t_error	ft_ulysses_recognizes(char **map, unsigned short y,
		unsigned short x, char *target)
{
	unsigned short	xtest;
	unsigned short	ytest;
	t_comps			i;

	xtest = 0;
	ytest = 0;
	i = -1;
	while (++i < CHECKANGLES)
	{
		if (ft_ulysses_compass(compass_x(x, i), compass_y(y, i), &xtest, &ytest)
			== E_ERROR)
			return (E_ERROR);
		if (ytest > room_width(map) || xtest > ft_strlen(map[y]))
			return (ft_error_print("[ULYSS] Map error, Ulysses go too far ",
					"ft_ulysses_recognizes", E_ERROR));
		if (isinside(map[ytest][xtest], target) == E_ERROR)
			return (E_ERROR);
		if (!map[ytest][xtest] || !isinside(map[ytest][xtest], target))
			return (ft_error_print("[ULYSS] The map is not close by walls ",
					"ft_ulysses_recognizes", E_ERROR));
	}
	return (E_TRUE);
}

t_error	ft_ulysses(t_map *map, char **mrtn, unsigned short y,
		unsigned short x)
{
	unsigned short		dir;
	unsigned short		ty;
	unsigned short		tx;

	dir = -1;
	ty = 0;
	tx = 0;
	if (map == NULL || mrtn == NULL || y < 0 || x < 0)
		return (E_ERROR);
	if (ft_ulysses_recognizes(map->map, y, x, "012FONSEW") == E_ERROR)
		return (E_ERROR);
	while (++dir < 4)
	{
		if (ft_ulysses_compass(compass_x(x, dir), compass_y(y, dir), &tx, &ty)
			== E_ERROR)
			return (E_ERROR);
		ft_ulysses_kills_pretender(map->map, y, x, "FO");
		ft_ulysses_retains_memories(map->map, mrtn, y, x);
		ft_ulysses_retains_memories(map->map, mrtn, ty, tx);
		if (ft_ispretender(map->map, ty, tx))
			if (ft_ulysses(map, mrtn, ty, tx) == E_ERROR)
				return (E_ERROR);
	}
	return (E_TRUE);
}
