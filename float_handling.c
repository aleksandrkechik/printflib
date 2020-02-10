/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:41:49 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/21 16:48:00 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_hash(t_arg_list *arg)
{
	if (ft_strchr(arg->flags, '#') != '\0')
		arg->hash = 1;
	else
		arg->hash = 0;
}

int		check_long_float(char *flags)
{
	if (ft_strstr(flags, "L") != NULL)
		return (1);
	else
		return (0);
}

char	*hash_magic(char *out, t_arg_list *arg)
{
	char		*temp;

	if (arg->hash == 0)
	{
		temp = ft_strsub(out, 0, ft_strlen(out) - 1);
		free(out);
		return (temp);
	}
	return (out);
}

char	*float_handling(t_arg_list *arg)
{
	char		*out;
	long double	nb;

	find_precision(arg);
	check_exp(arg);
	check_hash(arg);
	if (arg->exp == EXP || arg->exp == LONG_EXP)
		return (exp_handling(arg));
	if (arg->exp == G_STUFF || arg->exp == L_G_STUFF)
		return (g_stuff_handling(arg));
	if ((*arg).type == FLOAT)
		nb = *(double*)(arg->content);
	if ((*arg).type == LONG_FLOAT)
		nb = *(long double*)((*arg).content);
	if ((*arg).precision == -1)
		out = ft_ftoa(nb, 6);
	else
		out = ft_ftoa(nb, (*arg).precision);
	if (arg->precision == 0)
		out = hash_magic(out, arg);
	check_gap(arg);
	check_extra_flags(arg, &out);
	if (arg->gap == 1)
		out = handle_gap(arg, out);
	return (out);
}
