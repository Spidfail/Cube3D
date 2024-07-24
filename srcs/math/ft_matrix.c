#include "../../inc/leader.h"

static void	ft_raycast_x_matrix(t_player *player, t_rlist *vect)
{
	double		cosinus;
	double		sinus;

	cosinus = player->nod_cos;
	sinus = player->nod_sin;
	vect->y = cosinus * vect->y - sinus * vect->z;
	vect->z = sinus * vect->y + cosinus * vect->z;
}

static void	ft_raycast_y_matrix(t_player *player, t_rlist *vect)
{
	double		cosinus;
	double		sinus;

	cosinus = player->or_cos;
	sinus = player->or_sin;
	vect->x = cosinus * vect->x + sinus * vect->z;
	vect->z = -sinus * vect->x + cosinus * vect->z;
}

static void	ft_raycast_z_matrix(t_player *player, t_rlist *vect)
{
	double		tmp_a;

	tmp_a = vect->x;
	vect->x = (player->or_cos * vect->x) + (vect->y * -player->or_sin);
	vect->y = player->or_sin * tmp_a + vect->y * player->or_cos;
}

void	ft_application_of_matrix(t_player *player, t_rlist *ray, int wh)
{
	void	(*arr[3])(t_player *, t_rlist *);

	arr[0] = ft_raycast_z_matrix;
	arr[1] = ft_raycast_y_matrix;
	arr[2] = ft_raycast_x_matrix;
	return (arr[wh](player, ray));
}
