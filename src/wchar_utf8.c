/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 01:26:04 by tjohanne          #+#    #+#             */
/*   Updated: 2018/09/24 01:26:05 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static intmax_t	ft_binary_to_decimal(size_t *tab)
{
	size_t	z;
	int		i;

	i = 0;
	z = 0;
	while (z < 8)
	{
		if (tab[z] == 1)
			i += ft_power(2, (intmax_t)(7 - z));
		z++;
	}
	return (i);
}

static char		*ft_utf8_norme(size_t *tab, size_t nb_octets,
				size_t y, size_t z)
{
	size_t	bin[4][8];
	size_t	x;
	char	*str;

	if (!(str = ft_strnew(5)))
		return (NULL);
	while (y < nb_octets)
	{
		x = 0;
		while (y == 0 && x < nb_octets)
			bin[y][x++] = 1;
		if (x == 0)
			bin[y][x++] = 1;
		bin[y][x++] = 0;
		while (x != 8)
			bin[y][x++] = tab[z++];
		y++;
	}
	x = 0;
	while (x < nb_octets)
	{
		str[x] = (char)ft_binary_to_decimal(bin[x]);
		x++;
	}
	return (str);
}

static char		*ft_utf8_decimal_to_binary(intmax_t i, size_t nb_bytes)
{
	intmax_t	power;
	size_t		*tab;
	char		*ret;

	if (!(tab = malloc(sizeof(*tab) * nb_bytes)))
		exit(0);
	power = nb_bytes - 1;
	while (power >= 0)
	{
		if (i >= ft_power(2, power))
		{
			i -= ft_power(2, power);
			tab[nb_bytes - (power--) - 1] = 1;
		}
		else
			tab[nb_bytes - (power--) - 1] = 0;
	}
	ret = ft_utf8_norme(tab, nb_bytes / 5, 0, 0);
	free(tab);
	return (ret);
}

char			*wchar_utf8(intmax_t i)
{
	char	*ret;

	if (i <= 0x7F)
	{
		if (!(ret = ft_strnew(2)))
			return (NULL);
		ret[0] = i;
		return (ret);
	}
	else if (i <= 0x7FF)
		return (ft_utf8_decimal_to_binary(i, 11));
	else if (i <= 0xFFFF)
		return (ft_utf8_decimal_to_binary(i, 16));
	else if (i <= 0x10FFFF)
		return (ft_utf8_decimal_to_binary(i, 21));
	else
		return (NULL);
}
