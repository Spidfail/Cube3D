#include "../../inc/mlx_setup.h"

int	ft_kill(t_rsrcs *rsrcs)
{
	ft_kill_them_all(rsrcs, E_STOP);
	exit(0);
}
