/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:59:24 by khansman          #+#    #+#             */
/*   Updated: 2016/11/14 07:38:52 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		remalloc(char **line, int len)
{
	char			*tmp;

	tmp = *line;
	*line = ft_strnew(len + LINE_SIZE + 2);
	if (len != -1)
	{
		ft_memcpy(*line, tmp, len + 1);
		free(tmp);
	}
}

static void		get_buff(t_buff **buff, int fd)
{
	static t_buff	buffs[NUM_BUFF];
	int				k;

	k = -1;
	while (++k < NUM_BUFF)
		if (buffs[k].active && buffs[k].fd == fd)
		{
			*buff = &buffs[k];
			return ;
		}
	k = -1;
	while (++k < NUM_BUFF)
	{
		if (!buffs[k].active)
		{
			ft_bzero(&buffs[k], sizeof(t_buff));
			buffs[k].fd = fd;
			*buff = &buffs[k];
			return ;
		}
	}
	ft_bzero(&buffs[0], sizeof(t_buff));
	buffs[0].fd = fd;
	*buff = &buffs[0];
}

static int		read_line(t_buff *buff)
{
	if (!ACTIVE)
		ACTIVE = 1;
	else if (RET < BUFF_SIZE)
	{
		ACTIVE = 0;
		RET = 0;
		return (0);
	}
	else
		ft_bzero(&BUFF, BUFF_SIZE);
	RET = read(B_FD, BUFF, BUFF_SIZE);
	POS = 0;
	if (RET == -1)
	{
		ACTIVE = 0;
		return (RET);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_buff			*buff;

	if (BUFF_SIZE < 1 || line == NULL)
		return (-1);
	get_buff(&buff, fd);
	if ((!ACTIVE || (POS > RET)) && !read_line(buff))
		return (RET);
	L = -1;
	while (BUFF[POS] != '\n' && BUFF[POS] != 26)
	{
		if (POS > RET && !read_line(buff))
			return (RET);
		if (BUFF[POS] == '\n' || BUFF[POS] == 26)
			break ;
		if (((L + 1) % LINE_SIZE) == 0 || L == -1)
			remalloc(&LINE, L);
		LINE[++L] = BUFF[POS];
		POS++;
	}
	*line = (L == -1) ? ft_strnew(4) : LINE;
	POS++;
	return (1);
}
