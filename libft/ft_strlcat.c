/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:42:49 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/29 17:42:49 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = 0;
	src_len = 0;
	while (*((char*)dst + dst_len) != '\0')
		dst_len++;
	while (*((char*)src + src_len) != '\0')
		src_len++;
	while ((dst_len + i + 1) < size && *((char*)src + i) != '\0')
	{
		*((char*)dst + dst_len + i) = *((char*)src + i);
		i++;
	}
	*((char*)dst + dst_len + i) = '\0';
	if (size >= dst_len)
		return (dst_len + src_len);
	return (src_len + size);
}
