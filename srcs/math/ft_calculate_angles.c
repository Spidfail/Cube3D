#include "../../inc/mlx_setup.h"

double	ft_scalar(t_rlist *ray1, t_rlist *ray2)
{
	return (ray1->x * ray2->x + ray1->y * ray2->y + ray1->z * ray2->z);
}

double	ft_calculate_rays_angle(t_rlist *ray1, t_rlist *ray2)
{
	double		rtn;

	rtn = ft_scalar(ray1, ray2);
	rtn /= ray1->norm * ray2->norm;
	return (rtn);
}

double	ft_calculate_vect_norme(t_rlist vect)
{
	return (sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z));
}

void	ft_normalized_vect(t_rlist *dst, t_rlist vect)
{
	dst->x = vect.x / vect.norm;
	dst->y = vect.y / vect.norm;
	dst->z = vect.z / vect.norm;
	return ;
}
