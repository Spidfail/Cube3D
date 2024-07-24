#include "ulyss.h"

unsigned short	room_width(char **map)
{
	unsigned short		i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i])
	{
		if (i + 1 > USHRT_MAX)
			return (-1);
		i++;
	}
	return (i);
}

char	isinside(char c, char *membs)
{
	unsigned short		i;

	i = 0;
	while (membs[i])
	{
		if (membs[i] == c)
			return (c);
		if (i + 1 > USHRT_MAX)
			return (ft_error_print("[ULYSS] Overflow while checking members ",
					"is_inside", E_ERROR));
		i++;
	}
	return (0);
}

unsigned short	compass_x(unsigned short x, t_comps p)
{
	int		compass[8];

	compass[CPS_N] = 0;
	compass[CPS_E] = 1;
	compass[CPS_S] = 0;
	compass[CPS_W] = -1;
	compass[CPS_NE] = 1;
	compass[CPS_SE] = 1;
	compass[CPS_NW] = -1;
	compass[CPS_SW] = -1;
	if (x + compass[p] > USHRT_MAX)
	{
		ft_error_print("[ULYSS] Overflow while setting compass ",
			"ft_compass_x_value", E_ERROR);
		return (USHRT_MAX);
	}
	else if (x + compass[p] < 0)
	{
		ft_error_print("[ULYSS] Unexpected neg value on compass ",
			"ft_compass_x_value", E_ERROR);
		return (USHRT_MAX);
	}
	return (x + compass[p]);
}

unsigned short	compass_y(unsigned short y, t_comps p)
{
	int		compass[8];

	compass[CPS_N] = -1;
	compass[CPS_E] = 0;
	compass[CPS_S] = 1;
	compass[CPS_W] = 0;
	compass[CPS_NE] = -1;
	compass[CPS_SE] = 1;
	compass[CPS_NW] = -1;
	compass[CPS_SW] = 1;
	if (y + compass[p] > USHRT_MAX)
	{
		ft_error_print("[ULYSS] Overflow while setting compass ",
			"ft_compass_y_value", E_ERROR);
		return (USHRT_MAX);
	}
	else if (y + compass[p] < 0)
	{
		ft_error_print("[ULYSS] The map is not closed on the North side ",
			"ft_compass_y_value", E_ERROR);
		return (USHRT_MAX);
	}
	return (y + compass[p]);
}

t_error	ft_ispretender(char **map, unsigned short ytemp, unsigned short xtemp)
{
	if (xtemp >= USHRT_MAX || ytemp >= USHRT_MAX)
		return (E_ERROR);
	if (ft_strchr("02NSEW", map[ytemp][xtemp]))
		return (E_TRUE);
	else
		return (E_STOP);
}
