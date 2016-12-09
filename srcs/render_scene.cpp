/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:26:34 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:26:36 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void LoadTextureRAW(GLuint texture, const char *filename, int wrap, int width, int height)
{
	unsigned char	*data;
    FILE			*file;

    // open texture data
    file = fopen( filename, "rb" );
    if (file == NULL)
	{
		return ;
	}

    // allocate buffer
    data = (unsigned char *)malloc(width * height * 4);

    // read texture data
    fread(data, width * height * 4, 1, file);
    fclose(file);

    // select modulate to mix texture with color for shading
//    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//                     GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
 //                    wrap ? GL_REPEAT : GL_CLAMP );
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
//                     wrap ? GL_REPEAT : GL_CLAMP );

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // build our texture mipmaps
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	// free buffer
    free(data);
}

void	draw_36_snowmen(void)
{
	int		k;
	int		l;

	k = -4;
	while (++k < 3)
	{
		l = -4;
		while (++l < 3)
		{
			glPushMatrix();
			glTranslated(k * 10, 0, l * 10);
			draw_snowman();
			glPopMatrix();
		}
	}
}

void	draw_walls(void)
{
	static float	i;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_QUADS);/*Draw the ground*/
		glColor3f(0.581176, 0.55098, 0.282353);/*Floor*/
		glTexCoord2d(0, i); glVertex3f(-4, 0, -5);
		glTexCoord2d(0, i + 1); glVertex3f(-4, 0, 200);
		glTexCoord2d(1, i + 1); glVertex3f(4, 0, 200);
		glTexCoord2d(1, i); glVertex3f(4, 0, -5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glBegin(GL_QUADS);
		glColor3f(0.5098039216, 0.3039215686, 0.3039215686);/*Walls*/
		glTexCoord2d(0, i); glVertex3f(-4, 0, -5);
		glTexCoord2d(0, i + 1); glVertex3f(-4, 0, 200);
		glTexCoord2d(1, i + 1); glVertex3f(-4, 8, 200);
		glTexCoord2d(1, i); glVertex3f(-4, 8, -5);

		glTexCoord2d(0, i); glVertex3f(4, 0, -5);
		glTexCoord2d(0, i + 1); glVertex3f(4, 0, 200);
		glTexCoord2d(1, i + 1); glVertex3f(4, 8, 200);
		glTexCoord2d(1, i); glVertex3f(4, 8, -5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_QUADS);
		glColor3f(0.3, 0.3, 0.3);/*Roof*/
		glTexCoord2d(0, i); glVertex3f(-4, 8, -5);
		glTexCoord2d(0, i + 1); glVertex3f(-4, 8, 200);
		glTexCoord2d(1, i + 1); glVertex3f(4, 8, 200);
		glTexCoord2d(1, i); glVertex3f(4, 8, -5);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	if (i == 1)
		i = 0;
	if (g_game.mode == MODE_PLAY)
		i += 0.02f;
}

/*
** Old Code:
** if (g_pos.deltaMove)
**		compute_pos(g_pos.deltaMove);
**	if (g_pos.deltaAngle)
**		compute_dir(g_pos.deltaAngle);
**
** draw_36_snowmen();
** draw_main_box(0b111);
** draw_short_straight();
*/

void	render_scene(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(
		0.0 + g_eye.ex, 1.0 + g_eye.ey, 0.0 + g_eye.ez,
		0.0 + g_eye.ex, 1.0 + g_eye.ey, 1.0 + g_eye.ez,
		0.0, 2.0, 0.0);
	if (g_eye.ey > 0 && (g_game.mode == MODE_PLAY || g_game.mode == MODE_STOP))
		g_eye.ey -= 0.1 * g_game.speed;
	draw_walls();
	if (g_game.mode == MODE_PLAY || g_game.mode == MODE_STOP)
		render_objects();
	if (g_game.mode == MODE_PLAY)
	{
		render_game_stats();
		ability_do();
		g_game.speed += 0.002;
		g_game.score += 0.1;
		g_game.time += 0.1;
	}
	else if (g_game.mode == MODE_STOP)
		render_game_over();
	else if (g_game.mode == MODE_PAUSE)
		render_game_paused();
	render_character();
	glutSwapBuffers();
}
