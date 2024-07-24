#include "../../inc/build.h"

static void	ft_set_vector_ns(t_plist *link, double y)
{
	link->nvector[0] = 0;
	link->nvector[1] = 1;
	link->nvector[2] = 0;
	link->d = -y;
	return ;
}

static void	ft_set_vector_we(t_plist *link, double x)
{
	link->nvector[0] = 1;
	link->nvector[1] = 0;
	link->nvector[2] = 0;
	link->d = -x;
	return ;
}

void	ft_set_vector(t_plist *link, t_oinfo *info, int ws)
{
	if (ws == WE_NORTH)
		ft_set_vector_ns(link, info->pos_y + 1);
	else if (ws == WE_SOUTH)
		ft_set_vector_ns(link, info->pos_y);
	else if (ws == WE_WEST)
		ft_set_vector_we(link, info->pos_x + 1);
	else if (ws == WE_EAST)
		ft_set_vector_we(link, info->pos_x);
}

t_error	ft_set_vector_clfl(t_plist *link, t_wside ws)
{
	link->nvector[0] = 0;
	link->nvector[1] = 0;
	link->nvector[2] = 1;
	if (ws == WE_FLOOR)
		link->d = 0;
	if (ws == WE_CEIL)
		link->d = -1;
	return (E_TRUE);
}

t_error	ft_set_things_point(t_plist *link, t_oinfo *info)
{
	if (info->pos_x < 0 || info->pos_y < 0 || !link)
		return (ft_error_node(4, 4, 0, "ft_set_things_point"));
	link->point_xy[0] = (double)info->pos_x + 0.5;
	link->point_xy[1] = (double)info->pos_y + 0.5;
	return (E_TRUE);
}
