/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_log.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 08:26:07 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 08:26:08 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

t_object	generate_log(void)
{
	t_object	log;

	bzero(&log, sizeof(t_object));
	log.object_type = O_LOG;
	log.size = 1;
	log.eye.ey = 1.25;
	log.eye.ez = RENDER_DIST;
	log.colour.x = 0.9140625;
	log.colour.y = 0.49609375;
	log.colour.z = 0.19921875;
	log.lane = OL_LEFT | OL_CENTER | OL_RIGHT;
	return (log);
}

int			draw_log(t_object *log)
{
	if (log->object_type != O_LOG)
		return (-1);
	glPushMatrix();
	glColor3f(log->colour.x, log->colour.y, log->colour.z);
	glBegin(GL_QUADS);
		glVertex3f(-4, 0, log->eye.ez);
		glVertex3f(-4, log->eye.ey, log->eye.ez);
		glVertex3f(4, log->eye.ey, log->eye.ez);
		glVertex3f(4, 0, log->eye.ez);
		glVertex3f(-4, log->eye.ey, log->eye.ez);
		glVertex3f(-4, log->eye.ey, log->eye.ez + 3);
		glVertex3f(4, log->eye.ey, log->eye.ez + 3);
		glVertex3f(4, log->eye.ey, log->eye.ez);
	glEnd();
	glPopMatrix();
	log->eye.ez -= g_game.speed;
	return ((log->eye.ez == 0) ? 2 : (log->eye.ez > 0) ? 1 : 0);
}
