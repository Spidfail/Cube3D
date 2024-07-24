#include "../../inc/mlx_setup.h"

static t_error	ft_set_sprite_intersection(t_tp_thread *thread,
		t_sprite **sp_lst, t_error e)
{
	short		i;
	double		denom;

	i = -1;
	denom = 0;
	while (++i <= thread->rsrcs->objlst->sp_max)
	{
		if (sp_lst[i]->sgn_scalar >= 0)
		{
			denom = ft_is_intersect_denominator(&thread->tp_ray,
					sp_lst[i]->plan_ray);
			if (denom != 0)
			{
				if (ft_calculate_sprite_intersection(&thread->tp_ray,
						sp_lst[i], thread, denom) == E_TRUE)
					e = E_TRUE;
			}
		}
	}
	return (e);
}

t_error	ft_set_sprite_node(t_tp_thread *thread, t_objlst *objlst)
{
	if (ft_set_sprite_intersection(thread, objlst->things, E_STOP)
		== E_STOP)
		return (E_STOP);
	return (E_TRUE);
}
