#ifndef ULYSS_H
# define ULYSS_H
# include "../../inc/global_enum.h"
# include "../../inc/global_error.h"
# include "../../inc/global_strct.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# define CHECKANGLES 4

typedef enum e_compass
{
	CPS_N = 0,
	CPS_E,
	CPS_S,
	CPS_W,
	CPS_NE,
	CPS_SE,
	CPS_NW,
	CPS_SW,
	CPS_OUT,
}			t_comps;

t_error				ft_ulysses(t_map *map, char **mrtn, unsigned short y,
						unsigned short x);

t_error				ft_ispretender(char **map, unsigned short ytemp,
						unsigned short xtemp);

char				isinside(char c, char *membs);
unsigned short		room_width(char **map);
unsigned short		compass_x(unsigned short x, t_comps p);
unsigned short		compass_y(unsigned short y, t_comps p);

t_error				ft_clean_ulysses(int *pos, char **map, char **pretds,
						char **membs);

#endif
