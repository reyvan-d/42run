/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:24:49 by khansman          #+#    #+#             */
/*   Updated: 2016/08/13 11:17:52 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_remalloc(char *line, size_t size)
{
	char				*tmp;

	tmp = ft_strnew(size + 50);
	if (size > 0)
	{
		tmp = ft_strcpy(tmp, line);
		free(line);
	}
	return (tmp);
}
