/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:18:25 by khansman          #+#    #+#             */
/*   Updated: 2016/12/10 15:18:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	displaymenu(void)
{
	float	font_size = 200.0;
	int	l;
	int	len;
	int	i;

//	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(0.0, 0.0, font_size, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//fontsize !upsidedown
//	if (g_menu_cursor > -1)//will be continue clause
//	{
		glTranslatef(0.0, 30.0, 0.0);// height up
		//  glRotatef(-200.0, 0.0, 0.0, 0.0);
		glScalef(0.1, 0.1, 0.1);//scalesize on x y z
		for(l=0;l < g_nomenuitems;l++)//prints out all quotes
		{
			len = (int)strlen(g_menu[l]);
			glPushMatrix();
			glTranslatef(-(len * 37), -(l * 200), 0.0);
			for (i = 0; i < len; i++)//loops through each char in the quote
			{
				glColor3f(0.0, 255.0 * (l != g_menu_cursor), 255.0);//rgb
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, g_menu[l][i]);//style
			}
			glPopMatrix();
		}
	//glutSwapBuffers();
	glPopMatrix();
}
