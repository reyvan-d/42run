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
	glBegin(GL_QUADS);/*Draw the ground*/
		glColor3f(0.281176, 0.25098, 0.082353);/*Floor*/
		glVertex3f(-4, 0, -5);
		glVertex3f(-4, 0, 100);
		glVertex3f(4, 0, 100);
		glVertex3f(4, 0, -5);
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
