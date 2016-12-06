/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:54:48 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 11:16:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				k;

	k = -1;
	if (s == NULL || f == NULL)
		return ;
	while (s[++k])
		f(k, (char *)&s[k]);
}
