/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 08:11:01 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 10:53:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;
	int		num;
	char	*a;
	char	*b;

	k = 0;
	a = (char *)s1;
	b = (char *)s2;
	while (k < n)
	{
		if (a[k] != b[k])
		{
			num = (unsigned char)a[k] - (unsigned char)b[k];
			return (num);
		}
		k++;
	}
	return (0);
}
