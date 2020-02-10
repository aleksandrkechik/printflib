/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:36:48 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/19 17:25:57 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long	ft_atol(const char *str)
{
	long					result;
	long					index;
	long					is_negative;

	result = 0;
	is_negative = 1;
	index = parse_ws(str);
	if (str[index - 1] == '-')
		is_negative = -1;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			break ;
		result += str[index] - '0';
		if (str[index + 1] == '\0' || str[index + 1] < '0' ||
			str[index + 1] > '9')
			break ;
		result *= 10;
		if (result > result * 10)
		{
			return (handle_overflow(str, is_negative, index));
		}
		index++;
	}
	return ((result * is_negative));
}

void	check_align(t_arg_list *arg)
{
	int i;

	i = 0;
	while (arg->flags[i])
	{
		if (arg->flags[i] == '-')
			arg->alignment = LEFT_ALIGN;
		i++;
	}
}

void	check_min_width2(t_arg_list *arg, int *i)
{
	while (arg->flags[*i] && !ft_isdigit(arg->flags[*i]))
	{
		if (arg->flags[*i] == '.')
			return ;
		if (arg->flags[*i] == '-')
			arg->alignment = LEFT_ALIGN;
		(*i)++;
	}
	if (arg->flags[*i] == '0')
	{
		arg->zeroing = 1;
		(*i)++;
	}
}

void	check_min_width(t_arg_list *arg)
{
	int		start;
	char	*temp;

	INIT_COUNTER(i);
	arg->alignment = RIGHT_ALIGN;
	arg->zeroing = -1;
	arg->min_field_width = -1;
	check_min_width2(arg, &i);
	if (arg->flags[i] == '-' || arg->flags[i] == '+')
		i++;
	start = i;
	while (ft_isdigit(arg->flags[i]))
		i++;
	temp = ft_strsub(arg->flags, start, i - start + 1);
	arg->min_field_width = ft_atoi(temp);
	free(temp);
	if (arg->min_field_width < 0)
		arg->min_field_width = -arg->min_field_width;
	check_align(arg);
}

char	*check_extra_flags(t_arg_list *arg, char **output)
{
	check_plus(arg);
	check_min_width(arg);
	if ((*arg).plus)
		(*output) = handle_plus((*output));
	(*output) = process_flags(arg, output);
	return (*output);
}
