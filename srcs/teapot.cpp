/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teapot.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:51:23 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:51:24 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

t_object	generate_teapot(void)
{
	t_object	teapot;

	bzero(&teapot, sizeof(t_object));
	teapot.size = 1;
	teapot.object_type = O_TEAPOT;
	teapot.eye.ez = RENDER_DIST;
	teapot.eye.ex = (random_range(1, 3) * 2) - 4;
	teapot.eye.ey = 0.75;
	teapot.colour.y = 1;
	teapot.speed = 2;
	return (teapot);
}

int			draw_teapot(t_object *teapot)
{
	glPushMatrix();
	glColor3f(teapot->colour.x, teapot->colour.y, teapot->colour.z);
	glTranslatef(teapot->eye.ex, teapot->eye.ey, teapot->eye.ez);
	glutSolidTeapot(teapot->size);
	glPopMatrix();
	teapot->eye.ez -= teapot->speed;
	return ((teapot->eye.ez == 0) ? 2 : (teapot->eye.ez > 0) ? 1 : 0);
}
