/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:58:27 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 14:58:27 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	if (little[0] == '\0')
		return (&*(char*)big);
	while (i < len && big[i] != '\0')
	{
		while (big[i + y] == little[y] && (i + y) < len)
		{
			if (little[y + 1] == '\0')
				return (&*((char*)big + i));
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
