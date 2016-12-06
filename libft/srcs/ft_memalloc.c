/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:10:18 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 10:45:15 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if ((temp = (void *)malloc(size)) == NULL)
		return (NULL);
	ft_bzero(temp, size);
	return (temp);
}
