#ifndef MINIMAP_H
# define MINIMAP_H

# include "global_strct.h"
# include "global_error.h"
# include "leader.h"
# include "mlx_setup.h"

t_error		ft_put_minimap_to_image(t_image *dst, t_image *src,
				t_minimap param);
t_minimap	*ft_minimap_events(t_map *map, t_displ *dspl, t_mlxset *mlx);
t_image		*ft_minimap_generate(t_mlxset *mlx, t_map *map);
void		ft_minimap_put_player(t_rsrcs *rsrcs);

#endif
