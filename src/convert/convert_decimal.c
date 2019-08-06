/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:19:31 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 13:19:31 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static intmax_t		get_nb(va_list *ap, t_return *flag)
{
	intmax_t	nb;

	if (flag->j != -1)
		nb = va_arg(*ap, intmax_t);
	else if (flag->z != -1)
		nb = va_arg(*ap, size_t);
	else if ((flag->type >= 'A' && flag->type <= 'Z') || flag->ll != -1)
		nb = va_arg(*ap, long long);
	else if (flag->l != -1)
		nb = va_arg(*ap, long);
	else if (flag->h != -1)
		nb = (short)va_arg(*ap, int);
	else if (flag->hh != -1)
		nb = (char)va_arg(*ap, int);
	else
		nb = va_arg(*ap, int);
	return (nb);
}

static size_t		convert_decimal_pos_space(intmax_t nb,
					t_return *flag, char **str)
{
	char		*temp;

	if (flag->positive != -1 && nb >= 0)
	{
		temp = ft_strjoin("+", *str);
		free(*str);
		if (!(*str = ft_strnew(flag->len + 2)))
			return (0);
		ft_strncpy(*str, temp, flag->len + 1);
		free(temp);
		flag->len++;
	}
	if (flag->space != -1 && (nb >= 0 || str[0] == '\0'))
	{
		temp = ft_strjoin(" ", *str);
		free(*str);
		if (!(*str = ft_strnew(flag->len + 2)))
			return (0);
		ft_strncpy(*str, temp, flag->len + 1);
		free(temp);
		flag->len++;
	}
	return (1);
}

size_t				convert_decimal(va_list *ap, t_return *flag, char **buff)
{
	char		*str;
	intmax_t	nb;
	size_t		z;

	nb = get_nb(ap, flag);
	if (!(str = ft_itoa_base(nb, 10)))
		return (0);
	flag->len = ft_strlen(str);
	z = flag->len;
	if (nb < 0)
		z--;
	if (!convert_decimal_pos_space(nb, flag, &str))
		return (0);
	flag->len = z;
	if (!(decimal_flag_two(&str, flag, nb, buff)))
		return (0);
	return (1);
}
