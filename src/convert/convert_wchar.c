/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 18:03:02 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 18:03:02 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		convert_wchar(va_list *ap, t_return *flag, char **buff)
{
	int			c;
	char		*str;
	size_t		octet;

	c = va_arg(*ap, int);
	if (c >= 0)
	{
		if (!(str = wchar_utf8(c)))
			return (0);
		flag->len = 1;
		if (ft_strlen(str) > 0)
			octet = ft_strlen(str) - flag->len;
		else
			octet = 0;
		flag->len += octet;
	}
	if (!flag_zero(&str, flag) || !flag_width(&str, flag) ||
		!flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
