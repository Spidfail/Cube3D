/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:29:34 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/10 10:27:43 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_ERROR_H
# define GLOBAL_ERROR_H
# include "../libs/libft/libft.h"
# include "global_types.h"
# include "global_enum.h"
# include "global_strct.h"
# include <errno.h>

typedef enum e_objectpars
{
	WP_CREATE = 1,
}					t_objpars;

int			ft_kill(t_rsrcs *rsrcs);
t_error		ft_kill_them_all(t_rsrcs *rsrcs, t_error e);
t_error		ft_kill_all_objects(t_objlst *objlst, t_map *map, t_error e);
t_error		ft_clean_minimap(t_mlxset *mlx, t_error e);

t_error		ft_error_node(t_icode ec, int e, int err, char *fct);
t_error		ft_error_pthread(t_thrd_p *threads, char *custerr,
				char *debg, int e);
char		*ft_parserr_general(int wh);
char		*ft_parserr_objpars(int wh);
char		*ft_disperr_mlx(int wh);
t_error		ft_dblfree(void **pt, int nb);

t_error		ft_release_rsrcs(t_rsrcs *rsrcs, t_error e);
t_error		ft_free_things(t_objlst *objlst, int i, int tmp_i, t_error e);
t_error		ft_free_objects(t_objlst *objlst, t_error e);
void		ft_free_plan_array(t_plist **planlist);

t_error		ft_free_player(t_player *player, t_error e);

t_error		ft_error_print(char *str, char *debg, t_error e);
void		ft_print_log(char *str);

#endif
