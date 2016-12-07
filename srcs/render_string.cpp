/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_string.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:05:37 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 10:05:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		const char *string) {

  const char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void	render_string(t_coord pos, void *font, const char *str)
{
	//renderBitmapString(pos.x, pos.y, pos.z, font, str);
	if (!str)
		return ;
	const char	*s = str;
	glRasterPos3f(pos.x, pos.y, pos.z);
	while (*s)
	{
		glutBitmapCharacter(font, *s);
		s++;
	}
}

void	render_game_stats(void)
{
	char		tmp[50];

	set_orthographic_projection();

	(void)tmp;
	glPushMatrix();
	glLoadIdentity();
	glColor3f(1, 1, 1);
	sprintf(tmp, "Score: %.2f", g_game.score);
	renderBitmapString(5, 30, 0, GLUT_BITMAP_HELVETICA_18, tmp);
	bzero(tmp, 50);
	sprintf(tmp, "Health: %.2f%%", g_game.health);
	renderBitmapString(5, 50, 0, GLUT_BITMAP_HELVETICA_18, tmp);
	glPopMatrix();

	restore_perspective_projection();

}
