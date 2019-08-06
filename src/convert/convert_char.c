/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:44:44 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/30 18:44:44 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		convert_char(va_list *ap, t_return *flag, char **buff)
{
	char	*str;

	if (!(str = ft_strnew(2)))
		return (0);
	str[0] = (char)va_arg(*ap, int);
	flag->len = 1;
	if (!flag_zero(&str, flag) || !flag_width(&str, flag)
		|| !flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
