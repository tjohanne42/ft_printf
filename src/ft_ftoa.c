/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjohanne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:30:20 by tjohanne          #+#    #+#             */
/*   Updated: 2018/12/07 11:30:21 by tjohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t		ft_ftoa_join(char **str_dec, char **str)
{
	char			*temp;
	char			*temp2;

	if (!(temp = ft_strjoin(str[0], ".")))
		return (0);
	if (!(temp2 = ft_strjoin(temp, str_dec[0])))
		return (0);
	free(str[0]);
	free(str_dec[0]);
	if (!(str[0] = ft_strnew(ft_strlen(temp2) + 1)))
		return (0);
	if (!ft_strcpy(str[0], temp2))
		return (0);
	free(temp);
	free(temp2);
	return (1);
}

static size_t		ft_ftoa_increase_num(char **str)
{
	int				i;
	char			*temp;

	i = ft_strlen(str[0]) - 1;
	while (i >= 0 && str[0][i] == '9')
	{
		str[0][i] = '0';
		i--;
	}
	if (i >= 0)
		str[0][i] += 1;
	else
	{
		if (!(temp = ft_strjoin("1", str[0])))
			return (0);
		free(str[0]);
		if (!(str[0] = ft_strnew(ft_strlen(temp) + 1)))
			return (0);
		if (!ft_strcpy(str[0], temp))
			return (0);
		free(temp);
	}
	return (1);
}

static size_t		ft_ftoa_round(char **str, char **str_dec, int i)
{
	if (i == 0)
	{
		if (!ft_ftoa_increase_num(str))
			return (0);
	}
	else if (i != 0 && str_dec[0][i - 1] != '9')
		str_dec[0][i - 1] += 1;
	else
	{
		while (i - 1 >= 0 && str_dec[0][i - 1] == '9')
		{
			str_dec[0][i - 1] = '0';
			i--;
		}
		if (i - 1 >= 0)
			str_dec[0][i - 1] += 1;
		else
		{
			if (!ft_ftoa_increase_num(str))
				return (0);
		}
	}
	return (1);
}

static size_t		ft_ftoa_accuracy(char **str, long double dec,
					size_t accuracy)
{
	char			*str_dec;
	size_t			i;

	i = 0;
	if (!(str_dec = ft_strnew(accuracy + 1)))
		return (0);
	while (i < accuracy)
	{
		dec *= 10.0;
		if (i + 1 == accuracy)
			dec += 0.5;
		if ((long long)dec >= 10.0)
		{
			if (!ft_ftoa_round(str, &str_dec, (int)i))
				return (0);
			dec -= 10.0;
		}
		str_dec[i] = (long long)dec + '0';
		dec -= (str_dec[i] - '0');
		i++;
	}
	if (!ft_ftoa_join(&str_dec, str))
		return (0);
	return (1);
}

char				*ft_ftoa(long double nb, size_t accuracy)
{
	long double		dec;
	long double		num;
	char			*str;

	if (accuracy == 0)
		nb += 0.5;
	num = (long long)nb;
	dec = nb - num;
	if (dec < 0)
		dec *= -1;
	if (!(str = ft_itoa_base((long long)num, 10)))
		return (NULL);
	if (accuracy > 0)
	{
		if (!ft_ftoa_accuracy(&str, dec, accuracy))
			return (NULL);
	}
	return (str);
}
