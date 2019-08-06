/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:31:22 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 18:31:23 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static	size_t		float_flag_zero(char **str, t_return *flag,
					char *temp, int temp2)
{
	if (flag->sharp != -1 && !ft_strchr(str[0], '.'))
	{
		temp = ft_strjoin(str[0], ".");
		free(str[0]);
		if (!(str[0] = ft_strnew(flag->len + 2)))
			return (0);
		ft_strncpy(str[0], temp, flag->len + 1);
		free(temp);
		flag->len++;
	}
	if (flag->zero != -1 && (size_t)flag->zero > flag->len)
	{
		temp2 = -1;
		if (str[0][0] == '-' || str[0][0] == '+' || str[0][0] == ' ')
		{
			temp2 = str[0][0];
			str[0][0] = '0';
		}
		if (!flag_zero(str, flag))
			return (0);
		if (temp2 != -1)
			str[0][0] = temp2;
	}
	return (1);
}

static size_t		float_flag_positive(char **str, t_return *flag,
					char *temp, long double nb)
{
	if (flag->positive != -1 && nb >= 0.0)
	{
		temp = ft_strjoin("+", str[0]);
		free(str[0]);
		if (!(str[0] = ft_strnew(flag->len + 2)))
			return (0);
		ft_strncpy(str[0], temp, flag->len + 1);
		free(temp);
		flag->len++;
	}
	if (flag->space != -1 && (nb >= 0.0 || str[0][0] == '\0'))
	{
		temp = ft_strjoin(" ", str[0]);
		free(str[0]);
		if (!(str[0] = ft_strnew(flag->len + 2)))
			return (0);
		ft_strncpy(str[0], temp, flag->len + 1);
		free(temp);
		flag->len++;
	}
	return (1);
}

size_t				convert_float(va_list *ap, t_return *flag, char **buff)
{
	long double		nb;
	char			*str;
	char			*temp;

	temp = NULL;
	if (flag->lfloat != -1)
		nb = (double long)va_arg(*ap, double long);
	else
		nb = (double)va_arg(*ap, double);
	if (flag->accuracy == -1)
		flag->accuracy = 6;
	if (!(str = ft_ftoa(nb, flag->accuracy)))
		return (0);
	flag->len = ft_strlen(str);
	if (!float_flag_positive(&str, flag, temp, nb) ||
		!float_flag_zero(&str, flag, temp, 1)
		|| !flag_width(&str, flag) || !flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
