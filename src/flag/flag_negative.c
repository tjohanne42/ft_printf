/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_negative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:41:10 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/30 18:41:10 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		flag_negative(char **str, t_return *flag)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	if (flag->negative != -1 && (size_t)flag->negative > flag->len)
	{
		i = 0;
		if (!(temp2 = ft_strnew(flag->len + 1)) ||
			!(temp = ft_strnew(flag->negative - flag->len + 1)))
			return (0);
		ft_strncpy(temp2, *str, flag->len);
		while (i < flag->negative - flag->len)
			temp[i++] = ' ';
		free(*str);
		if (!(*str = ft_strnjoin(temp2, temp, flag->len,
			flag->negative - flag->len)))
			return (0);
		flag->len = flag->negative;
		free(temp);
		free(temp2);
	}
	return (1);
}
