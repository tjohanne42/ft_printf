/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:44:03 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 14:44:04 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (*((char*)src + i) != (char)c && i < n)
	{
		*((char*)dest + i) = *((char*)src + i);
		i++;
	}
	if (i != n)
	{
		*((char*)dest + i) = *((char*)src + i);
		return ((void*)dest + i + 1);
	}
	return (NULL);
}
