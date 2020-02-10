/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:47:11 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 13:48:31 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		validate_long_int(char *flags)
{
	int ls;
	int i;

	i = 0;
	ls = 0;
	while (flags[i])
	{
		if (flags[i] == 'l')
			ls++;
		i++;
	}
	if (ls == 2 && ft_strstr(flags, "ll") == '\0')
		return (1);
	if (ls != 2 && ls != 1 && ls != 0)
		return (1);
	return (0);
}

int		validate_long_float(char *flags)
{
	int ls;
	int i;

	i = 0;
	ls = 0;
	while (flags[i])
	{
		if (flags[i] == 'l' || flags[i] == 'L')
			ls++;
		i++;
	}
	if (ls != 1)
		return (1);
	return (0);
}

int		validate_long(t_arg_list *arg)
{
	if (arg->type == INT)
		return (validate_long_int(arg->flags));
	else if (arg->type == FLOAT || arg->type == LONG_FLOAT)
		return (validate_long_float(arg->flags));
	return (0);
}

int		check_invalid_flags(char *flags)
{
	size_t i;

	if (flags == NULL)
		return (0);
	INIT_VALID_FLAGS;
	i = 1;
	while (i < ft_strlen(flags) - 1)
	{
		if (ft_strchr(valid_flags, flags[i]) == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		flag_validation(t_arg_list *arg)
{
	int total;

	total = 0;
	total += validate_long(arg);
	total += check_invalid_flags(arg->flags);
	if (total != 0)
		return (1);
	return (0);
}
