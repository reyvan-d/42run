/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:07:42 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 17:47:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_start(char *s)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	while (s[k] == '\t' || s[k] == '\n' || s[k] == ' ')
		k++;
	while (s[k] != '\0')
	{
		s[l] = s[k];
		k++;
		l++;
	}
	s[l] = '\0';
	return (s);
}

static char	*ft_str_rev(char *s)
{
	int		k;
	int		l;
	char	temp;

	k = 0;
	l = -1;
	while (s[l + 1] != '\0')
		l++;
	while (l > k)
	{
		temp = s[k];
		s[k] = s[l];
		s[l] = temp;
		l--;
		k++;
	}
	return (s);
}

char		*ft_strtrim(char const *s)
{
	char	*temp;
	int		k;

	if (!s)
		return (NULL);
	k = 0;
	if (!(temp = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[k] != '\0')
	{
		temp[k] = s[k];
		k++;
	}
	temp[k] = '\0';
	temp = ft_strtrim_start(temp);
	temp = ft_strtrim_start(ft_str_rev(temp));
	temp = ft_str_rev(temp);
	return (temp);
}
