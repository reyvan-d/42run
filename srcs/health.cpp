/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:44:18 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 11:44:20 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	collide(t_object object)
{
	if (object.object_type == O_CUBE || object.object_type == O_SPHERE)
		g_game.health -= 5;
	else if (object.object_type == O_PILLAR || object.object_type == O_LOG)
		g_game.health -= 10;
	else if (object.object_type == O_TEAPOT)
	{
		g_game.health += 0.5;
		g_game.score += 2;
	}
	else
		g_game.health -= 2.5;
	if (g_game.health > 100)
		g_game.health = 100;
	else if (g_game.health <= 0)
	{
		g_game.mode = MODE_STOP;
		g_game.health = 0;
	}
}

void	calc_collision(t_object object)
{
	char	tmp;

	tmp = (g_eye.ex < -1) ? OL_LEFT : (g_eye.ex > 1) ? OL_RIGHT : OL_CENTER;
	tmp |= (g_eye.ey < 2.4) ? OL_BOTTOM : (g_eye.ey < 6) ? OL_MID : OL_TOP;
	if ((tmp & OL_LEFT) & object.lane)
	{
		if ((tmp & 0b00111000) & object.lane)
			collide(object);
	}
	else if ((tmp & OL_RIGHT) & object.lane)
	{
		if ((tmp & 0b00111000) & object.lane)
			collide(object);
	}
	else
	{
		if ((tmp & 0b00111000) & object.lane)
			collide(object);
	}
}