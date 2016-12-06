/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 07:23:21 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 10:46:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	k;
	void	*ptr;
	char	*s;
	char	*d;

	k = 0;
	s = (char *)src;
	d = (char *)dst;
	while (k < n)
	{
		d[k] = s[k];
		if (s[k] == c)
		{
			ptr = (void *)&d[k + 1];
			return (ptr);
		}
		k++;
	}
	return (NULL);
}
