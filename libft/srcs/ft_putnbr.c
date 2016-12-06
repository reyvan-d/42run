/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:22:24 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 18:02:52 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_int_len(int n)
{
	int		k;

	if (n < 0)
		n = -n;
	k = 0;
	while (n > 0)
	{
		k++;
		n = n / 10;
	}
	return (k);
}

void		ft_putnbr(int n)
{
	char	c;
	int		k;
	int		l;

	if (n == 0)
		write(1, "0", 1);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	k = 1;
	l = ft_int_len(n);
	while (n % k != n)
		k = 10 * k;
	while (l > 0)
	{
		c = (n / (k / 10)) + '0';
		n = n - ((n / (k / 10) * (k / 10)));
		k = k / 10;
		l--;
		write(1, &c, 1);
	}
}
