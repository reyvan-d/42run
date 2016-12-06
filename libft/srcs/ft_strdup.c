/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 13:15:10 by khansman          #+#    #+#             */
/*   Updated: 2016/08/13 09:16:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	k;
	char	*copy;

	k = 0;
	while (s1[k] != '\0')
		k++;
	if (!(copy = malloc(k + 1)))
		return (NULL);
	while (k > 0)
	{
		copy[k] = s1[k];
		k--;
	}
	*copy = *s1;
	return (copy);
}
