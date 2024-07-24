#include "../../inc/leader.h"
#include "../../inc/pars.h"
#include "../../libs/ulyss/ulyss.h"

t_error	ft_isallparsed(t_error e, t_pars p)
{
	static bool	chkp[8] = {false};

	if (e == E_TRUE && p < E_OUT)
		if (!ft_isparsed_info(p, chkp))
			return (ft_error_node(PS_INF, 10, 0, "ft_isallparsed"));
	if (e == E_STOP || e == E_ERROR || p == E_OUT)
	{
		if (!ft_isparsed_info(8, chkp))
		{
			ft_error_node(PS_INF, 13, 0, "ft_isallparsed");
			return (ft_error_node(PS_INF, 9, 0, "ft_isallparsed"));
		}
		else if (e == E_ERROR)
			return (E_ERROR);
	}
	return (E_TRUE);
}

t_error	ft_getinfo_skip_id_lines(int fd, t_displ *dspl)
{
	t_error		e;

	e = E_TRUE;
	e = ft_pars_skip_empty_line(fd, &(dspl->buff), &(dspl->lnu));
	while (e == E_TRUE)
	{
		if (ft_get_enum_info(dspl->buff) < 8)
			e = ft_parsing_gnl_info(fd, dspl);
		else
			e = E_STOP;
	}
	return (e);
}
