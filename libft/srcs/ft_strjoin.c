/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:55:29 by khansman          #+#    #+#             */
/*   Updated: 2016/05/21 11:05:59 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		k;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	if (!(temp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	k = -1;
	while (*s1)
		temp[++k] = *(s1++);
	while (*s2)
		temp[++k] = *(s2++);
	return (temp);
}
