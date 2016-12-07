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
	int			tmp;

	bzero(&teapot, sizeof(t_object));
	teapot.size = 1;
	teapot.object_type = O_TEAPOT;
	teapot.eye.ez = RENDER_DIST;
	tmp = random_range(1, 3);
	teapot.eye.ex = (tmp * 2) - 4;
	teapot.lane = (tmp == 1) ? OL_LEFT : (tmp == 2) ? OL_CENTER : OL_RIGHT;
	teapot.lane |= OL_BOTTOM;
	teapot.eye.ey = 0.75;
	teapot.colour.y = 1;
	return (teapot);
}

int			draw_teapot(t_object *teapot)
{
	if (teapot->object_type != O_TEAPOT)
		return (-1);
	glPushMatrix();
	glColor3f(teapot->colour.x, teapot->colour.y, teapot->colour.z);
	glTranslatef(teapot->eye.ex, teapot->eye.ey, teapot->eye.ez);
	glutSolidTeapot(teapot->size);
	glPopMatrix();
	teapot->eye.ez -= g_game.speed;
	return ((teapot->eye.ez == 0) ? 2 : (teapot->eye.ez > 0) ? 1 : 0);
}
