/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:26:29 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:26:30 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	release_key(int key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT)
		g_pos.deltaAngle = 0.0;
	if (key == GLUT_KEY_DOWN || key == GLUT_KEY_UP)
		g_pos.deltaMove = 0.0;
}
