/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:29:03 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 16:29:03 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static uintmax_t		get_nb(va_list *ap, t_return *flag)
{
	uintmax_t	nb;

	if ((flag->type >= 'A' && flag->type <= 'Z') || flag->ll != -1)
		nb = va_arg(*ap, unsigned long long);
	else if (flag->l != -1)
		nb = va_arg(*ap, unsigned long);
	else if (flag->h != -1)
		nb = (unsigned short)va_arg(*ap, int);
	else if (flag->hh != -1)
		nb = (unsigned char)va_arg(*ap, int);
	else if (flag->j != -1)
		nb = va_arg(*ap, uintmax_t);
	else if (flag->z != -1)
		nb = va_arg(*ap, ssize_t);
	else
		nb = va_arg(*ap, unsigned int);
	return (nb);
}

static size_t			unsigned_flag_accuracy(char **str, t_return *flag,
						uintmax_t nb)
{
	size_t		i;
	char		*temp;
	char		*temp2;

	if (flag->accuracy == 0 && nb == 0)
		str[0][0] = '\0';
	else if (flag->accuracy != -1 && (size_t)flag->accuracy > flag->len)
	{
		i = 0;
		if (!(temp = ft_strnew(flag->accuracy - flag->len + 1)) ||
			!(temp2 = ft_strnew(flag->len + 1)))
			return (0);
		while (i < flag->accuracy - flag->len)
			temp[i++] = '0';
		ft_strncpy(temp2, *str, flag->len);
		free(*str);
		if (!(*str = ft_strjoin(temp, temp2)))
			return (0);
		free(temp);
		free(temp2);
	}
	return (1);
}

size_t					convert_unsigned(va_list *ap, t_return *flag,
						char **buff)
{
	char		*str;
	uintmax_t	nb;

	nb = get_nb(ap, flag);
	if (!(str = ft_uitoa_base(nb, 10)))
		return (0);
	flag->len = ft_strlen(str);
	if (!unsigned_flag_accuracy(&str, flag, nb))
		return (0);
	flag->len = ft_strlen(str);
	if (!flag_zero(&str, flag) || !flag_width(&str, flag) ||
		!flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
