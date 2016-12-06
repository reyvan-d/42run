/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 14:06:33 by khansman          #+#    #+#             */
/*   Updated: 2016/08/19 14:06:35 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_find_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		temp = f(ft_lstnew(lst->content, lst->content_size));
		if (!new)
			new = temp;
		else
			ft_find_last(new)->next = temp;
		lst = lst->next;
		temp = temp->next;
	}
	return (new);
}
