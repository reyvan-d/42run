/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cube.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 07:54:35 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 07:54:38 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

t_object	generate_cube(void)
{
	t_object	cube;
	int			tmp;

	bzero(&cube, sizeof(t_object));
	cube.object_type = O_CUBE;
	cube.size = 1;
	cube.eye.ez = RENDER_DIST;
	tmp = random_range(1, 3);
	cube.eye.ex = (tmp * 3) - 6;
	cube.lane = (tmp == 1) ? OL_LEFT : (tmp == 2) ? OL_CENTER : OL_RIGHT;
	cube.lane |= OL_BOTTOM;
	cube.eye.ey = 0.75;
	cube.colour.x = 0.5;
	cube.colour.y = 0.5;
	cube.colour.z = 0.5;
	return (cube);
}

int			draw_cube(t_object *cube)
{
	if (cube->object_type != O_CUBE)
		return (-1);
	glPushMatrix();
	glColor3f(cube->colour.x, cube->colour.y, cube->colour.z);
	glTranslatef(cube->eye.ex, cube->eye.ey, cube->eye.ez);
	glutSolidCube(cube->size);
	glPopMatrix();
	cube->eye.ez -= g_game.speed;
	return ((cube->eye.ez == 0) ? 2 : (cube->eye.ez > 0) ? 1 : 0);
}
