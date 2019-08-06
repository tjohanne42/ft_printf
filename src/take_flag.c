/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:42:59 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/13 16:43:00 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			struct_init(t_return *flag)
{
	flag->len = 0;
	flag->type = 0;
	flag->sharp = -1;
	flag->zero = -1;
	flag->negative = -1;
	flag->positive = -1;
	flag->space = -1;
	flag->accuracy = -1;
	flag->width = -1;
	flag->h = -1;
	flag->hh = -1;
	flag->l = -1;
	flag->ll = -1;
	flag->j = -1;
	flag->z = -1;
	flag->lfloat = -1;
	flag->ptr_cs++;
}

static size_t		convert_type(const char c, t_return *flag)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
		c == 'X' || c == 'c' || c == 'C' || c == '%' || flag->type == '0' ||
		c == 'f' || c == 'F')
		return (1);
	return (0);
}

static size_t		get_use_flag(va_list *ap, t_return *flag,
					char **buff, const char *str)
{
	if (flag->type != 'd' && flag->type != 'D' && flag->type != 'i' &&
		flag->type != 'I' && flag->type != 'f' && flag->type != 'F')
	{
		flag->space = -1;
		flag->positive = -1;
	}
	if ((flag->type == 'd' || flag->type == 'D' || flag->type == 'i' ||
		flag->type == 'I' || flag->type == 'f' || flag->type == 'F') &&
		flag->positive != -1)
		flag->space = -1;
	if (flag->type != 'o' && flag->type != 'O' && flag->type != 'x' &&
		flag->type != 'X' && flag->type != 'f' && flag->type != 'F')
		flag->sharp = -1;
	if (flag->zero != -1 && flag->width != -1)
		flag->zero = flag->width;
	if (flag->negative != -1 && flag->width != -1)
		flag->negative = flag->width;
	else if (flag->negative == 0 && flag->width == -1)
		flag->negative = -1;
	if (flag->zero != -1 || flag->negative != -1)
		flag->width = -1;
	if (!parser(ap, flag, buff, str))
		return (0);
	return (1);
}

size_t				take_flag(const char *str, va_list *ap,
				t_return *flag, char **buff)
{
	int		temp;

	temp = 0;
	struct_init(flag);
	while (!convert_type(str[flag->ptr_cs], flag))
	{
		if (!take_flag_func(ap, str, flag, temp))
		{
			flag->ptr_cs -= 2;
			flag->type = '0';
		}
		flag->ptr_cs++;
	}
	if (flag->type != '0')
		flag->type = str[flag->ptr_cs];
	if ((flag->type != '0' && flag->type != 'c' && flag->type != 'C' &&
		flag->type != 's' && flag->type != 'S' && flag->type != 'p' &&
		flag->type != '%' && flag->accuracy != -1 && flag->type != 'f'
		&& flag->type != 'F') || flag->negative != -1 ||
		(flag->zero == 0 && flag->width == -1))
		flag->zero = -1;
	if (!get_use_flag(ap, flag, buff, str))
		return (0);
	return (1);
}
