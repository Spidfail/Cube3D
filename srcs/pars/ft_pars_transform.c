#include "../../inc/leader.h"
#include "../../inc/pars.h"
#include "../../libs/ulyss/ulyss.h"

t_error	ft_map_transform(t_map *map)
{
	char		**mrtn;

	mrtn = NULL;
	if (map == NULL)
		return (E_ERROR);
	mrtn = ft_dbl_chrcalloc(map->m_y[1] + 1, map->m_x[1] + 1);
	if (!mrtn)
		return (E_ERROR);
	if (ft_ulysses(map, mrtn, map->plyxy[1], map->plyxy[0]) == E_ERROR)
	{
		ft_dblfree((void **)mrtn, map->m_y[1]);
		ft_dblfree((void **)map->map, map->m_y[1] + 1);
		mrtn = NULL;
		map->map = NULL;
		return (E_ERROR);
	}
	ft_dblfree((void **)map->map, map->m_y[1] + 1);
	map->map = mrtn;
	mrtn = NULL;
	return (E_TRUE);
}
