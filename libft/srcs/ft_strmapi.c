/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:08:36 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 12:03:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				k;
	char			*temp;

	k = -1;
	if (s == NULL)
		return (NULL);
	if (!(temp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++k] != '\0')
		temp[k] = f(k, s[k]);
	temp[k] = '\0';
	return (temp);
}
