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
	if (g_game.ability != AB_TRANS)
		g_game.health -= object.weight;
	g_game.score -= object.weight / 10;
	if (object.object_type == O_TEAPOT)
		g_game.score -= (g_game.health > 99.0f) ? 20 * object.weight : 4 * object.weight;

	if (object.lane & OL_SPEC)
		activate_ability((char)random_range(1, 3));

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
	tmp |= (g_eye.ey < 2) ? OL_BOTTOM : (g_eye.ey < 6) ? OL_MID : OL_TOP;
	if (((tmp & OL_LEFT) && (object.lane & OL_LEFT)) ||
			((tmp & OL_RIGHT) & (object.lane & OL_RIGHT)) ||
			((tmp & OL_CENTER) & (object.lane & OL_CENTER)))
	{
		if (((tmp & OL_BOTTOM) && (object.lane & OL_BOTTOM)) ||
				((tmp & OL_MID) && (object.lane & OL_MID)) ||
				((tmp & OL_TOP) && (object.lane & OL_TOP)))
			collide(object);
	}
}