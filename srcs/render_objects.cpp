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

void	render_objects(void)
{
	static t_object		objects[20];

	/*if (objects[0].eye.ez < 2)
		objects[0] = generate_teapot();
	draw_teapot(&objects[0]);*/
	if (objects[1].eye.ez < 2)
		objects[1] = generate_log();
	draw_log(&objects[1]);
}
