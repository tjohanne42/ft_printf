/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:03:22 by tjohanne          #+#    #+#             */
/*   Updated: 2018/11/30 17:03:23 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static	size_t		decimal_flag_zero(char **str, t_return *flag)
{
	int		temp;

	if (flag->zero != -1 && (size_t)flag->zero > flag->len)
	{
		temp = -1;
		if (str[0][0] == '-' || str[0][0] == '+' || str[0][0] == ' ')
		{
			temp = str[0][0];
			str[0][0] = '0';
		}
		if (!flag_zero(str, flag))
			return (0);
		if (temp != -1)
			str[0][0] = temp;
	}
	return (1);
}

static size_t		decimal_flag_accuracy(char **str, t_return *flag,
					size_t z)
{
	size_t		i;
	char		*temp;
	char		*temp2;

	i = 0;
	if (!(temp = ft_strnew(flag->accuracy - z + 1)))
		return (0);
	if (str[0][0] == '-' || str[0][0] == '+' || str[0][0] == ' ')
	{
		temp[0] = str[0][0];
		str[0][0] = '0';
		i++;
	}
	while (i < flag->accuracy - z)
		temp[i++] = '0';
	if (!(temp2 = ft_strjoin(temp, *str)))
		return (0);
	flag->len += flag->accuracy - z;
	free(*str);
	if (!(*str = ft_strnew(flag->len + 1)))
		return (0);
	ft_strncpy(*str, temp2, flag->len);
	free(temp2);
	free(temp);
	return (1);
}

size_t				decimal_flag_two(char **str, t_return *flag,
					intmax_t nb, char **buff)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = flag->len;
	flag->len = ft_strlen(str[0]);
	if (nb == 0 && flag->accuracy == 0)
	{
		while (str[0][i] < '0' || str[0][i] > '9')
			i++;
		str[0][i] = '\0';
		flag->len = i;
	}
	else if (flag->accuracy != -1 && (size_t)flag->accuracy > z)
	{
		if (!decimal_flag_accuracy(str, flag, z))
			return (0);
	}
	if (!decimal_flag_zero(str, flag) || !flag_width(str, flag) ||
		!flag_negative(str, flag))
		return (0);
	insert_str(str[0], buff, flag, flag->len);
	free(*str);
	return (1);
}
