/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_size.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:25:32 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:25:33 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	change_size(int width, int height)
{
	float		ratio;

	if (height == 0)
		height = 1;
	ratio = (width * 1.0) / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(45.0, ratio, 1.0, 110.0);
	glMatrixMode(GL_MODELVIEW);
	g_win.height = height;
	g_win.width = width;
}
