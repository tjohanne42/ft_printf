/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:15:47 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/15 02:15:48 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next_list;
	t_list	*list;

	list = lst;
	while (list)
	{
		next_list = list->next;
		f(list);
		list = next_list;
	}
}
