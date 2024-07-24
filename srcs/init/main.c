/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:43:15 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/11 14:52:44 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/mlx_setup.h"
#include "../../inc/leader.h"
#include <unistd.h>

t_error	ft_error_arg(void)
{
	printf("Error\n");
	printf("Please respect this format : ./Cub3D [.cub] [--save]\n");
	return (E_ERROR);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_error_arg());
	if (argc > 3)
		return (ft_error_arg());
	if (argc == 3)
	{
		if (!argv[2])
			return (ft_error_arg());
		if (ft_strcmp(argv[2], "--save") == 0)
		{
			if (ft_save_cub3d(argv[1], "save.bmp") == E_ERROR)
				return (-1);
		}
		else
			return (ft_error_arg());
	}
	else if (argc == 2)
	{
		if (ft_cub3d(argv[1]) == E_ERROR)
			return (-1);
	}
	return (0);
}
