/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:03 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 15:36:04 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	size_t			i;

	uc1 = (unsigned char*)s1;
	uc2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && uc1[i] == uc2[i])
		i++;
	return (uc1[i] - uc2[i]);
}
