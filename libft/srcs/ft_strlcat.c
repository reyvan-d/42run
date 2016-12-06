/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:12:51 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 18:05:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	k;

	d = (char *)ft_memchr(dst, '\0', size);
	if (d == NULL)
		return (size + ft_strlen(src));
	s = (char *)src;
	k = (size_t)(d - dst) + ft_strlen(s);
	while (((size_t)(d - dst) < size - 1) && (*s != '\0'))
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (k);
}
