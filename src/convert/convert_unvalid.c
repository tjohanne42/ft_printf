/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unvalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:31:22 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/16 18:31:23 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		convert_unvalid(t_return *flag, char **buff, const char *str)
{
	char	*temp;

	if (str[flag->ptr_cs + 1] == '\0')
		return (1);
	if (!(temp = ft_strnew(2)))
		return (0);
	temp[0] = str[flag->ptr_cs + 1];
	flag->ptr_cs++;
	flag->len = 1;
	if (!flag_zero(&temp, flag) || !flag_width(&temp, flag) ||
		!flag_negative(&temp, flag))
		return (0);
	insert_str(temp, buff, flag, flag->len);
	free(temp);
	return (1);
}
