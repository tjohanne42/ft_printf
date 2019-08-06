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

size_t		convert_string(va_list *ap, t_return *flag, char **buff)
{
	char	*str;
	char	*temp;

	if (!(temp = va_arg(*ap, char*)))
		temp = "(null)";
	flag->len = ft_strlen(temp);
	if (!(str = ft_strnew(flag->len + 1)))
		return (0);
	ft_strcpy(str, temp);
	if (flag->accuracy != -1 && (size_t)flag->accuracy < flag->len)
	{
		str[flag->accuracy] = '\0';
		flag->len = flag->accuracy;
	}
	if (!flag_zero(&str, flag) || !flag_width(&str, flag) ||
		!flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
