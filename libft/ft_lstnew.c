/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:13:05 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/05 06:13:06 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (NULL);
	else if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (void*)malloc(sizeof(content) * content_size)))
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
