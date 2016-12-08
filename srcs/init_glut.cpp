/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_glut.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:26:00 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:26:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {0.0, 5.0, 5.0, 7.0};  /* Infinite light location. */

void	init_g_pos(void)
{
	bzero(&g_pos, sizeof(t_pos));
	bzero(&g_eye, sizeof(t_eye));
	bzero(&g_game, sizeof(t_game));
	bzero(&g_win, sizeof(t_win));
	g_pos.z = 5.0;
	g_game.speed = 2;
	g_game.mode = MODE_PLAY;
	g_game.health = 100;
	//g_game.ability = "none";
	//g_game.render_min = 5;
	g_win.width = WIN_WIDTH;
	g_win.height = WIN_HEIGHT;
	g_eye.ey = 6;
}

void	init_glut(int ac, char **av)
{
	init_g_pos();
	glutInit(&ac, av);
	//texture = LoadTextureRAW("./textures/floor.data", TRUE);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(WIN_X, WIN_Y);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("42run");
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	glutSpecialFunc(press_key);
	//glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(release_key);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
