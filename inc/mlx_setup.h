#ifndef MLX_SETUP_H
# define MLX_SETUP_H

# include "global_enum.h"
# include "global_strct.h"
# include "global_error.h"
# include "global_types.h"
# include "leader.h"
# include "../mlx/mlx.h"

typedef enum e_mlx_enum
{
	MLX_CREATE_INIT = 0,
	MLX_CREATE_WINDW,
	MLX_CREATE_IMAGE,
}				t_mlxen;

typedef enum e_mlx_error
{
	ME_INIT = 0,
	ME_WINDW,
}				t_mlxerr;

t_error		ft_mlx_setup(t_rsrcs *rsrcs);
t_error		ft_mlx_create(t_rsrcs *rsrcs, t_mlxen id);
t_error		ft_mlx_build_images(t_rsrcs *rscrcs);
t_error		ft_mlx_build_images_ceil_floor(t_rsrcs *rsrcs);
t_error		ft_build_choosen_texture(void *init, char *path,
				t_image *image);
t_error		ft_mlx_set_color_image(unsigned int color, t_image *image);
t_error		ft_mlx_print_images(t_rsrcs *rsrcs);

t_error		ft_set_print_images(t_displ *dspl, t_mlxset *mlx);

t_error		ft_setup_clean_images(t_mlxset *mlx, t_error e);

t_error		ft_set_pixel(t_rsrcs *rsrcs, t_rlist *ray);
t_error		ft_set_pixel_node(t_rsrcs *rsrcs, int position, int x, int y);
t_error		ft_print_pixel_on_image(t_image *img, t_rsrcs *rsrcs);

t_error		ft_init_calculate_plan_numerator(t_rsrcs *rsrcs);
void		ft_init_calculate_ceil_floor_numerator(t_rsrcs *rsrcs);
t_error		ft_init_calculate_sprites(t_rsrcs *rsrcs);

t_error		ft_calculate_sprite_intersection(t_rlist *ray, t_sprite *sprite,
				t_tp_thread *thread, double denom);

int			ft_mlx_keypress(int keycode, t_rsrcs *rsrcs);
int			ft_mlx_keyrelease(int keycode, t_rsrcs *rsrcs);
int			ft_exit_switch(t_rsrcs *rsrcs);

void		ft_keycode_movement(t_keycode *keycode, t_rsrcs *rsrcs);
int			ft_mlx_close(t_mlxset *mlx);

#endif
