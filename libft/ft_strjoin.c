/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:11:51 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 22:11:53 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s2_len = ft_strlen(s2);
	s1_len = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(str) * (s1_len + s2_len) + 1)))
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
