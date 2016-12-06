/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:50:43 by khansman          #+#    #+#             */
/*   Updated: 2016/08/19 13:50:47 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*temp;

	list = *alst;
	temp = list;
	while (temp != NULL)
	{
		temp = list->next;
		del((void *)list->content, (size_t)list->content_size);
		free(list);
		list = temp;
	}
	*alst = NULL;
}
