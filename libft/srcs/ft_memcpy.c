/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 08:13:31 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 18:00:06 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (n == 0 || dest == src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (--n)
		*d++ = *s++;
	*d = *s;
	return (dest);
}
