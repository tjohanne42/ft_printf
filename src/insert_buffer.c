/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:26:38 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/13 17:26:39 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		buffer_cpy(char *s1, const char *s2, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		s1[i] = s2[i];
		i++;
	}
}

static void		extend_buffer(char **buff, t_return *flag)
{
	char		*temp;

	if (!(temp = ft_strnew(BUFF_SIZE * flag->buff_size_multi)))
		exit(0);
	flag->buff_size_multi++;
	buffer_cpy(temp, *buff, flag->ptr_bff + 1);
	free(*buff);
	if (!(*buff = ft_strnew(BUFF_SIZE * flag->buff_size_multi)))
		exit(0);
	buffer_cpy(*buff, temp, flag->ptr_bff + 1);
	free(temp);
}

void			insert_char(const char c, char **buff, t_return *flag)
{
	if (flag->ptr_bff == (int)(flag->buff_size_multi * BUFF_SIZE - 1))
		extend_buffer(buff, flag);
	buff[0][flag->ptr_bff] = c;
	flag->ptr_bff++;
}

void			insert_str(const char *str, char **buff,
				t_return *flag, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		insert_char(str[i], buff, flag);
		i++;
	}
}
