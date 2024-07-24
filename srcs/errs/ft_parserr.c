/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:19:00 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/08 17:29:46 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/leader.h"
#include "../../inc/pars.h"

char	*ft_parserr_getinfo(int wh)
{
	char	*sterr[17];

	sterr[0] = " [PARS] Incorrect resolution [R] ";
	sterr[1] = " [PARS] Incorrect texture [Wall North] ";
	sterr[2] = " [PARS] Incorrect texture [Wall south] ";
	sterr[3] = " [PARS] Incorrect texture [Wall west] ";
	sterr[4] = " [PARS] Incorrect texture [Wall east] ";
	sterr[5] = " [PARS] Incorrect texture [Sprite] ";
	sterr[6] = " [PARS] Incorrect texture [Floor] ";
	sterr[7] = " [PARS] Incorrect texture [Ceiling] ";
	sterr[8] = " [PARS] Incorrect ID, please define all of them correctly ";
	sterr[9] = " [PARS] Incorrect id and map order ";
	sterr[10] = " [PARS] ID already defined ";
	sterr[11] = " [PARS] Error while opening or closing the file ";
	sterr[12] = " [PARS] Unexpected EOF, please add a map ";
	sterr[13] = " [PARS] One or more ID informations are missing ";
	sterr[14] = " [PARS] Invalid color range [0 - 255] ";
	return (sterr[wh]);
}

char	*ft_parserr_getmap(int wh)
{
	char	*sterr[6];

	sterr[0] = " [PARS] Incorrect player position ";
	sterr[1] = " [PARS] Error - the player have more than one strating point ";
	sterr[2] = " [PARS] Incorrect map ";
	sterr[3] = " [PARS] Incorrect map wall ";
	sterr[4] = " [PARS] Error while opening or closing the file ";
	sterr[5] = " [PARS] Unexpected EOF, please add a starting point ";
	return (sterr[wh]);
}

char	*ft_parserr_general(int wh)
{
	char	*sterr[3];

	sterr[0] = " [PARS] Wrong file path ";
	sterr[1] = " [PARS] Error while opening the file ";
	sterr[2] = " [PARS] Unexpected error : while reading the file ";
	return (sterr[wh]);
}

char	*ft_parserr_ulysses(int wh)
{
	char	*sterr[6];

	sterr[0] = " [PARS] The map is not closed ";
	return (sterr[wh]);
}

char	*ft_parserr_objpars(int wh)
{
	char	*sterr[10];

	sterr[1] = " [PARS] Error while creating a raystruc ";
	sterr[2] = " [PARS] Wrong texture picked ";
	sterr[3] = " [PARS] Error while creating a link ";
	sterr[4] = " [PARS] Wrong sprite position ";
	return (sterr[wh]);
}
