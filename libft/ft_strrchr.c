/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:44:46 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 18:44:47 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*((char*)s + i) != '\0')
		i++;
	while (i >= 0)
	{
		if (*((char*)s + i) == (char)c)
			return (&*((char*)s + i));
		i--;
	}
	return (NULL);
}
