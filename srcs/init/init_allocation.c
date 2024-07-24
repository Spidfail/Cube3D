#include "../../inc/pars.h"
#include "../../inc/build.h"
#include "../../inc/mlx_setup.h"
#include "../../inc/minimap.h"
#include "../../inc/leader.h"
#include "../../inc/global_strct.h"
#include "../../inc/global_enum.h"
#include "../../inc/global_error.h"

t_error	ft_allocate_root(t_rsrcs *rsrcs)
{
	if (!rsrcs)
		return (E_ERROR);
	rsrcs->dspl = ft_calloc(1, sizeof(t_displ));
	if (!rsrcs->dspl)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->map = ft_calloc(1, sizeof(t_map));
	if (!rsrcs->map)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->objlst = ft_calloc(1, sizeof(t_objlst));
	if (!rsrcs->objlst)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->mlx = ft_calloc(1, sizeof(t_mlxset));
	if (!rsrcs->mlx)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->player = ft_calloc(1, sizeof(t_player));
	if (!rsrcs->player)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->threads = ft_calloc(1, sizeof(t_thrd_p));
	if (!rsrcs->threads)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	rsrcs->keycode = ft_calloc(1, sizeof(t_keycode));
	if (!rsrcs->keycode)
		return (ft_release_rsrcs(rsrcs, E_ERROR));
	return (E_TRUE);
}
