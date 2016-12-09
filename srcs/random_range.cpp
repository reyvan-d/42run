/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_range.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 06:31:55 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 06:31:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

/*
** Old rand:
**unsigned int	k;
**	do
**	{
**		k = rand();
**	} while (k < ((unsigned int)(RAND_MAX) + 1) % (max + 1 - min));
**	return (k % (max + 1 - min) + min);
*/

int		random_range(int min, int max)
{
	//unsigned int	k;

//	srand(rand());
//	do
//	{
//		k = rand();
//	} while (k < ((unsigned int)(RAND_MAX) + 1) % (max + 1 - min));
//	return (k % (max + 1 - min) + min);
	return ((int)rand() % (max - min + 1) + min);
}