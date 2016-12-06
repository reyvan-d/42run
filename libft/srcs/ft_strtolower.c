/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:38:18 by khansman          #+#    #+#             */
/*   Updated: 2016/11/13 11:43:15 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	int		k;

	k = -1;
	if (!str || !*str)
		return (NULL);
	while (str[++k])
		str[k] = ft_tolower(str[k]);
	return (str);
}
