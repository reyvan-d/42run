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
	static int	screenstatus;
	(void)x;
	(void)y;

	if (g_game.mode == MODE_PAUSE)
	{
		if (key == 'p')
			g_game.mode = MODE_PLAY;
		else if (key == 27)
			exit(0);
		else if (key == 98)
			goto fscreen;
		return ;
	}
	if (key == GLUT_KEY_RIGHT && g_eye.ex > -2)
		g_eye.ex -= 3;
	else if (key == GLUT_KEY_LEFT && g_eye.ex < 2)
		g_eye.ex += 3;
	else if ((key == GLUT_KEY_UP || key == 32) && g_eye.ey < 0.2)
		g_eye.ey = 5;
	else if (key == GLUT_KEY_DOWN)
		g_eye.ey = 0;
	else if (key == 'p' && g_game.mode == MODE_PLAY)
		g_game.mode = MODE_PAUSE;
	else if (key == 'r' && g_game.mode == MODE_STOP)
	{
		g_game.mode = MODE_PLAY;
		if (g_game.score > g_game.high_score)
			g_game.high_score = g_game.score;
		g_game.time = 0;
		g_game.score = 0;
		g_game.health = 100;
	}
	else if (key == 27)
		exit_prog();
	else if (key == 98)
	{
fscreen:
		if (++screenstatus == 1)
			glutFullScreen();
		else
		{
			glutReshapeWindow(WIN_WIDTH, WIN_HEIGHT);
        	glutPositionWindow(WIN_X, WIN_Y);
        	screenstatus = 0;
		}
	}
}
