/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:52:36 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 18:52:37 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (aiguille[0] == '\0')
		return (&*(char*)meule_de_foin);
	while (meule_de_foin[i] != '\0')
	{
		while (meule_de_foin[i + y] == aiguille[y] && aiguille != '\0')
		{
			if (aiguille[y + 1] == '\0')
				return (&*((char*)meule_de_foin + i));
			y++;
		}
		y = 0;
		i++;
	}
	return (NULL);
}
