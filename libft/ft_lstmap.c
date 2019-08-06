/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 04:35:30 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/15 04:35:31 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*premier;
	t_list	*temp;
	t_list	*next_list;
	t_list	*temp_list;

	if (lst)
	{
		next_list = lst->next;
		temp = f(lst);
		if (!(temp_list = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		premier = temp_list;
		lst = next_list;
	}
	while (lst)
	{
		next_list = lst->next;
		temp = f(lst);
		if (!(temp_list->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		temp_list = temp_list->next;
		lst = next_list;
	}
	return (premier);
}
