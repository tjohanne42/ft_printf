/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:23:50 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 13:23:50 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa_llong_min(size_t base)
{
	char	*str;

	if (!(str = ft_itoa_base(LLONG_MIN + 1, base)))
		return (0);
	str[ft_strlen(str) - 1] += 1;
	return (str);
}

static char		*itoa_tab(intmax_t nb, size_t base, int i)
{
	char	*str;

	if (!(str = ft_strnew(i + 2)))
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (i != -1 && str[i] != '-')
	{
		str[i--] = nb % base + '0';
		nb = nb / base;
	}
	return (str);
}

char			*ft_itoa_base(intmax_t nb, size_t base)
{
	int			i;
	intmax_t	cpy;

	i = 0;
	cpy = nb;
	if (base < 2 || base > 32)
		return (NULL);
	if (nb == LLONG_MIN)
		return (itoa_llong_min(base));
	if (nb < 0)
	{
		cpy = cpy * -1;
		i++;
	}
	while (cpy >= (intmax_t)base)
	{
		cpy = cpy / (intmax_t)base;
		i++;
	}
	return (itoa_tab(nb, base, i));
}
