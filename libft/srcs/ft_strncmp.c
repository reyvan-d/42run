/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 08:15:03 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 11:21:45 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_diff(char s1, char s2)
{
	int		l;
	int		m;

	if (s1 < 0)
		m = 256 + s1;
	else
		m = s1;
	if (s2 < 0)
		l = 256 + s2;
	else
		l = s2;
	return (m - l);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (s1[k] != '\0' && s2[k] != '\0' && k < n)
	{
		if (s1[k] != s2[k])
			return (ft_diff(s1[k], s2[k]));
		k++;
	}
	if (s1[k] != '\0' && k != n)
		return (ft_diff(s1[k], 0));
	else if (s2[k] != '\0' && k != n)
		return (ft_diff(0, s2[k]));
	return (0);
}
