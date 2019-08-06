/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:46:22 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 21:46:22 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		i++;
	s2 = (char*)malloc(sizeof(*s2) * i + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
