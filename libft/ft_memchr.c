/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:28:19 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 15:28:20 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*str;
	size_t			x;

	str = (unsigned char*)s;
	i = c;
	x = 0;
	while (x < n)
	{
		if (i == *((unsigned char*)str + x))
			return ((void*)s + x);
		x++;
	}
	return (NULL);
}
