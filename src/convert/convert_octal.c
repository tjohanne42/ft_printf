/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 17:48:07 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 17:48:07 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static uintmax_t	get_nb(va_list *ap, t_return *flag)
{
	uintmax_t	nb;

	if (flag->ll != -1 || (flag->type >= 'A' && flag->type <= 'Z'))
		nb = va_arg(*ap, unsigned long long);
	else if (flag->l != -1)
		nb = va_arg(*ap, unsigned long);
	else if (flag->j != -1)
		nb = va_arg(*ap, uintmax_t);
	else if (flag->z != -1)
		nb = va_arg(*ap, ssize_t);
	else if (flag->h != -1)
		nb = (unsigned short)va_arg(*ap, int);
	else if (flag->hh != -1)
		nb = (unsigned char)va_arg(*ap, int);
	else
		nb = va_arg(*ap, unsigned int);
	return (nb);
}

static size_t		octal_flag_accuracy(char **str, t_return *flag,
					size_t z)
{
	char		*temp;
	char		*temp2;
	size_t		i;

	i = 0;
	if (!(temp = ft_strnew(flag->accuracy - z + 1)) ||
		!(temp2 = ft_strnew(flag->len + 1)))
		return (0);
	while (i < flag->accuracy - z)
		temp[i++] = '0';
	ft_strncpy(temp2, *str, flag->len);
	free(*str);
	if (!(*str = ft_strjoin(temp, temp2)))
		return (0);
	flag->len += flag->accuracy - z;
	free(temp);
	free(temp2);
	return (1);
}

static size_t		octal_flag_sharp(char **str, t_return *flag)
{
	char		*temp;

	if (flag->sharp != -1 && str[0][0] != '0')
	{
		if (!(temp = ft_strnew(flag->len + 1)))
			return (0);
		ft_strncpy(temp, str[0], flag->len);
		free(str[0]);
		if (!(str[0] = ft_strjoin("0", temp)))
			return (0);
		flag->len++;
		free(temp);
	}
	if (!flag_zero(str, flag) || !flag_width(str, flag) ||
		!flag_negative(str, flag))
		return (0);
	return (1);
}

size_t				convert_octal(va_list *ap, t_return *flag,
					char **buff)
{
	char		*str;
	uintmax_t	nb;
	size_t		z;

	nb = get_nb(ap, flag);
	if (!(str = ft_uitoa_base(nb, 8)))
		return (0);
	flag->len = ft_strlen(str);
	z = flag->len;
	if (flag->accuracy == 0 && nb == 0)
	{
		str[0] = '\0';
		flag->len = 0;
	}
	else if (flag->accuracy != -1 && (size_t)flag->accuracy > z &&
		!octal_flag_accuracy(&str, flag, z))
		return (0);
	if (!octal_flag_sharp(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
