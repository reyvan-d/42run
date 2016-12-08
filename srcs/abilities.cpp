/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abilities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:56:54 by khansman          #+#    #+#             */
/*   Updated: 2016/12/08 13:56:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	activate_ability(char ability)
{
	if (ability == AB_FLY)
	{
		g_game.ability = AB_FLY;
		g_game.ability_str = "fly";
		g_game.ability_time = 10;
	}
	else if (ability == AB_FAST)
	{
		g_game.ability = AB_FAST;
		g_game.ability_str = "fast";
		g_game.ability_time = 10;
	}
	else if (ability == AB_SLOW)
	{
		g_game.ability = AB_SLOW;
		g_game.ability_str = "slow";
		g_game.ability_time = 10;
	}
	else if (ability == AB_TRANS)
	{
		g_game.ability = AB_TRANS;
		g_game.ability_str = "transparent";
		g_game.ability_time = 10; 
	}
	else if (ability == AB_HEAL)
	{
		g_game.ability = AB_HEAL;
		g_game.ability_str = "heal";
		g_game.ability_time = 10; 
	}
}

void	ability_clear(void)
{
	if (g_game.ability == AB_FAST || g_game.ability == AB_SLOW)
		g_game.speed = g_game.tmp;
	g_game.ability_time = 0;
	g_game.ability = AB_NONE;
	g_game.ability_str = NULL;
	g_game.tmp = 0;
}

void	ability_do(void)
{
	if (g_game.ability_time <= 0)
	{
		if (g_game.ability != AB_NONE)
			ability_clear();
		return ;
	}
	if (g_game.ability == AB_HEAL)
	{
		if (g_game.health < 100)
			g_game.health += 1;
	}
	else if (g_game.ability == AB_FLY)
	{
		g_eye.ey = 6;
	}
	g_game.ability_time -= 0.05;
}
