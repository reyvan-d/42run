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
	cube.eye.ex = (tmp * 1.5) - 3;
	cube.lane = (tmp == 1) ? OL_LEFT : (tmp == 2) ? OL_CENTER : OL_RIGHT;
	cube.lane |= OL_BOTTOM;
	cube.colour.x = 1;
	cube.colour.y = 1;
	cube.colour.z = 1;
	cube.weight = 15;
	return (cube);
}

int			draw_cube(t_object *cube)
{
	if (cube->object_type != O_CUBE)
		return (-1);
	glPushMatrix();
	glColor3f(cube->colour.x, cube->colour.y, cube->colour.z);
	glTranslatef(cube->eye.ex, cube->eye.ey, cube->eye.ez);
	texture = LoadTextureRAW("./textures/apple.data", 0, 256, 256);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3f((cube->eye.ex - 0.5), 0, (cube->eye.ez));
		glTexCoord2d(0, 1); glVertex3f((cube->eye.ex - 0.5), 1, (cube->eye.ez));
		glTexCoord2d(1, 1); glVertex3f((cube->eye.ex + 0.5), 1, (cube->eye.ez));
		glTexCoord2d(1, 0); glVertex3f((cube->eye.ex + 0.5), 0, (cube->eye.ez));

		glTexCoord2d(0, 0); glVertex3f((cube->eye.ex - 0.5), 0, (cube->eye.ez));
		glTexCoord2d(0, 1); glVertex3f((cube->eye.ex - 0.5), 1, (cube->eye.ez));
		glTexCoord2d(1, 1); glVertex3f((cube->eye.ex - 0.5), 1, (cube->eye.ez + 1));
		glTexCoord2d(1, 0); glVertex3f((cube->eye.ex - 0.5), 0, (cube->eye.ez + 1));
		
		glTexCoord2d(0, 0); glVertex3f((cube->eye.ex + 0.5), 0, (cube->eye.ez));
		glTexCoord2d(0, 1); glVertex3f((cube->eye.ex + 0.5), 1, (cube->eye.ez));
		glTexCoord2d(1, 1); glVertex3f((cube->eye.ex + 0.5), 1, (cube->eye.ez + 1));
		glTexCoord2d(1, 0); glVertex3f((cube->eye.ex + 0.5), 0, (cube->eye.ez + 1));
		
		glTexCoord2d(0, 0); glVertex3f((cube->eye.ex - 0.5), 1, (cube->eye.ez));
		glTexCoord2d(0, 1); glVertex3f((cube->eye.ex - 0.5), 1, (cube->eye.ez + 1));
		glTexCoord2d(1, 1); glVertex3f((cube->eye.ex + 0.5), 1, (cube->eye.ez + 1));
		glTexCoord2d(1, 0); glVertex3f((cube->eye.ex + 0.5), 1, (cube->eye.ez));
	glEnd();
	glDeleteTextures(1, &texture);
	glDisable(GL_TEXTURE_2D);
	//glutSolidCube(cube->size);
	glPopMatrix();
	cube->eye.ez -= g_game.speed;
	return ((cube->eye.ez == 0) ? 2 : (cube->eye.ez > 0) ? 1 : 0);
}
