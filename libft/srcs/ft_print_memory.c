/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 09:25:47 by khansman          #+#    #+#             */
/*   Updated: 2016/10/29 09:25:49 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_dots(unsigned char *str, int k, int l)
{
	while (++k <= l)
	{
		if (str[k] < 32 || str[k] > 126)
			ft_putchar('.');
		else
			ft_putchar(str[k]);
	}
}

static void	print_byte(unsigned char c)
{
	if (c < 16)
		ft_putchar('0');
	ft_print_hex(c);
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t			k;
	size_t			l;
	unsigned char	*str;

	k = -1;
	str = (unsigned char *)addr;
	l = (size % 16 == 0) ? size : size + (16 - (size % 16));
	while (++k < l)
	{
		if (k < size)
			print_byte(str[k]);
		else
			write(1, "  ", 2);
		if (((k + 1) % 2) == 0)
			ft_putchar(' ');
		if ((k + 1) % 16 == 0)
		{
			(k < size) ? print_dots(str, k - 16, k) \
				: print_dots(str, (size - (size % 16) - 1), size - 1);
			ft_putchar('\n');
		}
	}
}
