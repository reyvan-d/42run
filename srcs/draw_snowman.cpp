/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_snowman.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:25:47 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:25:48 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	draw_snowman(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 1.0, 0.0);/*Draw body*/
	glutSolidSphere(0.75, 20, 20);
	glTranslatef(0.0, 1.0, 0.0);/*Draw head*/
	glutSolidSphere(0.25, 20, 20);
	glPushMatrix();/*Draw Eyes*/
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.05, 0.1, 0.18);
	glutSolidSphere(0.05, 10, 10);
	glTranslatef(-0.1, 0.0, 0.0);
	glutSolidSphere(0.05, 10, 10);
	glPopMatrix();
	glColor3f(1.0, 0.5, 0.5);
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glutSolidCone(0.08, 0.5, 10, 2);
}
 
