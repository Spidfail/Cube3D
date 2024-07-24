# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 10:59:24 by guhernan          #+#    #+#              #
#    Updated: 2021/05/12 11:10:51 by guhernan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= cubddd.a
EXEC	= cub3D
CC 		= gcc
CFLAGS 	= -O2 -march=native -Wall -Wextra -Werror
#CSAN	= -fsanitize=address -g3
AR		= ar -rcs
LAR		= libft.a
LMLX	= mlx/

VPATH	= inc srcs objs libs $(VMLX) $(VLIBS) $(VULYSS) $(VSRCS) $(VINIT) $(VBUILDO) $(VMLXSET) $(VMLXEVT) $(VPRINT) $(VRAYCAST) $(VMINMAP) $(VIMG_MOD) $(VMATH) $(OBJ_DIR) $(VERR)

VMLX	= mlx
VINIT	= srcs/init
VLIBS 	= libs/gnl libs/libft libs/ulyss
VLIBFT	= libs/libft
VULYSS	= libs/ulyss
VBUILDO = srcs/build_obj
VPRINT	= srcs/mlx_print
VMLXSET	= srcs/mlx_setup
VMLXEVT	= srcs/mlx_events
VRAYCAST= srcs/raycast
VIMG_MOD= srcs/image_mod
VMINMAP = srcs/minimap
VMATH	= srcs/math

VSRCS	= srcs/pars 
VERR	= srcs/errs

OBJ_DIR	= objs
OBJSPATH= $(addprefix $(OBJ_DIR)/, $(OBJS) )

INCS	= inc/pars.h inc/leader.h $(VULYSS)/ulyss.h libs/libft/libft.h libs/gnl/get_next_line.h \
		  inc/global_error.h inc/global_strct.h inc/global_types.h inc/global_enum.h \
		  inc/build.h inc/mlx_setup.h inc/minimap.h $(VMLX)/mlx.h
CINCS	= $(addprefix -I , $(INCS) )

BMP		= save.bmp

INIT	= ft_cub3d.c \
		  ft_save.c \
		  ft_make_bmp.c \
		  main.c \
		  init_pars.c \
		  init_allocation.c \
		  init_objects.c \
		  init_player.c \
		  init_threads.c

SRCS 	= ft_getinfo_line_checkers.c \
		  ft_getinfo_res.c \
		  ft_getinfo_txtfc.c \
		  ft_getinfo_fc.c \
		  ft_getinfo_select.c \
		  ft_getinfo_utils.c \
		  ft_getmap_select.c \
		  ft_getmap_utils.c \
		  ft_getmap_line_checkers.c \
		  ft_pars.c \
		  ft_pars_utils.c \
		  ft_pars_lst_utils.c \
		  ft_pars_checkinfo.c \
		  ft_pars_gnl.c \
		  ft_pars_transform.c

BUILDO	= build_create_obj.c \
		build_set_obj.c \
		ft_get_object.c \
		ft_build_wall_node.c \
		ft_build_walls.c \
		ft_build_sprites.c

MLXSET	= ft_mlx_build_images.c \
		  ft_build_cf_images.c \
		  ft_mlx_create.c \
		  ft_mlx_setup.c \
		  ft_mlx_put_player.c \
		  ft_init_calculate_wall.c \
		  ft_init_calculate_sprite.c \
		  ft_init_calculate_ceil_floor.c \
		  ft_clean_images.c \

MLXEVENT = ft_kheys.c \
		   ft_mlx_close.c \
		   ft_movements.c \
		   ft_collision.c \
		   ft_rotation.c

IMG_MOD = pixel_mod.c \

PRINT	= ft_mlx_print_images.c \
		  ft_mlx_set_sprite.c \
		  ft_mlx_pixel_node.c \
		  ft_mlx_set_coordinate.c \
		  ft_mlx_set_pixel.c \
		  ft_mlx_set_pixel_utils.c \
		  ft_mlx_wall_check.c \
		  ft_mlx_set_wall.c

RAYCAST = ft_raycast.c \
		  ft_raycast_intersect.c \
		  ft_is_impact.c

MINMAP	= ft_minimap.c \
		  minimap_generate.c

MATH	= proportions.c \
		  ft_calculate_angles.c \
		  ft_calculate_ratio.c \
		  ft_matrix.c

ESRCS	= ft_disperr.c \
		  ft_errornode.c \
		  ft_free_init.c \
		  ft_parserr.c \
		  ft_release.c \
		  build_clean.c

LSRCS	= get_next_line.c \
		  get_next_line_bonus.c \
		  get_next_line_utils.c \
		  get_next_line_utils_bonus.c \
		  ft_ulysses.c \
		  ft_ulysses_utils.c

OBJS	= $(SRCS:.c=.o) $(LSRCS:.c=.o) $(ESRCS:.c=.o) $(INIT:.c=.o) $(BUILDO:.c=.o) $(RAYCAST:.c=.o) \
	$(PRINT:.c=.o) $(MLXSET:.c=.o) $(MLXEVENT:.c=.o) $(MINMAP:.c=.o) $(IMG_MOD:.c=.o) $(MATH:.c=.o)

all :		lib $(NAME) $(EXEC)

$(NAME) :	$(OBJS) $(LAR) | $(OBJ_DIR)
	cp $(VLIBFT)/$(LAR) ./
	mv ./$(LAR) ./$(NAME)
	$(AR) $(NAME) $(OBJSPATH)

$(EXEC) :	$(NAME)
	$(CC)  -I$(VMLX) $(NAME) -o $(EXEC) -framework OpenGL -framework AppKit -Lmlx -lmlx 

%.o:		%.c $(INCS)
	$(CC)  $(CFLAGS) $(CINCS) -c $< -o $(OBJ_DIR)/$@

lib :
	$(MAKE) -C libs/libft/ bonus
	$(MAKE) -C mlx

$(LAR) :
	$(MAKE) -C libs/libft/ bonus
	$(MAKE) -C mlx

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

.PHONY :	all lib clean fclean re

clean :
	$(MAKE) -C libs/libft/ clean
	$(MAKE) -C mlx clean
	$(RM) $(OBJSPATH)

fclean :	clean
	$(MAKE) -C libs/libft/ fclean
	$(RM) $(NAME) $(EXEC)

re :		fclean all

