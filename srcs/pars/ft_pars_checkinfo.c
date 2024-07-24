#include "../../inc/pars.h"
#include "../../inc/leader.h"

static t_error	ft_checkinfo_extension(char *str, int id)
{
	t_error		e;

	e = E_TRUE;
	if (ft_strnstr_nb(str, ".xpm", ft_strlen(str)) == 1)
		return (e);
	else
	{
		e = E_STOP;
		ft_error_node(PS_INF, id, 0, "ft_checkinfo_extension");
		ft_error_print(" [PARS] Please use a .xpm image file for textures",
			"ft_checkinfo_extension", E_ERROR);
	}
	return (e);
}

static t_error	ft_checkinfo_open(char *str, int i)
{
	t_error	e;

	e = E_TRUE;
	if (!str || !ft_check_open(str))
	{
		e = E_STOP;
		if (!str)
			ft_error_node(PS_INF, 13, 0, "ft_checkinfo_open");
		else
			ft_error_node(PS_INF, i + 1, 0, "ft_checkinfo_open");
	}
	return (e);
}

static t_error	ft_checkinfo_ceil_floor_path(t_displ *dspl)
{
	if ((dspl->floor == NULL && dspl->fhex < 0)
		|| (dspl->ceilg == NULL && dspl->chex < 0))
		return (E_ERROR);
	if (dspl->floor != NULL)
	{
		if (E_STOP == ft_checkinfo_open(dspl->floor, 5))
			return (E_ERROR);
		else if (dspl->floor)
			if (E_STOP == ft_checkinfo_extension(dspl->floor, 5 + 1))
				return (E_ERROR);
	}
	if (dspl->ceilg != NULL)
	{
		if (E_STOP == ft_checkinfo_open(dspl->ceilg, 6))
			return (E_ERROR);
		else if (dspl->ceilg)
			if (E_STOP == ft_checkinfo_extension(dspl->ceilg, 6 + 1))
				return (E_ERROR);
	}
	return (E_TRUE);
}

static t_error	ft_checkinfo_texturepath(t_displ *dspl)
{
	char	*arr[8];
	int		i;
	t_error	e;

	i = -1;
	e = E_TRUE;
	arr[0] = dspl->no;
	arr[1] = dspl->so;
	arr[2] = dspl->we;
	arr[3] = dspl->ea;
	arr[4] = dspl->spr;
	arr[5] = dspl->floor;
	arr[6] = dspl->ceilg;
	arr[7] = NULL;
	while (++i < 5)
	{
		if (E_STOP == ft_checkinfo_open(arr[i], i))
			e = E_ERROR;
		else if (arr[i])
			if (E_STOP == ft_checkinfo_extension(arr[i], i + 1))
				e = E_ERROR;
	}
	if (ft_checkinfo_ceil_floor_path(dspl) == E_ERROR)
		return (E_ERROR);
	return (e);
}

t_error	ft_pars_checkinfo(t_displ *dspl)
{
	int		e;

	e = 0;
	if (dspl->buff)
	{
		free(dspl->buff);
		dspl->buff = NULL;
	}
	if (dspl->res[1] > RESY_MAX || dspl->res[0] > RESX_MAX
		|| dspl->res[1] < RESY_MIN || dspl->res[0] < RESX_MIN)
		ft_error_node(PS_INF, 0, 0, "ft_checkinfo");
	e = ft_checkinfo_texturepath(dspl);
	dspl->i = 0;
	dspl->lnu = 0;
	return (e);
}
