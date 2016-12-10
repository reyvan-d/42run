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

void	menu_keys(int key, int x, int y)
{/*
	if (key == 'q')//escape keycode instead.
		exit(0);//exit	
	else if (g_menu_cursor < 0 && key == 'p')//if in game then pause menu
	{
		if (!g_pausemode)
		{
			glutDisplayFunc(displaypausemenu);
			g_pausemenu_cursor = 0;
		}
		else//pausmode deactivate
		{
			glutDisplayFunc(displayhighscores);//change to game display
			glutPostRedisplay();
		}
		g_pausemode = g_pausemode == 0;//special menu item code.
		glutPostRedisplay();
		return ;
	}
*/	if (key == ' ')//enter
	{
		if (g_menu_cursor > -1 && !g_menupos)//if its still in menu mode
		{
			if (g_menu_cursor == 0)
			{//PLAY
			 //g_pausemode = 0;//game is not paused.
				printf("%s\n", g_menu[g_menu_cursor]);
				glutDisplayFunc(displaymenu);
				glutPostRedisplay();
				g_menu_cursor = -1;
			}
			else if (g_menu_cursor == 2)
			{//HIGHSCORE
				g_menupos = g_menu_cursor;//2
				printf("%s\n", g_menu[g_menu_cursor]);
			}
			else if (g_menu_cursor == 4)
			{
				//g_starwarsvelocity = -10.0;
				//g_starwarsview = 20.0;
				g_menupos = g_menu_cursor;//2
				printf("%s\n", g_menu[g_menu_cursor]);
			}
			else if (g_menu_cursor == 6)
			{//EXIT
				exit(0);
			}
			return ;
		}
		/*
		else if (!g_pausemode && g_menupos > 0)//if is a remainder then is in a different menu.
		{
			g_menupos = 0;//back to main menu
			glutDisplayFunc(displaymenu);
			glutPostRedisplay();
			g_menu_cursor = 0;
		}
		else if (g_pausemode)
		{
			if (g_pausemenu_cursor == 0)
			{//MAIN MENU
				g_pausemenu_cursor = 0;
				g_menupos = 0;//back to main menu
				glutDisplayFunc(displaymenu);
				glutPostRedisplay();
				g_menu_cursor = 0;
			}
			if (g_pausemenu_cursor == 2)
			{//HIGHSCORE
				g_menupos = g_pausemenu_cursor;//2
				printf("%s\n", g_pausemenu[g_menu_cursor]);
			}
			else if (g_pausemenu_cursor == 4)
			{//EXIT
				exit(0);
			}
			//pause mode then select the current pos's value
		}
		*/
	}
	else if (key == 'm')
		g_game.mode == g_game.m_tmp;
	printf("%c\n", key);
}

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
	else if (g_game.mode == MODE_MENU)
		menu_keys(key, x, y);
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
	else if (key == 'm')
	{
		g_game.m_tmp = g_game.mode;
		g_game.mode = MODE_MENU;
		//glutDisplayFunc(displaymenu);//displaymenu();
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
