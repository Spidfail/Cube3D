#include "../../inc/mlx_setup.h"

static void	ft_is_impact_north(int *x, int *y, t_rlist *ray, t_plist *plan)
{
	*x = (int)ray->inters_pt[0];
	*y = (int)(-(plan->d) - 1);
}

static void	ft_is_impact_south(int *x, int *y, t_rlist *ray, t_plist *plan)
{
	*x = (int)ray->inters_pt[0];
	*y = (int)(-(plan->d));
}

static void	ft_is_impact_west(int *x, int *y, t_rlist *ray, t_plist *plan)
{
	*x = (int)(-(plan->d) - 1);
	*y = (int)(ray->inters_pt[1]);
}

static void	ft_is_impact_east(int *x, int *y, t_rlist *ray, t_plist *plan)
{
	*x = (int)(-(plan->d));
	*y = (int)ray->inters_pt[1];
}

t_error	ft_is_impact(t_rlist *ray, t_map *map, char c, t_plist *plan)
{
	int			x;
	int			y;
	void		(*arr[4])(int *, int *, t_rlist *ray, t_plist *plan);

	arr[0] = ft_is_impact_north;
	arr[1] = ft_is_impact_south;
	arr[2] = ft_is_impact_west;
	arr[3] = ft_is_impact_east;
	if (plan->id > 3)
		return (E_TRUE);
	arr[plan->id](&x, &y, ray, plan);
	if (x > (int)map->m_x[1] || x < 0)
		return (E_STOP);
	else if (y > (int)map->m_y[1] || y < 0)
		return (E_STOP);
	if (map->map[y][x] == c)
		return (E_TRUE);
	return (E_STOP);
}
