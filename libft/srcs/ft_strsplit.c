/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:57:41 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 15:58:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tab_count(const char *str, char c)
{
	int		k;

	k = 1;
	while (str)
	{
		str = ft_strchr(str, c);
		while (str && *str == c)
			++str;
		if (!str || !*str)
			return (k);
		k++;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		k;
	char	*tmp;
	char	**result;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!*s)
		return ((char **)ft_strnew(sizeof(char *)));
	k = ft_tab_count(s, c) + 1;
	if (!(arr = (char **)ft_strnew((k) * sizeof(char *))))
		return (NULL);
	result = arr;
	while (--k)
	{
		tmp = ft_strchr(s, c);
		if (!tmp && (*(arr++) = ft_strdup(s)))
			break ;
		*(arr++) = ft_strsub(s, 0, tmp - s);
		SKP_BLK;
		s = tmp;
	}
	return (result);
}
