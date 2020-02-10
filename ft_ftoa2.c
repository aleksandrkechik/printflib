/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:45:18 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/22 15:06:01 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	test_round2(char **s, int *i, char **test, int *started)
{
	NWHILE(i = i, *i >= 0);
	if ((*s)[*i] == '.')
		(*test)[*i] = '.';
	if (((*s)[*i] > '4' && ((*s)[*i] <= '9') && *started == 1))
	{
		(*test)[*i] = (*s)[*i] == '9' ? '0' : (*s)[*i] + 1;
	}
	if ((*s)[*i] > '5' && *started == 0)
	{
		*started = 0;
		if ((*s)[*i] == '9')
			(*test)[*i] = '0';
		else
			(*test)[*i] = (*s)[*i] + 1;
	}
	if ((*s)[*i] < '5' && (*s)[*i] >= '0')
	{
		(*test)[*i] = (*s)[*i];
		(*i)--;
		NWHILE(i = i, *i >= -1);
		(*test)[*i] = (*s)[*i];
		END_NWHILE((*i)--);
	}
	END_NWHILE((*i)--);
	free(*s);
}

char	*test_round(char **s, int precision)
{
	int		i;
	char	*test;

	INIT_COUNTER(started);
	INIT_COUNTER(dot);
	if (precision >= 7 || precision == 2)
		return (*s);
	while ((*s)[dot] != '.')
		dot++;
	if ((dot == (int)ft_strlen(*s) - 1 || precision == (int)ft_strlen(*s) - 1)
		|| (dot == (int)ft_strlen(*s) - 2 && ft_strchr(*s, '-') != '\0'))
		return ((*s));
	test = ft_strnew(precision + dot - 1);
	NWHILE(i = precision, i != 0);
	if ((*s)[i] == '.' && i--)
		continue;
	started = ((*s)[i] > '5' && started == 0) ? 1 : started;
	END_NWHILE(i--);
	i = precision + dot;
	IF((*s)[i--] > '5');
	started = 1;
	test_round2(s, &i, &test, &started);
	return (test);
	ENDIF;
	return (*s);
}
