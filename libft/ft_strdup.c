/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:02:50 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 16:02:51 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = (char *)malloc((sizeof(*str) * i) + 1)))
		return (NULL);
	str[i] = '\0';
	while (i > 0)
	{
		str[i - 1] = s[i - 1];
		i--;
	}
	return (str);
}
