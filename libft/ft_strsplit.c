/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:23:45 by tjohanne          #+#    #+#             */
/*   Updated: 2017/12/04 21:23:46 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		words_count(char const *s, char c)
{
	int		nb_mots;

	nb_mots = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		nb_mots++;
		while (*s != c && *s)
			s++;
	}
	return (nb_mots);
}

static int		ft_strclen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		nb_mots;
	int		w_len;
	int		i;

	if (!s)
		return (NULL);
	nb_mots = words_count(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (nb_mots + 1))))
		return (NULL);
	str[nb_mots] = NULL;
	i = 0;
	while (i < nb_mots)
	{
		while (*s == c)
			s++;
		w_len = ft_strclen(s, c);
		str[i++] = ft_strsub(s, 0, w_len);
		s = s + w_len + 1;
	}
	return (str);
}
