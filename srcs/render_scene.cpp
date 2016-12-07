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

GLuint LoadTextureRAW(const char *filename, int wrap)
{
    GLuint texture;
    int		width, height;
	char	*data;
    FILE	*file;

    // open texture data
    file = fopen( filename, "rb" );
    if ( file == NULL )
	{
		printf("asdf");
		return (0);
	}

    // allocate buffer
    width = 256;
    height = 256;
    data = (char *)malloc( width * height * 3 );

    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );

    // allocate a texture name
    glGenTextures( 1, &texture );

    // select our current texture
    glBindTexture( GL_TEXTURE_2D, texture );

    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                     wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                     wrap ? GL_REPEAT : GL_CLAMP );

    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );

    // free buffer
    free( data );

    return texture;
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);/*Draw the ground*/
		glColor3f(0.281176, 0.25098, 0.082353);/*Floor*/
		glTexCoord2d(0.0,0.0); glVertex2d(0.0,0.0);
		glTexCoord2d(1.0,0.0); glVertex2d(1.0,0.0);
		glTexCoord2d(1.0,1.0); glVertex2d(1.0,1.0);
		glTexCoord2d(0.0,1.0); glVertex2d(0.0,1.0);
		glTexCoord2d(-4, 0); glVertex3f(-4, 0, -5);
		glTexCoord2d(-4, 0); glVertex3f(-4, 0, 100);
		glTexCoord2d(4, 0); glVertex3f(4, 0, 100);
		glTexCoord2d(4, 0); glVertex3f(4, 0, -5);
		glColor3f(0.2, 0.2, 0.2);/*Roof*/
		glVertex3f(-4, 8, -5);
		glVertex3f(-4, 8, 100);
		glVertex3f(4, 8, 100);
		glVertex3f(4, 8, -5);
		glColor3f(0.85546875, 0.2578125, 0.1796875);/*Walls*/
		glVertex3f(-4, 0, -5);
		glVertex3f(-4, 0, 100);
		glVertex3f(-4, 8, 100);
		glVertex3f(-4, 8, -5);
		glVertex3f(4, 0, -5);
		glVertex3f(4, 0, 100);
		glVertex3f(4, 8, 100);
		glVertex3f(4, 8, -5);
	glEnd();
	glPopMatrix();
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
	if (g_eye.ey > 0)
		g_eye.ey -= 0.2;
	draw_walls();
	glutSwapBuffers();
}
