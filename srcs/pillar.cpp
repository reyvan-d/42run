/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pillar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:23:51 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 07:23:53 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

t_object	generate_pillar(void)
{
	t_object	pillar;
	int			tmp;

	bzero(&pillar, sizeof(t_object));
	pillar.object_type = O_PILLAR;
	pillar.size = 1;
	if (random_range(1, 2) == 1)
	{
		pillar.colour.x = 0.1328125;
		pillar.colour.y = 0.41796875;
		pillar.colour.z = 0.70703125;
	}
	else
	{
		pillar.colour.x = 0.85;
		pillar.colour.y = 0.85;
		pillar.colour.z = 0.85;
	}
	tmp = random_range(1, 3);
	pillar.eye.ex = (tmp * 3) - 6;
	pillar.lane = (tmp == 1) ? OL_LEFT : (tmp == 2) ? OL_CENTER : OL_RIGHT;
	pillar.lane |= OL_TOP | OL_MID | OL_BOTTOM;
	pillar.eye.ez = RENDER_DIST;
	pillar.weight = 30;
	return (pillar);
}

int			draw_pillar(t_object *pillar)
{
	if (pillar->object_type != O_PILLAR)
		return (-1);
	glEnable(GL_NORMALIZE);
	glPushMatrix();
	glActiveTexture(textures[3]);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glColor3f(pillar->colour.x, pillar->colour.y, pillar->colour.z);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3f(pillar->eye.ex - 1, 0, pillar->eye.ez);
		glTexCoord2d(1, 0); glVertex3f(pillar->eye.ex + 1, 0, pillar->eye.ez);
		glTexCoord2d(1, 1); glVertex3f(pillar->eye.ex + 1, 8, pillar->eye.ez);
		glTexCoord2d(0, 1); glVertex3f(pillar->eye.ex - 1, 8, pillar->eye.ez);
	
		glTexCoord2d(0, 1); glVertex3f(pillar->eye.ex - 1, 0, pillar->eye.ez);
		glTexCoord2d(1, 1); glVertex3f(pillar->eye.ex - 1, 0, pillar->eye.ez + 10);
		glTexCoord2d(0, 0); glVertex3f(pillar->eye.ex - 1, 8, pillar->eye.ez + 10);
		glTexCoord2d(1, 0); glVertex3f(pillar->eye.ex - 1, 8, pillar->eye.ez);
	
		glTexCoord2d(0, 1); glVertex3f(pillar->eye.ex + 1, 0, pillar->eye.ez);
		glTexCoord2d(1, 1); glVertex3f(pillar->eye.ex + 1, 0, pillar->eye.ez + 10);
		glTexCoord2d(0, 0); glVertex3f(pillar->eye.ex + 1, 8, pillar->eye.ez + 10);
		glTexCoord2d(1, 0); glVertex3f(pillar->eye.ex + 1, 8, pillar->eye.ez);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_NORMALIZE);
	pillar->eye.ez -= g_game.speed;
	return ((pillar->eye.ez == 0) ? 2 : (pillar->eye.ez > 0) ? 1 : 0);
}
