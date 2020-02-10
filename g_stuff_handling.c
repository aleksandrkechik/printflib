/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_stuff_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:49:54 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/11 17:51:51 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*kill_zeroes(char *input, int precision)
{
	char	*output;
	int		i;

	i = (int)ft_strlen(input) - 1;
	if (input[i] == '0')
	{
		while (input[i] == '0' || i > precision)
			i--;
		if (input[i] == '.')
			i--;
		output = ft_strsub(input, 0, i + 1);
		free(input);
		return (output);
	}
	return (input);
}

char	*g_stuff(t_arg_list *arg, long double nb)
{
	long			before_point;
	char			*output;

	INIT_COUNTER(times);
	before_point = (long)(nb);
	while (before_point > 9)
	{
		nb /= 10;
		before_point = (int)(nb);
		times++;
	}
	output = ft_ftoa(nb, 5);
	if (arg->precision != -1)
		output = kill_zeroes(output, arg->precision);
	else
		output = kill_zeroes(output, 6);
	if (arg->large_e == 0)
		output = freejoin(output, ft_strdup("e+0"));
	else
		output = freejoin(output, ft_strdup("E+0"));
	output = freejoin(output, ft_itoa(times));
	return (output);
}

char	*g_stuff_handling(t_arg_list *arg)
{
	long double		nb;
	int				nb_size;

	if (arg->exp == G_STUFF)
		nb = *(double*)(arg->content);
	if (arg->exp == L_G_STUFF)
		nb = *(long double*)((*arg).content);
	nb_size = g_c((int)nb);
	if ((nb_size < arg->precision))
		return (ft_ftoa(nb, arg->precision - nb_size));
	else if ((arg->precision == -1 && nb_size < 6))
		return (ft_ftoa(nb, 6 - nb_size));
	else if (nb_size == arg->precision)
		return (ft_itoa((int)nb));
	else
		return (g_stuff(arg, nb));
}
