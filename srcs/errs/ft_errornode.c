/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errornode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 08:56:35 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/09 11:20:25 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/global_error.h"
#include "../../inc/global_strct.h"

static t_error	ft_error_pstr(char *custerr, char *pstr, char *fct)
{
	if (!pstr)
		printf("%s  ---- \n\n", custerr);
	else
		printf("%s: %s  ---- \n\n", custerr, pstr);
	if (fct != NULL && ISDEBUG)
		printf("	//////// DEBG - [%s]\n", fct);
	return (E_ERROR);
}

t_error	ft_error_pthread(t_thrd_p *threads, char *custerr, char *debg, int e)
{
	int		arr[8];
	int		i;

	i = -1;
	arr[0] = threads->erno1;
	arr[1] = threads->erno2;
	arr[2] = threads->erno3;
	arr[3] = threads->erno4;
	arr[4] = threads->erno1_j;
	arr[5] = threads->erno2_j;
	arr[6] = threads->erno3_j;
	arr[7] = threads->erno4_j;
	printf("Error\n");
	printf("\n\n	######################################\n");
	printf("\n	    		ERROR	    \n\n");
	while (++i < 8)
	{
		if (arr[i])
		{
			printf("%s : %s\n", strerror(arr[i]), custerr);
			if (debg != NULL)
				printf("\n	//////// DEBG - [%s]\n", debg);
		}
	}
	return (e);
}

t_error	ft_error_node(t_icode ec, int e, int err, char *fct)
{
	char	*(*errnode[10])(int e);

	errnode[0] = ft_parserr_getinfo;
	errnode[1] = ft_parserr_getmap;
	errnode[2] = ft_parserr_ulysses;
	errnode[3] = ft_parserr_general;
	errnode[4] = ft_parserr_objpars;
	errnode[5] = ft_disperr_mlx;
	printf("Error\n");
	printf("\n\n	######################################\n");
	printf("\n	    		ERROR	    \n\n");
	if (errno != 0)
	{
		perror(errnode[ec](e));
		if (fct != NULL && ISDEBUG)
			printf("\n	//////// DEBG - [%s]\n", fct);
	}
	else if (err == 0)
		return (ft_error_pstr(errnode[ec](e), NULL, fct));
	else
		return (ft_error_pstr(errnode[ec](e), strerror(err), fct));
	return (E_ERROR);
}

t_error	ft_error_print(char *str, char *debg, t_error e)
{
	printf("Error\n");
	printf("\n\n	######################################\n");
	printf("\n	    		ERROR	    \n\n");
	if (errno != 0)
	{
		perror(str);
		if (debg != NULL && ISDEBUG)
			printf("\n	//////// DEBG - [%s]\n", debg);
		printf("\n");
	}
	else
	{
		printf("%s  ---- \n\n", str);
		if (debg != NULL && ISDEBUG)
			printf("\n	//////// DEBG - [%s]\n", debg);
		printf("\n");
	}
	return (e);
}
