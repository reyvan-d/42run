/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teapot.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:51:23 by khansman          #+#    #+#             */
/*   Updated: 2016/12/06 17:51:24 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

#include <iostream>
#include <random>

t_object	generate_teapot(void)
{
	t_object	teapot;

	bzero(&teapot, sizeof(t_object));
	teapot.size = 2;
	teapot.object_type = O_TEAPOT;
	teapot.eye.ex = 50;
	teapot.eye.ez = (rand() * 2) - 2;
}
