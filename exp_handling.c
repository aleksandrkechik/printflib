/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:37 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 13:51:47 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

void		check_exp(t_arg_list *arg)
{
	if ((ft_strchr(arg->flags, 'e') != '\0' || ft_strchr(arg->flags,
			'E') != '\0') && ft_strchr(arg->flags, 'L') != '\0')
		arg->exp = LONG_EXP;
	else if ((ft_strchr(arg->flags, 'g') != '\0' || ft_strchr(arg->flags,
			'G') != '\0') && ft_strchr(arg->flags, 'L') != '\0')
		arg->exp = L_G_STUFF;
	else if ((ft_strchr(arg->flags, 'e') != '\0' || ft_strchr(arg->flags,
			'E') != '\0') && ft_strchr(arg->flags, 'L') == '\0')
		arg->exp = EXP;
	else if ((ft_strchr(arg->flags, 'g') != '\0' || ft_strchr(arg->flags,
			'G') != '\0') && ft_strchr(arg->flags, 'L') == '\0')
		arg->exp = G_STUFF;
	else
		arg->exp = 0;
	if (ft_strchr(arg->flags, 'E') != '\0' ||
		ft_strchr(arg->flags, 'G') != '\0')
		arg->large_e = 1;
	else
		arg->large_e = 0;
}

char		*exp_handling(t_arg_list *arg)
{
	char		*output;
	long double	nb;
	int			before_point;
	char		*test;

	INIT_COUNTER(times);
	if (arg->exp == EXP)
		nb = *(double*)(arg->content);
	if (arg->exp == LONG_EXP)
		nb = *(long double*)((*arg).content);
	before_point = (int)(nb);
	while (before_point > 9)
	{
		nb /= 10;
		before_point = (int)(nb);
		times++;
	}
	arg->precision = arg->precision == -1 ? 6 : arg->precision;
	if (arg->large_e == 0)
		output = freejoin(ft_ftoa(nb, arg->precision), ft_strdup("e+0"));
	else
		output = freejoin(ft_ftoa(nb, arg->precision), ft_strdup("E+0"));
	test = ft_itoa(times);
	output = freejoin(output, test);
	return (output);
}
