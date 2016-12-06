/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:03:01 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 12:01:42 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		k;
	char	*temp;

	k = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[k] != '\0')
		k++;
	if (!(temp = (char *)malloc(k + 1)))
		return (NULL);
	k = 0;
	while (s[k] != '\0')
	{
		temp[k] = f(s[k]);
		k++;
	}
	temp[k] = '\0';
	return (temp);
}
