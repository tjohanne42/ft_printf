/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:07:33 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 18:07:33 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(const char *s1, const char *s2, int s1_len, int s2_len)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(str) * (s1_len + s2_len + 1))))
		return (NULL);
	str[s1_len + s2_len] = '\0';
	while (s1_len >= 0)
	{
		while (s2_len > 0)
		{
			str[s2_len + s1_len - 1] = s2[s2_len - 1];
			s2_len--;
		}
		if (s1_len > 0)
			str[s1_len - 1] = s1[s1_len - 1];
		s1_len--;
	}
	return (str);
}
