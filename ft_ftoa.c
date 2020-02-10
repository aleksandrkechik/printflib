/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:58:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/22 15:54:25 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		need_round(long double num)
{
	if ((num *= 10) > 5)
		return (1);
	else if (num < 5)
		return (0);
	else if (num == 5)
		need_round(num);
	return (0);
}

int		g_c(long nb)
{
	int		size;

	size = 1;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int		ft_ftoa2(long double *num, int *times, int *temp, char **output)
{
	INIT_COUNTER(zeroes);
	while (*times != 0)
	{
		(*temp) += (int)(*num *= 10);
		(*num) -= (int)*num;
		if (*num == 0.0f && *temp == 0)
			zeroes++;
		if (((((*temp * 10) / 10) == *temp) && *times != 1) ||
			((int)*num == 0 && *temp == 0))
		{
			(*temp) *= 10;
			if (*num != 0.0f && *temp == 0)
				(*output) = freejoin((*output), ft_strdup("0"));
		}
		if ((((*temp * 10) / 10) != *temp))
		{
			(*output) = freejoin((*output), ft_itoa(*temp / 10));
			*temp = 0;
		}
		(*times)--;
	}
	return (zeroes);
}

int		ft_ft3(t_f s, long double num)
{
	if (need_round(num) && g_c((*s.t)) == g_c((*s.t) + 1) && (*s.z != 0))
		(*s.t)++;
	else if (need_round(num) && g_c((*s.t)) && ((int)ft_strlen(ft_strchr(
	(*s.output), '.')) - 2) + g_c((*s.t) + 1) == (*s.z) && (g_c(
	(*s.t)) + 1 == g_c((*s.t) + 1)) && g_c((*s.t)) != (*s.z))
	{
		(*s.output)[ft_strlen((*s.output)) - 1] = 0;
		(*s.output) = freejoin((*s.output), ft_itoa_base(((*s.t) + 1), 10));
		return (1);
	}
	else if ((need_round(num) && g_c((*s.t)) != g_c((*s.t) + 1))
	|| (need_round(num) && (*s.times) == 0 && (*s.t) == 0))
	{
		free((*s.output));
		(*s.output) = (*s.before_point) > 0 ? freejoin(ft_itoa_base(
	(*s.before_point) + 1, 10), ft_strdup(".")) : freejoin(ft_itoa_base(
	(*s.before_point) - 1, 10), ft_strdup("."));
		(*s.t) = 0;
		(*s.zeroes) = (*s.z);
	}
	if ((int)num == 0 && (((*s.t) * 10) / 10) != ((*s.t) * 10))
		(*s.t) *= 10;
	if ((*s.t) != 0)
		(*s.output) = freejoin((*s.output), ft_itoa((*s.t) / 10));
	return (0);
}

char	*ft_ftoa(long double num, int times)
{
	long	b_p;
	char	*output;

	INIT_COUNTER(z);
	INIT_COUNTER(zeroes);
	INIT_COUNTER(temp);
	b_p = (long)num;
	z = num < 0 && (int)num == 0 ? -1 : z;
	num -= (long double)b_p;
	num = num < 0 ? -num : num;
	output = z == -1 ? freejoin(ft_strdup("-0"), ft_strdup(".")) :
			freejoin(ft_itoa_base(b_p, 10), ft_strdup("."));
	z = times;
	zeroes = ft_ftoa2(&num, &times, &temp, &output);
	if (temp == 0 && ((int)ft_strlen(ft_strchr(output, '.')) - 2) &&
		need_round(num) && g_c(temp) == g_c(temp + 1) && (z != 0))
	{
		output[ft_strlen(output) - 1] = '1';
		return (output);
	}
	if (ft_ft3((t_f){&output, &temp, &z, &times, &b_p, &zeroes}, num) == 1)
		return (output);
	while (zeroes-- > 0)
		output = freejoin(output, ft_strdup("0"));
	return (test_round(&output, z + 1));
}
