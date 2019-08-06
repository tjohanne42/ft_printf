/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:58:55 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/15 00:58:56 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_list;
	t_list	*list;

	list = *alst;
	while (list)
	{
		next_list = list->next;
		ft_lstdelone(&list, del);
		list = next_list;
	}
	*alst = NULL;
}
