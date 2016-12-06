/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 09:43:21 by khansman          #+#    #+#             */
/*   Updated: 2016/05/14 14:14:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(char *big, char *little)
{
	int		k;
	int		l;

	k = 0;
	if (big[0] == '\0' && little[0] == '\0')
		return (big);
	while (big[k] != '\0')
	{
		l = 0;
		while (little[l] != '\0' && little[l] == big[k + l])
			l++;
		if (little[l] == '\0')
			return (&big[k]);
		k++;
	}
	return (NULL);
}
