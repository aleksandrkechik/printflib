/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:17:51 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/19 17:24:24 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg_list.h"

void	str_to_low(char **str)
{
	INIT_COUNTER(i);
	while ((*str)[i])
	{
		(*str)[i] = ft_tolower((*str)[i]);
		i++;
	}
}

char	*handle_uns(t_arg_list *arg)
{
	char			*out;
	unsigned long	nb;

	if (arg->width == LONG_FLAG)
		nb = *(unsigned long*)arg->content;
	if (arg->width == SHORT_FLAG)
		nb = (unsigned short int)*(long*)arg->content;
	if (arg->width == CHAR_FLAG)
		nb = (unsigned char)*(long*)arg->content;
	if (arg->width == DEFAULT)
		nb = (unsigned int)*(long*)arg->content;
	if (arg->base != -16)
		return (ft_utoa_base(nb, arg->base));
	else
	{
		out = ft_utoa_base(nb, -arg->base);
		str_to_low(&out);
		return (out);
	}
}

char	*handle_sign(t_arg_list *arg)
{
	long	nb;
	char	*out;

	if (arg->width == LONG_FLAG)
		nb = (long)*(long*)arg->content;
	if (arg->width == SHORT_FLAG)
		nb = (short int)*(long*)arg->content;
	if (arg->width == CHAR_FLAG)
		nb = (char)*(long*)arg->content;
	if (arg->width == DEFAULT)
		nb = (int)*(long*)arg->content;
	if (arg->base != -16)
		return (ft_itoa_base(nb, arg->base));
	else
	{
		out = ft_itoa_base(nb, -arg->base);
		str_to_low(&out);
		return (out);
	}
}

void	int_to_str2(t_arg_list *arg, char **output, char *prec)
{
	if (arg->precision == 0 && !(arg->hash == 1 && arg->base == 8)
		&& !(arg->base == 10 && ft_atol((*output)) != 0))
		ft_strclr((*output));
	if (prec && (arg->base == 16 || arg->base == -16) && arg->hash == 1)
		(*output) = insert_replacement((*output), freejoin(prec,
				ft_memdup("00", 2)), 2, 0);
	else if (prec && ft_atol((*output)) < 0)
		(*output) = insert_replacement((*output), freejoin(prec,
						ft_memdup("0", 1)), 1, 0);
	else if ((prec == NULL && ft_atoi((*output)) < 0) &&
			(arg->precision != -1 && arg->zeroing == 1))
		(*output) = insert_replacement((*output), "0", 1, 0);
	else if (prec)
		(*output) = freejoin(prec, (*output));
}

char	*int_to_str(t_arg_list *arg)
{
	char	*output;
	char	*prec;

	if (arg->uns == 1)
		output = handle_uns(arg);
	else
		output = handle_sign(arg);
	output = add_base_hash(arg, output);
	prec = (int_precision(arg, ft_strlen((output))));
	int_to_str2(arg, &output, prec);
	check_gap(arg);
	check_extra_flags(arg, &output);
	if (arg->gap == 1)
		output = handle_gap(arg, output);
	return (output);
}
