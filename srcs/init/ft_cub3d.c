#include "../../inc/pars.h"
#include "../../inc/build.h"
#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

static t_rsrcs	*ft_transfert_parts(t_map **map, t_displ **dspl,
t_objlst **objlst, t_rsrcs **rsrcs)
{
	(*rsrcs)->dspl = *dspl;
	(*rsrcs)->map = *map;
	(*rsrcs)->objlst = *objlst;
	return (*rsrcs);
}

t_error	ft_cub3d(char *cub)
{
	t_rsrcs		*rsrcs;

	rsrcs = ft_calloc(1, sizeof(t_rsrcs));
	if (ft_allocate_root(rsrcs) == E_ERROR)
	{
		ft_error_print("[ROOT] Failed to allocate ressources struct ",
			"ft_allocate_root", E_ERROR);
		return (ft_kill_them_all(rsrcs, E_ERROR));
	}
	if (ft_init_pars(rsrcs, cub) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	if (ft_init_objects(rsrcs) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	if (ft_init_player(rsrcs->player, rsrcs->dspl, rsrcs->map) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	ft_init_threads(rsrcs);
	ft_init_calculate_plan_numerator(rsrcs);
	ft_transfert_parts(&rsrcs->map, &rsrcs->dspl, &rsrcs->objlst, &rsrcs);
	if (ft_mlx_setup(rsrcs) == E_ERROR)
		return (ft_kill_them_all(rsrcs, E_ERROR));
	return (ft_kill_them_all(rsrcs, E_TRUE));
	return (E_TRUE);
}
