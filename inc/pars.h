/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:47:25 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 16:23:45 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H
# define MPATH "map.cub"
# include "global_enum.h"
# include "global_strct.h"
# include "global_types.h"
# include "global_error.h"
# include "../libs/gnl/get_next_line.h"

t_error	ft_pars(t_map *map, t_displ *dspl, char *s);

int		ft_check_path(char *s, t_path path);
char	*ft_check_open(char *s);
char	*ft_check_rdwr(char *s);
t_error	ft_parsing_gnl_info(int fd, t_displ *dspl);
t_error	ft_parsing_gnl_map(int fd, char **s, t_map *map, bool *berr);
t_error	ft_pars_skip_empty_line(int fd, char **s, size_t *lnu);
size_t	ft_space_escape(char *s, size_t i);

t_error	ft_getinfo_line_chk_node(t_pars p, char *s);
t_error	ft_pars_checkinfo(t_displ *dspl);

t_error	ft_getinfo_node_parsing(size_t i, t_displ *dspl, t_error e);
void	*ft_getinfo_select_displ(t_pars p, t_displ *dspl);
t_error	ft_getinfo_skip_id_lines(int fd, t_displ *dspl);

t_error	ft_getmap_set_positions(t_map *map, char *s, size_t i, bool *berr);
t_error	ft_getmap_size(t_mpars mapenum, t_map *map, size_t x, size_t y);
t_error	ft_getmap_chained_map(t_map *map, char *s);
t_error	ft_getmap_line_exam(char *s, t_map *map, bool *berr);

t_error	ft_map_transform(t_map *map);

char	**ft_map_copy_list(t_map *map, t_list **tempmap);
t_pars	ft_get_enum_info(char *s);
int		ft_get_enum_map(char c);
t_error	ft_get_res(void *stct, char *s);
t_error	ft_get_wtxt(void **stct, char *s);
t_error	ft_get_color(void *stct, char *s);
t_error	ft_is_color_or_texture(t_error color, t_error texture);

t_error	ft_isemptyline(char *s);
t_error	ft_isparsed_info(int p, bool *chkp);
t_error	ft_isallparsed(t_error e, t_pars p);
t_error	ft_ismap(char c);
size_t	ft_map_width(char **map);

char	*ft_parserr_getinfo(int wh);
char	*ft_parserr_getmap(int wh);
char	*ft_parserr_ulysses(int wh);
t_error	ft_parsclean(t_error e, t_map *map, t_displ *dspl);
t_error	ft_clean_dsplcomplete(t_displ *dspl);
t_error	ft_clean_mapcomplete(t_map *map);
t_error	ft_clean_gnl(t_error e, char **s, t_list **lst);
int		ft_print_line(char *s, size_t ln);

#endif
