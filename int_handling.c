/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:21:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/11 17:18:42 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_type_flag(t_arg_list *arg)
{
	if ((ft_strstr(arg->flags, "ll") != NULL) ||
	(ft_strstr(arg->flags, "l") != NULL) ||
	(ft_strstr(arg->flags, "j") != NULL) ||
	(ft_strstr(arg->flags, "z") != NULL) ||
	(ft_strstr(arg->flags, "U") != NULL))
		arg->width = LONG_FLAG;
	else if (ft_strstr(arg->flags, "L") != NULL)
		arg->width = LONG_FLOAT_FLAG;
	else if ((ft_strstr(arg->flags, "hh") != NULL)
	|| (ft_strstr(arg->flags, "c") != NULL))
		arg->width = CHAR_FLAG;
	else if (ft_strstr(arg->flags, "h") != NULL)
		arg->width = SHORT_FLAG;
	else
		arg->width = DEFAULT;
}

void		check_uns(t_arg_list *arg)
{
	INIT_COUNTER(i);
	if (!(arg->flags))
		return ;
	while (arg->flags[i] != 0)
	{
		if (arg->flags[i] == 'Y' || arg->flags[i] == 'u'
		|| arg->flags[i] == 'X' || arg->flags[i] == 'x' ||
		arg->flags[i] == 'o' || arg->flags[i] == 'U')
		{
			arg->uns = 1;
			return ;
		}
		if (arg->flags[i] == 'S')
		{
			arg->uns = 0;
			return ;
		}
		i++;
	}
	arg->uns = 0;
}

void		find_precision(t_arg_list *arg)
{
	int		result;
	char	*precision;

	INIT_COUNTER(i);
	INIT_COUNTER(start);
	while (arg->flags && arg->flags[i] != 0)
	{
		if (arg->flags[i] == '.')
		{
			start = i + 1;
			i += 2;
			while ((ft_isdigit(arg->flags[i])))
				i++;
			precision = ft_strsub(arg->flags, start, i - start);
			result = ft_atoi(precision);
			arg->precision = result;
			free(precision);
			if ((arg->type == PERC && arg->precision == 0) ||
			(arg->type == CHAR && arg->precision == 0))
				arg->precision = 1;
			return ;
		}
		i++;
	}
	arg->precision = -1;
}

void		get_base(t_arg_list *arg)
{
	if (arg->flags != NULL)
	{
		if ((ft_strstr(arg->flags, "d") != NULL) ||
		(ft_strstr(arg->flags, "c") != NULL) || (ft_strstr(arg->flags,
			"u") != NULL) || (ft_strstr(arg->flags, "i") != NULL)
			|| (ft_strstr(arg->flags, "U") != NULL))
			arg->base = 10;
		if (ft_strstr(arg->flags, "X") != NULL)
			arg->base = 16;
		if (ft_strstr(arg->flags, "x") != NULL)
			arg->base = -16;
		if (ft_strstr(arg->flags, "b") != NULL)
			arg->base = 2;
		if (ft_strstr((*arg).flags, "o") != NULL)
			arg->base = 8;
		return ;
	}
	arg->base = 0;
}

char		*int_handling(t_arg_list *arg)
{
	check_uns(arg);
	find_precision(arg);
	check_type_flag(arg);
	get_base(arg);
	return (int_to_str(arg));
}
