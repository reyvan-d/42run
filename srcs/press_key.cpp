/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:26:20 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:26:22 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

/*
** Old Code:
**if (key == GLUT_KEY_LEFT)
**		g_pos.deltaAngle = -0.05;
**	else if (key == GLUT_KEY_RIGHT)
**		g_pos.deltaAngle = 0.05;
**	else if (key == GLUT_KEY_UP)
**		g_pos.deltaMove += 1.0;
**	else if (key == 27)
**		exit(0);
**	else if (key == GLUT_KEY_DOWN)
**		g_pos.deltaMove -= 1.0;
*/

void	press_key(int key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == GLUT_KEY_RIGHT && g_eye.ex > -2)
		g_eye.ex -= 2;
	else if (key == GLUT_KEY_LEFT && g_eye.ex < 2)
		g_eye.ex += 2;
	else if (key == GLUT_KEY_UP && g_eye.ey < 0.2)
		g_eye.ey = 5;
	else if (key == GLUT_KEY_DOWN)
		g_eye.ey = 0;
	else if (key == 27)
		exit(0);
}
