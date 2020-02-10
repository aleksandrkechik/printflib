/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:58:27 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/11 17:15:05 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*int_precision(t_arg_list *arg, int size)
{
	char	*out;
	int		prec_size;

	prec_size = arg->precision - size;
	out = NULL;
	if (prec_size > 0)
	{
		out = ft_strnew(prec_size + 1);
		ft_memset(out, 48, prec_size);
	}
	return (out);
}

char		*add_base_hash(t_arg_list *arg, char *input)
{
	check_hash(arg);
	if (arg->hash == 1)
	{
		if ((arg->base == -16) && ft_strequ("0", input) != 1)
			input = freejoin(ft_strdup("0x"), input);
		if ((arg->base == 16) && ft_strequ("0", input) != 1)
			input = freejoin(ft_strdup("0X"), input);
		if (arg->base == 2 && ft_strequ("0", input) != 1)
			input = freejoin(ft_strdup("0b"), input);
		if (arg->base == 8 && ft_strequ("0", input) != 1)
			input = freejoin(ft_strdup("0"), input);
	}
	return (input);
}
