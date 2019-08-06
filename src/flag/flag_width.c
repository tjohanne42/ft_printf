/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:42:26 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/30 18:42:27 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		flag_width(char **str, t_return *flag)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	if (flag->width != -1 && (size_t)flag->width > flag->len)
	{
		i = 0;
		if (!(temp = ft_strnew(flag->width - flag->len + 1)) ||
			!(temp2 = ft_strnew(flag->len + 1)))
			return (0);
		while (i < flag->width - flag->len)
			temp[i++] = ' ';
		ft_strncpy(temp2, *str, flag->len);
		free(*str);
		if (!(*str = ft_strnjoin(temp, temp2, flag->width -
			flag->len, flag->len)))
			return (0);
		flag->len = flag->width;
		free(temp);
		free(temp2);
	}
	return (1);
}
