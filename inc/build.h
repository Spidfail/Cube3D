#ifndef BUILD_H
# define BUILD_H

# include "leader.h"
# include "global_types.h"
# include "global_enum.h"
# include "global_strct.h"

typedef enum e_wallside
{
	WE_NORTH = 0,
	WE_SOUTH,
	WE_WEST,
	WE_EAST,
	WE_CEIL,
	WE_FLOOR,
	WE_OUT = 4,
}			t_wside;

typedef enum e_thingtype
{
	THE_CENTER = 0,
	THE_OUT,
}			t_thtype;

typedef struct s_objectinfo
{
	double			point_xy[2];
	int				pos_x;
	int				pos_y;
	int				d;
}			t_oinfo;

t_error		ft_get_objects(t_map *map, t_objlst *objlst);

t_error		ft_build_wall_if_possible(t_oinfo *info,
				t_objlst *objlst, t_map *map);
t_error		ft_build_sprite_if_possible(t_oinfo *info, t_objlst *objlst);
t_error		ft_build_north_wall(t_objlst *objlst, t_oinfo *info);
t_error		ft_build_south_wall(t_objlst *objlst, t_oinfo *info);
t_error		ft_build_east_wall(t_objlst *objlst, t_oinfo *info);
t_error		ft_build_west_wall(t_objlst *objlst, t_oinfo *info);

t_plist		*ft_create_sprite(t_oinfo *info);
t_plist		*ft_raylst_new(void);
void		ft_set_vector(t_plist *link, t_oinfo *info, int ws);
t_error		ft_set_vector_clfl(t_plist *link, t_wside ws);
t_error		ft_set_things_point(t_plist *link, t_oinfo *info);

t_error		ft_is_wall_to_build(t_objlst *objlst, t_oinfo *info);

#endif
