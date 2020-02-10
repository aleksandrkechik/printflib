/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gap_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:58:15 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/21 12:06:53 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_gap(t_arg_list *arg)
{
	if (ft_strchr(arg->flags, ' ') != '\0')
		arg->gap = 1;
	else
		arg->gap = 0;
	(check_plus(arg));
}

char	*handle_gap(t_arg_list *arg, char *input)
{
	char *output;

	if (arg->plus == 1)
		return (input);
	if (arg->gap == 1 && ft_strchr(input, '+') == '\0'
		&& ft_strchr(input, '-') == '\0' && arg->uns != 1)
	{
		output = ft_strjoin(" ", input);
		free(input);
		return (output);
	}
	return (input);
}
