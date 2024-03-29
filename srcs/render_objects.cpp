/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_objects.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 06:48:23 by khansman          #+#    #+#             */
/*   Updated: 2016/12/07 06:48:25 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	generate_object(t_object *object)
{
	int				k;
	static	char	p2;
	static	char	p1_pos;

	if (p2)
	{
		do {
			*object = generate_pillar();
		} while ((object->lane & p1_pos));
		g_game.render += random_range(40, 60);
		p2 = 0;
		return ;
	}
	k = random_range(1, 5);
	if (k == O_CUBE && (g_game.render += random_range(40, 70)))
		*object = generate_cube();
	else if (k == O_SPHERE)
	{
		*object = generate_pillar();
		p1_pos = object->lane & 0b00000111;
		p2 = 1;
	}
	else if (k == O_TEAPOT && (g_game.render += random_range(15, 30)))
		*object = generate_teapot();
	else if (k == O_PILLAR && (g_game.render += random_range(40, 60)))
		*object = generate_pillar();
	else if (k == O_LOG && (g_game.render += random_range(30, 60)))
		*object = generate_log();
}

void	draw_object(t_object *object)
{
	if (!object || object->object_type < 1)
		return ;
	if (object->object_type == O_CUBE)
		draw_cube(object);
	else if (object->object_type == O_SPHERE)
		return ;
	else if (object->object_type == O_TEAPOT)
		draw_teapot(object);
	else if (object->object_type == O_PILLAR)
		draw_pillar(object);
	else if (object->object_type == O_LOG)
		draw_log(object);
}

void	render_objects(void)
{
	static t_object		objects[NUM_OBJS];
	int					k = 0;

	if (g_game.mode == MODE_PLAY)
	{
		while (k < NUM_OBJS)
		{
			if (objects[k].eye.ez > 0 && objects[k].eye.ez < g_game.speed * 1.5)
			{
				calc_collision(objects[k]);
				objects[k].eye.ez = 0;
			}
			if ((objects[k].eye.ez < 2) && (g_game.render <= g_game.render_min))
				generate_object(&objects[k]);
			else if (objects[k].eye.ez < 2)
				bzero(&objects[k], sizeof(t_object));
			else
				draw_object(&objects[k]);
			k++;
		}
		g_game.render--;
	}
	else if (g_game.mode == MODE_STOP)
	{
		while (k < NUM_OBJS)
		{
			bzero(&objects[k], sizeof(t_object));	
			k++;
		}
	}
}
