/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 09:18:57 by khansman          #+#    #+#             */
/*   Updated: 2016/08/13 09:19:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = -1;
	while (src[++k] && k < len)
		dst[k] = src[k];
	while (k < len)
		dst[k++] = '\0';
	return (dst);
}
