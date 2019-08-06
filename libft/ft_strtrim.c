/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:44:00 by tjohanne          #+#    #+#             */
/*   Updated: 2017/11/30 22:44:01 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		str_len;

	if (!s)
		return (NULL);
	while (*s != '\0' && (*s == ' ' || *s == '\n'
			|| *s == '\t'))
		s++;
	str_len = ft_strlen(s);
	while (str_len > 0 && (s[str_len - 1] == ' ' || s[str_len - 1] == '\n'
			|| s[str_len - 1] == '\t'))
		str_len--;
	return (ft_strsub(s, 0, str_len));
}
