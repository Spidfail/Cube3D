/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:57:49 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/10 10:04:29 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_set(char **line, t_buff *gnl, ssize_t scpy)
{
	if (scpy == -1)
	{
		if (line)
		{
			free(*line);
			*line = NULL;
		}
		return (-1);
	}
	gnl->nsave = 0;
	if ((size_t)scpy < (gnl->nread - gnl->i))
		gnl->i += scpy;
	else
	{
		gnl->i = 0;
		gnl->nread = 0;
	}
	return (0);
}

void	*ft_memoire_rpl(char **m1, void *m2, size_t size1, size_t size2)
{
	char	*temp;

	temp = NULL;
	temp = ft_memoire_join(*m1, m2, size1, size2);
	if (*m1)
	{
		free(*m1);
		*m1 = NULL;
	}
	return (temp);
}

ssize_t	ft_readload(int fd, char **line, t_buff *gnl)
{
	ssize_t	r;

	r = 0;
	if (gnl->nread)
	{
		if (0 < ft_memoire_chr(gnl->buff + gnl->i, '\n', gnl->nread - gnl->i))
			return (0);
		else
		{
			*line = ft_memoire_rpl(line, gnl->buff + gnl->i,
					gnl->nsave, gnl->nread - gnl->i);
			if (!*line)
				return (-1);
			gnl->nsave += (gnl->nread - gnl->i);
			gnl->i = 0;
			gnl->nread = 0;
		}
		return (1);
	}
	r = read(fd, gnl->buff, BUFFER_SIZE);
	if (-1 == r || r == 0)
		return (r);
	gnl->nread = r;
	return (1);
}

ssize_t	ft_linecpy(char **line, t_buff *gnl)
{
	size_t	scpy;

	scpy = 0;
	if (gnl->nread == 0)
	{
		*line = ft_memoire_rpl(line, gnl->buff, gnl->nsave, gnl->nread);
		if (!*line)
			return (-1);
		return (0);
	}
	scpy = ft_memoire_chr(&gnl->buff[gnl->i], '\n', gnl->nread - gnl->i);
	*line = ft_memoire_rpl(line, &gnl->buff[gnl->i], gnl->nsave, scpy - 1);
	if (*line == NULL)
		return (-1);
	return (scpy);
}

int	get_next_line(int fd, char **line)
{
	static t_buff		gnl[OPEN_MAX + 1];
	ssize_t				r;

	r = 1;
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (ft_set(line, &gnl[fd], -1));
	*line = NULL;
	while (r)
	{
		r = ft_readload(fd, line, &gnl[fd]);
		if (r == -1)
			return (ft_set(line, &gnl[fd], r));
	}
	r = ft_linecpy(line, &gnl[fd]);
	if (r == -1)
		return (ft_set(line, &gnl[fd], r));
	ft_set(line, &gnl[fd], r);
	if (r == 0)
		return (0);
	return (1);
}
