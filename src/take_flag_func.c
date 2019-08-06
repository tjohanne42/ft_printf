/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_flag_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:31:39 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/30 18:31:39 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t		take_flag_func_4(va_list *ap, const char *str,
					t_return *flag, int temp)
{
	if (str[flag->ptr_cs] <= '9' && str[flag->ptr_cs] > '0')
	{
		flag->width = ft_atoi(&str[flag->ptr_cs]);
		flag->ptr_cs += ft_nbrlen(flag->width) - 1;
	}
	else if (str[flag->ptr_cs] == '*')
	{
		temp = va_arg(*ap, int);
		if (temp < 0)
		{
			flag->negative = temp * -1;
			flag->width = temp * -1;
		}
		else
			flag->width = temp;
	}
	else if (str[flag->ptr_cs] == 'j')
		flag->j = 1;
	else if (str[flag->ptr_cs] == 'z')
		flag->z = 1;
	else if (str[flag->ptr_cs] == 'L')
		flag->lfloat = 1;
	else
		return (0);
	return (1);
}

static size_t		take_flag_func_3(va_list *ap, const char *str,
					t_return *flag, int temp)
{
	if (str[flag->ptr_cs] == '.')
	{
		if (str[flag->ptr_cs + 1] <= '9' && str[flag->ptr_cs + 1] >= '0')
		{
			flag->accuracy = ft_atoi(&str[flag->ptr_cs + 1]);
			while (str[flag->ptr_cs + 1] >= '0' && str[flag->ptr_cs + 1] <= '9')
				flag->ptr_cs++;
		}
		else if (str[flag->ptr_cs + 1] == '*')
		{
			flag->accuracy = va_arg(*ap, int);
			if (flag->accuracy < 0)
				flag->accuracy = -1;
			flag->ptr_cs++;
		}
		else
			flag->accuracy = 0;
	}
	else if (!take_flag_func_4(ap, str, flag, temp))
		return (0);
	return (1);
}

static size_t		take_flag_func_2(va_list *ap, const char *str,
					t_return *flag, int temp)
{
	if (str[flag->ptr_cs] == '0')
	{
		if (str[flag->ptr_cs + 1] <= '9' && str[flag->ptr_cs + 1] > '0')
		{
			flag->zero = ft_atoi(&str[flag->ptr_cs + 1]);
			flag->width = flag->zero;
			flag->ptr_cs += ft_nbrlen(flag->zero);
		}
		else
			flag->zero = 0;
	}
	else if (str[flag->ptr_cs] == '-')
	{
		if (str[flag->ptr_cs + 1] <= '9' && str[flag->ptr_cs + 1] > '0')
		{
			flag->negative = ft_atoi(&str[flag->ptr_cs + 1]);
			flag->width = flag->negative;
			flag->ptr_cs += ft_nbrlen(flag->negative);
		}
		else
			flag->negative = 0;
	}
	else if (!take_flag_func_3(ap, str, flag, temp))
		return (0);
	return (1);
}

size_t				take_flag_func(va_list *ap, const char *str,
					t_return *flag, int temp)
{
	if (str[flag->ptr_cs] == '#')
		flag->sharp = 1;
	else if (str[flag->ptr_cs] == '+')
		flag->positive = 1;
	else if (str[flag->ptr_cs] == ' ')
		flag->space = 1;
	else if (str[flag->ptr_cs] == 'h')
	{
		flag->hh = flag->h;
		if (flag->h != -1)
			flag->h = -1;
		else
			flag->h = 1;
	}
	else if (str[flag->ptr_cs] == 'l')
	{
		flag->ll = flag->l;
		if (flag->l != -1)
			flag->l = -1;
		else
			flag->l = 1;
	}
	else if (!take_flag_func_2(ap, str, flag, temp))
		return (0);
	return (1);
}
