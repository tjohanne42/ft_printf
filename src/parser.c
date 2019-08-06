/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:07:01 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 13:07:01 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	parser_two(va_list *ap, t_return *flag, char **buff,
			const char *str)
{
	if (flag->type == 'S' || (flag->type == 's' && flag->l != -1))
		convert_wstring(ap, flag, buff);
	else if (flag->type == 'C' || (flag->type == 'c' && flag->l != -1))
		convert_wchar(ap, flag, buff);
	else if (flag->type == 'c' && flag->l == -1)
		convert_char(ap, flag, buff);
	else if (flag->type == 'p')
		convert_pointer(ap, flag, buff);
	else if (flag->type == '%')
		convert_pourcent(flag, buff);
	else if (flag->type == '0')
		convert_unvalid(flag, buff, str);
	else if (flag->type == 'f' || flag->type == 'F')
		convert_float(ap, flag, buff);
}

size_t		parser(va_list *ap, t_return *flag, char **buff, const char *str)
{
	if (flag->type == 'd' || flag->type == 'D' ||
		flag->type == 'i' || flag->type == 'I')
		convert_decimal(ap, flag, buff);
	else if (flag->type == 'x' || flag->type == 'X')
		convert_hexadecimal(ap, flag, buff);
	else if (flag->type == 'o' || flag->type == 'O')
		convert_octal(ap, flag, buff);
	else if (flag->type == 'u' || flag->type == 'U')
		convert_unsigned(ap, flag, buff);
	else if (flag->type == 's' && flag->l == -1)
		convert_string(ap, flag, buff);
	else
		parser_two(ap, flag, buff, str);
	return (1);
}
