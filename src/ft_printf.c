/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:19:47 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/13 16:19:47 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void				ft_printf_putstr(char *buff, size_t len)
{
	write(1, &*buff, len);
}

static intmax_t			central(const char *str, va_list *ap, t_return *flag)
{
	char		*buff;

	flag->ptr_cs = 0;
	flag->ptr_bff = 0;
	flag->buff_size_multi = 1;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (str[flag->ptr_cs] != '\0')
	{
		if (str[flag->ptr_cs] == '%')
		{
			if (!take_flag(str, ap, flag, &buff))
			{
				free(buff);
				return (-1);
			}
		}
		else
			insert_char(str[flag->ptr_cs], &buff, flag);
		flag->ptr_cs++;
	}
	ft_printf_putstr(buff, (size_t)flag->ptr_bff);
	free(buff);
	return (flag->ptr_bff);
}

int						ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;
	t_return	flag;

	va_start(ap, str);
	ret = central(str, &ap, &flag);
	va_end(ap);
	return (ret);
}
