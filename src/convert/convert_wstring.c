/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 18:03:02 by tjohanne          #+#    #+#             */
/*   Updated: 2018/10/14 18:03:02 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static size_t		convert_wstring_accuracy(char **str, t_return *flag,
					int *tab)
{
	size_t		i;

	i = 0;
	if (flag->accuracy != -1 && (size_t)flag->accuracy < flag->len)
	{
		if (flag->accuracy < tab[0])
		{
			flag->len = 0;
			str[0][0] = '\0';
		}
		else
		{
			i = 0;
			while (flag->accuracy >= tab[i + 1])
				i++;
			flag->len = tab[i];
			str[0][flag->len] = '\0';
		}
	}
	if (!flag_zero(str, flag) || !flag_width(str, flag) ||
		!flag_negative(str, flag))
		return (0);
	return (1);
}

static size_t		convert_wstring_tab(char **str, wchar_t *wstr,
					t_return *flag, int **tab)
{
	char		*temp;
	char		*temp2;
	size_t		i;

	i = 0;
	while (wstr[i])
	{
		if (!(temp2 = wchar_utf8(wstr[i])))
			return (0);
		if (!(temp = ft_strjoin(str[0], temp2)))
			return (0);
		if (i == 0)
			tab[0][i] = ft_strlen(temp2);
		else
			tab[0][i] = tab[0][i - 1] + ft_strlen(temp2);
		flag->len += ft_strlen(temp2);
		free(str[0]);
		if (!(str[0] = ft_strnew(flag->len + 1)))
			return (0);
		ft_strncpy(str[0], temp, flag->len);
		free(temp);
		free(temp2);
		i++;
	}
	return (1);
}

size_t				convert_wstring(va_list *ap, t_return *flag, char **buff)
{
	wchar_t		*wstr;
	char		*str;
	int			*tab;

	if (!(str = ft_strnew(0)))
		return (0);
	if (!(wstr = (wchar_t*)va_arg(*ap, intmax_t*)))
		wstr = L"(null)";
	if (!(tab = malloc(sizeof(*tab) * (ft_wstrlen(wstr)))))
		return (0);
	if (!convert_wstring_tab(&str, wstr, flag, &tab))
		return (0);
	if (!convert_wstring_accuracy(&str, flag, tab))
		return (0);
	insert_str(str, buff, flag, flag->len);
	free(tab);
	free(str);
	return (1);
}
