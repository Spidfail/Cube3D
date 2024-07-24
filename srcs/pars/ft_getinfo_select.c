/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo_select.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:36:15 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 10:00:24 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/pars.h"

t_pars	ft_get_enum_info(char *s)
{
	char	*id[8];
	int		j;
	int		i;

	j = 0;
	i = 0;
	id[0] = "R ";
	id[1] = "NO ";
	id[2] = "SO ";
	id[3] = "WE ";
	id[4] = "EA ";
	id[5] = "S ";
	id[6] = "F ";
	id[7] = "C ";
	while (j < 8)
	{
		if (0 == ft_strncmp(&s[i], id[j], ft_strlen(id[j])))
			return (j);
		j++;
	}
	return (j);
}

void	*ft_getinfo_select_displ(t_pars p, t_displ *dspl)
{
	void	*stct[8];

	stct[0] = &dspl->res;
	stct[1] = &dspl->no;
	stct[2] = &dspl->so;
	stct[3] = &dspl->we;
	stct[4] = &dspl->ea;
	stct[5] = &dspl->spr;
	stct[6] = &dspl->floor;
	stct[7] = &dspl->ceilg;
	return (stct[p]);
}

static t_error	ft_getinfo_select(t_pars p, char *s, t_displ *dspl)
{
	t_error	(*pars[8])(void *, char *s);
	t_error	(*parstxt[8])(void **, char *s);

	pars[0] = ft_get_res;
	pars[6] = ft_get_color;
	pars[7] = ft_get_color;
	parstxt[0] = NULL;
	parstxt[1] = &ft_get_wtxt;
	parstxt[2] = &ft_get_wtxt;
	parstxt[3] = &ft_get_wtxt;
	parstxt[4] = &ft_get_wtxt;
	parstxt[5] = &ft_get_wtxt;
	parstxt[6] = &ft_get_wtxt;
	parstxt[7] = &ft_get_wtxt;
	if (p == 0)
		return (pars[p](ft_getinfo_select_displ(p, dspl), s));
	else if (p == 6)
		return (ft_is_color_or_texture(pars[p]((void *)&dspl->fhex, s),
			parstxt[p](ft_getinfo_select_displ(p, dspl), s)));
	else if (p == 7)
		return (ft_is_color_or_texture(pars[p]((void *)&dspl->chex, s),
			parstxt[p](ft_getinfo_select_displ(p, dspl), s)));
	else
		return (parstxt[p](ft_getinfo_select_displ(p, dspl), s));
	return (E_ERROR);
}

t_error	ft_isparsed_info(int p, bool *chkp)
{
	int			i;

	i = 0;
	if (p < 0)
		return (E_ERROR);
	if (p > 7)
	{
		while (i < 8)
		{
			if (chkp[i] == false)
				return (E_STOP);
			i++;
		}
		return (E_TRUE);
	}
	if (chkp[p] == true)
		return (E_STOP);
	else
		chkp[p] = true;
	return (E_TRUE);
}

t_error	ft_getinfo_node_parsing(size_t i, t_displ *dspl, t_error e)
{
	t_pars	p;

	p = ft_get_enum_info(&dspl->buff[i]);
	if (E_ERROR == ft_isallparsed(e, p))
	{
		printf("\n");
		ft_print_line(dspl->buff, dspl->lnu);
		return (E_ERROR);
	}
	if (p == E_OUT)
		return (E_STOP);
	else if (p < E_OUT)
	{
		if (ft_getinfo_line_chk_node(p, dspl->buff))
		{
			if (ft_getinfo_select(p, dspl->buff, dspl) == E_TRUE)
			{
				dspl->buff = ft_free(dspl->buff);
				return (E_TRUE);
			}
		}
	}
	return (ft_error_node(PS_INF, p, 0, "ft_getinfo_node_parsing"));
}
