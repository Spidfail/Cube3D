#include "../../inc/leader.h"
#include "../../inc/pars.h"

static char	*ft_linechecker_id(t_pars p)
{
	char	*id[8];

	id[1] = "NO ";
	id[2] = "SO ";
	id[3] = "WE ";
	id[4] = "EA ";
	id[5] = "S ";
	id[6] = "F ";
	id[7] = "C ";
	return (id[p]);
}

static t_error	ft_linechecker_resolution(t_pars p, char *s, bool *bl)
{
	int		i;

	i = 0;
	if (p != D_RES)
		return (E_ERROR);
	while (s[i] == ' ' || s[i] == 'R' || ft_isdigit(s[i]))
	{
		if (s[i] == 'R')
		{
			if (*bl)
				return (E_ERROR);
			else
				*bl = true;
		}
		i++;
	}
	if (s[i] != '\0')
		return (E_ERROR);
	return (E_TRUE);
}

static t_error	ft_linechecker_wall_sprite(t_pars p, char *s, bool *bl)
{
	if (s == NULL || !(*s) || *bl == true)
		return (E_ERROR);
	if (!ft_isstr(s, IS_PRINT))
		return (E_ERROR);
	else if (1 != ft_strnstr_nb(s, " ./", ft_strlen(s)))
		return (E_ERROR);
	else if (1 != ft_strnstr_nb(s, ".xpm", ft_strlen(s)))
		return (E_ERROR);
	else if (1 != ft_strnstr_nb(s, ft_linechecker_id(p), ft_strlen(s)))
		return (E_ERROR);
	else
		*bl = true;
	return (E_TRUE);
}

static t_error	ft_linechecker_ceil_floor(t_pars p, char *s, bool *bl)
{
	if (s == NULL || !(*s) || *bl == true)
		return (E_ERROR);
	else if (!ft_isstr(s, IS_PRINT))
		return (E_ERROR);
	else if (1 != ft_strnstr_nb(s, ft_linechecker_id(p), ft_strlen(s)))
		return (E_ERROR);
	else if (ft_strnstr_nb(s, " ./", ft_strlen(s)) > 0)
	{
		if (1 != ft_strnstr_nb(s, " ./", ft_strlen(s)))
			return (E_ERROR);
		else if (1 != ft_strnstr_nb(s, ".xpm", ft_strlen(s)))
			return (E_ERROR);
		*bl = true;
		return (E_TRUE);
	}
	else if (ft_strnstr_nb(s, ",", ft_strlen(s)) != 2)
		return (E_ERROR);
	*bl = true;
	return (E_TRUE);
}

t_error	ft_getinfo_line_chk_node(t_pars p, char *s)
{
	t_error		(*linecheckers[8])(t_pars p, char *s, bool *barr);
	bool		barr[8];
	int			i;

	i = 0;
	ft_bzero(barr, sizeof(barr));
	linecheckers[0] = ft_linechecker_resolution;
	linecheckers[1] = ft_linechecker_wall_sprite;
	linecheckers[2] = ft_linechecker_wall_sprite;
	linecheckers[3] = ft_linechecker_wall_sprite;
	linecheckers[4] = ft_linechecker_wall_sprite;
	linecheckers[5] = ft_linechecker_wall_sprite;
	linecheckers[6] = ft_linechecker_ceil_floor;
	linecheckers[7] = ft_linechecker_ceil_floor;
	if (p == E_OUT)
	{
		while (i < 8)
			if (!barr[i++])
				return (E_ERROR);
		return (E_TRUE);
	}
	return (linecheckers[p](p, s, &barr[p]));
}
