/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:11:53 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/10 12:59:23 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEADER_H
# define LEADER_H
# include <math.h>
# include "pars.h"
# include "global_enum.h"
# include "global_strct.h"
# include "global_types.h"
# include "../libs/libft/libft.h"
# include "../mlx/mlx.h"

# define RESX_MAX 2560
# define RESX_MIN 640
# define RESY_MAX 1440
# define RESY_MIN 360
# define SHADE 0.5
# define TMEXIT 100
# define MVT 0.05
# define ROT_SPEED 0.05
# define NOD_SPEED 0.05
# define ISDEBUG 0
# define GODMOD 1

t_error			ft_cub3d(char *cub);
t_error			ft_save_cub3d(char *cub, char *bmp);
t_error			ft_make_bmp(char *bmp, t_image *img, t_rsrcs *rsrcs);
t_error			ft_error_arg(void);

t_error			ft_allocate_root(t_rsrcs *rsrcs);
t_error			ft_init_pars(t_rsrcs *rsrcs, char *cub);
t_error			ft_init_objects(t_rsrcs *rsrcs);
t_error			ft_init_player(t_player *player, t_displ *dspl, t_map *map);
void			ft_init_threads(t_rsrcs *rsrcs);

char			*ft_pixel_put(t_image *image, int color, int x, int y);
unsigned int	ft_get_pixel_color(t_image *image, int x, int y);
unsigned int	*ft_get_pixel_address(t_image *image, int x, int y);

double			ft_scalar(t_rlist *ray1, t_rlist *ray2);
double			ft_calculate_rays_angle(t_rlist *ray1, t_rlist *ray2);
double			ft_calculate_vect_norme(t_rlist vect);
void			ft_normalized_vect(t_rlist *dst, t_rlist vect);
void			ft_calculate_u(t_sprite *dst, t_sprite *sprite, t_rlist *ray);

t_error			ft_intersection(t_player *player, t_rlist *vect, t_plist *plan);
t_error			ft_build_raycast(t_player *player);

double			ft_proportion(double bvalue, double nvalue);
double			ft_calculate_horizontal_ratio(double half_fov, double width);
double			ft_calculate_vertical_ratio(double half_fov,
					double h, double w);

void			ft_copy_ray(t_rlist *dst, t_rlist *src);
void			ft_copy_thread(t_tp_thread *dst, t_rsrcs *rsrcs);

void			ft_check_wall_priority(t_tp_thread *thread);
t_error			ft_set_wall_node(t_tp_thread *thread, t_objlst *objlst,
					t_rlist *ray);
double			ft_is_intersect_denominator(t_rlist *vect, t_plist *plan);
t_error			ft_is_impact(t_rlist *ray, t_map *map, char c, t_plist *plan);
double			ft_calculate_numerator(t_player *player, t_plist *plan);
t_error			ft_calculate_intersection(t_rlist *ray, t_plist *plan,
					t_tp_thread *thread, double denom);
t_error			ft_calculate_if_on_wall(t_player *player, t_rlist *vect,
					t_plist *plan);

t_error			ft_set_sprite_node(t_tp_thread *thread, t_objlst *objlst);

t_error			ft_decide_if_floor_or_ceil(t_tp_thread *thread);

int				ft_define_ray_wall_north(t_tp_thread *thread, t_rlist *ray,
					int pos, t_plist **plan);
int				ft_define_ray_wall_east(t_tp_thread *thread, t_rlist *ray,
					int pos, t_plist **plan);
int				ft_define_ray_wall_south(t_tp_thread *thread, t_rlist *ray,
					int pos, t_plist **plan);
int				ft_define_ray_wall_west(t_tp_thread *thread, t_rlist *ray,
					int pos, t_plist **plan);
int				ft_define_ray_ceil_floor(t_tp_thread *thread, t_rlist *ray,
					t_plist *plan);

void			ft_reset(t_tp_thread *thread);
t_error			ft_print_pixel(t_image *img_src, t_rlist *ray, t_displ *dspl);
t_image			*ft_fix_all_images(int id, t_tp_thread *thread);
void			ft_set_img_wall_floor_coordinate(t_rlist *ray,
					long int *coord_x, long int *coord_y, t_image *img);
void			ft_set_img_sprite_coordinate(t_rlist *ray, t_sprite *sprite,
					t_image *img);

void			ft_calculate_ratio(t_player *player);
void			ft_mlx_movement(t_rsrcs *rsrcs);
void			ft_mlx_rotation(t_rsrcs *rsrcs);
void			ft_application_of_matrix(t_player *player, t_rlist *ray,
					int wh);
t_error			ft_check_collision(t_rsrcs *rsrcs, double tmp_x, double tmp_y);

#endif
