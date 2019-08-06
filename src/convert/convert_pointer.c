/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:43:20 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 15:43:21 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static size_t		pointer_flag_accuracy(char **str, t_return *flag)
{
	char		*temp;
	char		*temp2;
	size_t		i;

	if (flag->accuracy != -1 && (size_t)flag->accuracy > flag->len - 2)
	{
		i = 0;
		flag->len -= 2;
		if (!(temp = ft_strnew(flag->accuracy - flag->len + 1)))
			return (0);
		while (i < flag->accuracy - flag->len)
			temp[i++] = '0';
		str[0][1] = '0';
		if (!(temp2 = ft_strjoin(temp, *str)))
			return (0);
		temp2[1] = 'x';
		flag->len = flag->accuracy + 2;
		free(*str);
		if (!(*str = ft_strnew(flag->len + 1)))
			return (0);
		ft_strncpy(*str, temp2, flag->len);
		free(temp2);
		free(temp);
	}
	return (1);
}

static size_t		convert_pointer_str(va_list *ap, t_return *flag, char **str)
{
	char		*temp;

	if (!(str[0] = ft_uitoa_base((long unsigned int)va_arg(*ap, void*), 16)))
		return (0);
	if (!(temp = ft_strjoin("0x", str[0])))
		return (0);
	flag->len = ft_strlen(temp);
	free(str[0]);
	if (!(str[0] = ft_strnew(flag->len + 1)))
		return (0);
	ft_strncpy(str[0], temp, flag->len);
	free(temp);
	if (flag->zero != -1 && flag->accuracy != -1 && flag->zero > flag->accuracy)
	{
		flag->width = flag->zero;
		flag->zero = -1;
	}
	return (1);
}

size_t				convert_pointer(va_list *ap, t_return *flag, char **buff)
{
	char		*str;

	if (!convert_pointer_str(ap, flag, &str))
		return (0);
	if (flag->accuracy == 0 && ft_strcmp(str, "0x0") == 0)
	{
		flag->len--;
		str[2] = '\0';
	}
	else if (!pointer_flag_accuracy(&str, flag))
		return (0);
	if (!pointer_flag_accuracy(&str, flag))
		return (0);
	if (flag->zero != -1 && (size_t)flag->zero > flag->len)
	{
		str[1] = '0';
		if (!flag_zero(&str, flag))
			return (0);
		str[1] = 'x';
	}
	if (!flag_width(&str, flag) || !flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
