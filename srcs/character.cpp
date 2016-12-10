/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 09:31:27 by khansman          #+#    #+#             */
/*   Updated: 2016/12/08 09:31:29 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	render_snowball(void)
{
	static float		k;
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(g_eye.ex, g_eye.ey + 0.5, 2);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);//
	glRotatef(k, 1.0f, 0.0f, 0.0f);
	GLUquadric *sphere = gluNewQuadric(); 
	gluQuadricTexture(sphere, GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, textures[6]);
	gluSphere(sphere, 0.25, 50, 50);
	gluDeleteQuadric(sphere);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	if (g_game.mode == MODE_PLAY)
		k += 30;
	if (k > 360)
		k = 0;
}

void	render_character(void)
{
	render_snowball();
}
