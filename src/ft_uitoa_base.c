/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:40:55 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 13:40:56 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_uitoa_base(uintmax_t nb, size_t base)
{
	int				i;
	char			*str;
	uintmax_t		cpy;

	i = 0;
	cpy = nb;
	while (cpy >= (uintmax_t)base)
	{
		cpy = cpy / (uintmax_t)base;
		i++;
	}
	if (!(str = ft_strnew(i + 2)))
		return (NULL);
	while (i != -1)
	{
		if (nb % (uintmax_t)base < 10)
			str[i] = nb % (uintmax_t)base + '0';
		else
			str[i] = nb % (uintmax_t)base % 10 + 'a';
		nb = nb / base;
		i--;
	}
	return (str);
}
