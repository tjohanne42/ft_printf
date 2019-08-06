/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:47:15 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 19:47:16 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = (void*)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		*((char*)str + i) = '\0';
		i++;
	}
	return (str);
}
