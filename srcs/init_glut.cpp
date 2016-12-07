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

void	init_g_pos(void)
{
	bzero(&g_pos, sizeof(t_pos));
	bzero(&g_eye, sizeof(t_eye));
	bzero(&g_game, sizeof(t_game));
	g_pos.z = 5.0;
	g_game.speed = 2;
	g_game.mode = MODE_PLAY;
	//g_game.render_min = 5;
}

void	init_glut(int ac, char **av)
{
	init_g_pos();
	glutInit(&ac, av);
	//texture = LoadTextureRAW("./textures/floor.data", TRUE);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(720, 720);
	glutCreateWindow("42run");
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	glutSpecialFunc(press_key);
	//glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(release_key);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
