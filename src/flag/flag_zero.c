/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:43:26 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/30 18:43:27 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		flag_zero(char **str, t_return *flag)
{
	size_t		i;
	char		*temp;
	char		*temp2;

	if (flag->zero != -1 && (size_t)flag->zero > flag->len)
	{
		i = 0;
		if (!(temp = ft_strnew(flag->zero - flag->len + 1)) ||
			!(temp2 = ft_strnew(flag->len + 1)))
			return (0);
		while (i < flag->zero - flag->len)
			temp[i++] = '0';
		ft_strncpy(temp2, *str, flag->len);
		free(*str);
		if (!(*str = ft_strnjoin(temp, *str, flag->zero -
			flag->len, flag->len)))
			return (0);
		flag->len = flag->zero;
		free(temp);
		free(temp2);
	}
	return (1);
}
