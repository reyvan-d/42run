/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_box.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:25:42 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:25:43 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	draw_main_box(char config)
{
	if (!config & 0b111)
		config = 0b111;
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslated(-4, 2, 0);
	(config & 0b100) ? glutWireCube(4) : glutSolidCube(4);
	glTranslated(0, 0, -4);
	glutSolidCube(4);
	glTranslated(4, 0, 0);
	(config & 0b010) ? glutWireCube(4) : glutSolidCube(4);
	glTranslated(4, 0, 0);
	glutSolidCube(4);
	glTranslated(0, 0, 4);
	(config & 0b001) ? glutWireCube(4) : glutSolidCube(4);
	glTranslated(0, 0, 4);
	glutSolidCube(4);
	glTranslated(-8, 0, 0);
	glutSolidCube(4);
	glPopMatrix();
}
