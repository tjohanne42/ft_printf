/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 09:04:31 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/01 09:04:32 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_intlen(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char		*ft_itoamin(void)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * 12);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_len;

	n_len = ft_intlen(n);
	i = 1;
	if (n == -2147483648)
		return (ft_itoamin());
	if (!(str = (char*)malloc(sizeof(*str) * n_len + 1)))
		return (NULL);
	str[n_len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n >= 10)
	{
		str[n_len - i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	str[n_len - i] = n + '0';
	return (str);
}
