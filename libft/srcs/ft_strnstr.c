/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:43:21 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 17:29:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	if (*s2 == '\0')
		return ((char *)s1);
	k = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= k)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, k) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
