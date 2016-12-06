/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:33:51 by khansman          #+#    #+#             */
/*   Updated: 2016/08/19 13:33:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(list->content = (void *)malloc(content_size)))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
		ft_memcpy(list->content, content, content_size);
	list->content_size = (content) ? content_size : 0;
	list->next = NULL;
	return (list);
}
