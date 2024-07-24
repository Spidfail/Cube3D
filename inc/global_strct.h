/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_strct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:53:28 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 12:34:12 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_STRCT_H
# define GLOBAL_STRCT_H
# include "../libs/libft/libft.h"
# include "global_types.h"
# include "global_enum.h"

typedef struct s_map
{
	char		**map;
	t_list		*lstmap;
	char		*name;
	bool		lock_x;
	bool		lock_y;
	size_t		m_x[2];
	size_t		m_y[2];
	int			plyxy[2];
	char		plyor;
	char		*buff;
	size_t		i;
	size_t		lnu;
	int			debg[2];
}					t_map;

typedef struct s_display
{
	int		res[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*spr;
	char	*floor;
	char	*ceilg;
	int		fhex;
	int		chex;
	char	*title;
	char	*buff;
	size_t	lnu;
	size_t	i;
}					t_displ;

typedef struct s_raylist
{
	double			x;
	double			y;
	double			z;
	double			norm;
	double			distance;
	unsigned int	color;
	double			inters_pt[3];
	int				id;
}					t_rlist;

typedef struct s_planlist
{
	double			nvector[3];
	double			d;
	double			point_xy[3];
	int				id;
	double			numerator;
}					t_plist;

typedef struct s_image
{
	void	*img_ptr;
	int		size[2];
	char	*area;
	int		bit_pix;
	int		endian;
	int		size_line;
	int		real_sline;
}					t_image;

typedef struct s_sprite_elements
{
	t_rlist		tp_ray;
	t_rlist		*ray;
	t_plist		*plan_ray;
	double		r;
	t_rlist		v;
	t_rlist		v2;
	t_rlist		v_prime;
	t_rlist		u;
	double		sgn_scalar;
}				t_sprite;

typedef struct s_objectslist
{
	t_plist			**plan_north;
	t_plist			**plan_south;
	t_plist			**plan_west;
	t_plist			**plan_east;
	t_plist			*plan_floor;
	t_plist			*plan_ceil;
	t_sprite		**things;
	bool			issprite;
	int				sp_max;
	t_list			*lst_thgs;
}					t_objlst;

typedef struct s_player_refs
{
	t_rlist		**rays_area;
	double		ply_pos[3];
	t_rlist		*v_dir;
	double		or_cos;
	double		or_sin;
	double		vratio;
	double		hratio;
	double		rotation_angle;
	double		nod_angle;
	double		nod_cos;
	double		nod_sin;
	int			cust_res[3];
	bool		is_even;
}					t_player;

typedef struct s_sqrt
{
	int		size_pix;
	int		pos_x;
	int		pos_y;
	int		interv;
}					t_sqrt;

typedef struct s_minimap
{
	int		size_back;
	int		size_x_max;
	int		size_y_max;
	int		fst_pos_x;
	int		fst_pos_y;
	int		nb_sqrt_x;
	int		nb_sqrt_y;
	int		nb_pix_sqrt;
	int		color_back;
	int		color_floor;
	int		color_wall;
	int		color_plyr;
	int		ratio;
}					t_minimap;

typedef struct s_mlx_set
{
	char		*bmp;
	void		*init;
	void		*window;
	bool		event;
	bool		which;
	int			exit;
	t_image		*print1;
	t_image		*img_north;
	t_image		*img_south;
	t_image		*img_west;
	t_image		*img_east;
	t_image		*img_sprite;
	t_image		*img_floor;
	t_image		*img_ceilg;
	t_image		*img_minimap;
	t_minimap	*minimap;
}				t_mlxset;

typedef struct s_thread_pool
{
	t_image		*img;
	pthread_t	th1;
	pthread_t	th2;
	pthread_t	th3;
	pthread_t	th4;
	int			erno1;
	int			erno2;
	int			erno3;
	int			erno4;
	int			erno1_j;
	int			erno2_j;
	int			erno3_j;
	int			erno4_j;
	int			pthread1;
	int			pthread2;
	int			pthread3;
	int			pthread4;
	int			pth_max1;
	int			pth_max2;
	int			pth_max3;
	int			pth_max4;
	int			res_qrt;
}				t_thrd_p;

typedef struct s_keycode
{
	bool	up;
	bool	right;
	bool	left;
	bool	down;
	bool	rot_left;
	bool	rot_right;
	bool	nod_up;
	bool	nod_down;
	bool	neg_mod;
}				t_keycode;

typedef struct s_resources
{
	t_displ		*dspl;
	t_map		*map;
	t_objlst	*objlst;
	t_mlxset	*mlx;
	t_player	*player;
	t_thrd_p	*threads;
	t_keycode	*keycode;
}				t_rsrcs;

typedef struct s_temp_set_pixel
{
	t_rlist		*ray;
	t_rlist		tp_ray;
	t_rsrcs		*rsrcs;
	t_image		*img;
	t_error		up_sp_x;
	t_error		up_sp_y;
}				t_tp_thread;

#endif
