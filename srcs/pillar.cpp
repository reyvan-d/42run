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

	ft_bzero(&pillar, sizeof(t_object));
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
	pillar.speed = 2;
	pillar.eye.ex = (random_range(1, 3) * 2) - 6;
	pillar.eye.ez = RENDER_DIST;	
	return (pillar);
}

int			draw_pillar(t_object *pillar)
{
	glPushMatrix();
	glColor3f(pillar->colour.x, pillar->colour.y, pillar->colour.z);
	glTranslatef(pillar->eye.ex, pillar->eye.ey, pillar->eye.ez);
	glBegin(GL_QUADS);
		glVertex3f(pillar->eye.ex, 0, pillar->eye.ez);
		glVertex3f(pillar->eye.ex + 2, 0, pillar->eye.ez);
		glVertex3f(pillar->eye.ex + 2, 8, pillar->eye.ez);
		glVertex3f(pillar->eye.ex, 8, pillar->eye.ez);
		glVertex3f(pillar->eye.ex, 0, pillar->eye.ez);
		glVertex3f(pillar->eye.ex, 0, pillar->eye.ez + 10);
		glVertex3f(pillar->eye.ex, 8, pillar->eye.ez + 10);
		glVertex3f(pillar->eye.ex, 8, pillar->eye.ez);
		glVertex3f(pillar->eye.ex + 2, 0, pillar->eye.ez);
		glVertex3f(pillar->eye.ex + 2, 0, pillar->eye.ez + 10);
		glVertex3f(pillar->eye.ex + 2, 8, pillar->eye.ez + 10);
		glVertex3f(pillar->eye.ex + 2, 8, pillar->eye.ez);
	glEnd();
	glPopMatrix();
	pillar->eye.ez -= pillar->speed;
	return ((pillar->eye.ez == 0) ? 2 : (pillar->eye.ez > 0) ? 1 : 0);
}
