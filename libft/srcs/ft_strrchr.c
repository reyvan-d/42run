/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 13:58:38 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 18:04:11 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;

	pos = (char *)s + ft_strlen(s);
	while (*pos != c)
	{
		if (pos == s)
			return (NULL);
		pos--;
	}
	return (pos);
}
