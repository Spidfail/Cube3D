#include "../../inc/leader.h"

double	ft_is_intersect_denominator(t_rlist *vect, t_plist *plan)
{
	return ((vect->x * plan->nvector[0])
		+ (vect->y * plan->nvector[1])
		+ (vect->z * plan->nvector[2]));
}

double	ft_calculate_numerator(t_player *player, t_plist *plan)
{
	return (-(player->ply_pos[0] * plan->nvector[0]
			+ player->ply_pos[1] * plan->nvector[1]
			+ player->ply_pos[2] * plan->nvector[2]
			+ plan->d));
}

void	ft_calculate_u(t_sprite *dst, t_sprite *sprite, t_rlist *ray)
{
	dst->u.x = ray->inters_pt[0] - sprite->plan_ray->point_xy[0];
	dst->u.y = ray->inters_pt[1] - sprite->plan_ray->point_xy[1];
	dst->u.z = 0;
}
