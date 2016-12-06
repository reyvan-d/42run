/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:25:38 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:25:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	compute_pos(float delta_move)
{
	g_pos.x += delta_move * g_pos.lx * 0.1f;
	g_pos.z += delta_move * g_pos.lz * 0.1f;
}

void	compute_dir(float delta_angle)
{
	g_pos.angle += delta_angle;
	g_pos.lx = sin(g_pos.angle);
	g_pos.lz = -cos(g_pos.angle);
}
