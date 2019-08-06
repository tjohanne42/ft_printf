/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pourcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:04:09 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 16:04:09 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t				convert_pourcent(t_return *flag, char **buff)
{
	char	*str;

	if (!(str = ft_strnew(2)))
		return (0);
	str[0] = '%';
	flag->len = 1;
	if (!flag_zero(&str, flag) || !flag_width(&str, flag) ||
		!flag_negative(&str, flag))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(str);
	return (1);
}
