/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:30:51 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/10 10:08:35 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# define BUFFER_SIZE 30

typedef struct s_buff
{
	size_t		i;
	size_t		nread;
	char		buff[BUFFER_SIZE + 1];
	size_t		nsave;
}				t_buff;

void			*ft_copy_alloc(size_t count, size_t size);
ssize_t			ft_linecpy(char **line, t_buff *gnl);
void			*ft_memoire_join(void *m1, void *m2, size_t size1,
					size_t size2);
size_t			ft_memoire_chr(void *s, int c, size_t n);
void			*ft_memoire_dup(void *src, size_t len);
void			*ft_memoire_cpy(void *dst, const void *src, size_t n);
void			*ft_memoire_rpl(char **m1, void *m2, size_t size1,
					size_t size2);
ssize_t			ft_readload(int fd, char **line, t_buff *gnl);
int				ft_set(char **line, t_buff *gnl, ssize_t scpy);
int				get_next_line(int fd, char **line);

#endif
