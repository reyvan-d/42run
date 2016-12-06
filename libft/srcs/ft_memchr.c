/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 07:51:42 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 16:19:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	k;

	str = (char *)s;
	k = -1;
	while (++k < n)
		if ((unsigned char)str[k] == (unsigned char)c)
			return (&str[k]);
	return (NULL);
}
