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

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat	light_diff2[] = {0.5, 0.5, 0.5, 0.5};
GLfloat light_position[] = {0.0, -3.0, 1.0, -1.0};
GLfloat	light_pos2[] = {0.0, -4.0, -80.0, -1.0};

void	init_normals(void)
{/*
	t_vertex	v1;
	t_vertex	v2;
	t_vertex	v3;

	v1.x = -4;
	v1.y = 0;
	v1.z = -5;
	v2.x = -4;
	v2.y = 0;
	v2.z = 200;
	v3.x = 4;
	v3.y = 0;
	v3.z = 200;
	fnormals = normalise_point(&v1, &v2, &v3);
	v1.x = -4;
	v1.y = 0;
	v1.z = -5;
	v2.x = -4;
	v2.y = 0;
	v2.z = 200;
	v3.x = -4;
	v3.y = 8;
	v3.z = 200;
	w1normals = normalise_point(&v1, &v2, &v3);
	v1.x = 4;
	v1.y = 0;
	v1.z = -5;
	v2.x = 4;
	v2.y = 0;
	v2.z = 200;
	v3.x = 4;
	v3.y = 8;
	v3.z = 200;
	w2normals = normalise_point(&v1, &v2, &v3);
	v1.x = -4;
	v1.y = 8;
	v1.z = -5;
	v2.x = -4;
	v2.y = 8;
	v2.z = 200;
	v3.x = 4;
	v3.y = 8;
	v3.z = 200;
	cnormals = normalise_point(&v1, &v2, &v3);*/
}

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
	//srand(rand());
	init_g_pos();
	glutInit(&ac, av);
	//texture = LoadTextureRAW("./textures/floor.data", TRUE);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_MULTISAMPLE | GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(WIN_X, WIN_Y);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutCreateWindow("42run");
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diff2);
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 20);
	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	textures = new GLuint[6];
//	textures = (GLuint *)malloc(sizeof(GLuint) * 6);
	glGenTextures(7, textures);
	LoadTextureRAW(textures[0], "./textures/floor.data", 1, 256, 256);
	LoadTextureRAW(textures[1], "./textures/walls.data", 1, 512, 512);
	LoadTextureRAW(textures[2], "./textures/wires.data", 1, 512, 512);
	LoadTextureRAW(textures[3], "./textures/column.data", 1, 128, 512);
	LoadTextureRAW(textures[4], "./textures/table.data", 1, 512, 128);
	LoadTextureRAW(textures[5], "./textures/apple.data", 1, 128, 128);
	LoadTextureRAW(textures[6], "./textures/ball.data", 1, 512, 512);
	init_normals();
	glutDisplayFunc(render_scene);
	glutReshapeFunc(change_size);
	glutIdleFunc(render_scene);
	glutSpecialFunc(press_key);
	//glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(release_key);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}
