/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 09:31:27 by khansman          #+#    #+#             */
/*   Updated: 2016/12/08 09:31:29 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	render_snowball(void)
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(g_eye.ex, g_eye.ey + 0.5, 2);
	glutSolidSphere(0.25, 30, 10);
	glPopMatrix();
}

void	render_character(void)
{
	render_snowball();
}
