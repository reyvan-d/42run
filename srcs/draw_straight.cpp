/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:25:53 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:25:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void 	draw_short_straight(void)
{
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(-4, 1, 0);
	glutSolidTeapot(0.4);
	glPopMatrix();
}
