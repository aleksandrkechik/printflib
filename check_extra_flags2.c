/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra_flags2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:31:17 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/21 12:37:53 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_flags2(t_arg_list *arg, char **output, char **ret, char **new)
{
	if (arg->hash == 1 && arg->zeroing == 1)
	{
		if (arg->base == 8)
			(*ret) = insert_replacement(*output, (*new), 1, 0);
		if (arg->base == 16 || arg->base == -16 || arg->base == 2)
			(*ret) = insert_replacement(*output, (*new), 2, 0);
	}
	else if (arg->zeroing == 1 && ft_atol((*output)) < 0 &&
				arg->min_field_width - arg->precision > 1 &&
				arg->precision != -1)
		(*ret) = freejoin((*new), (*output));
	else if ((arg->plus == 1 || ft_atol(*output) < 0)
			&& arg->zeroing == 1)
		(*ret) = insert_replacement(*output, (*new), 1, 0);
	else if (ft_atol(*output) < 0 && arg->zeroing == 1 &&
			arg->precision < arg->min_field_width && arg->precision != -1)
		(*ret) = freejoin((*new), (*output));
	else
		(*ret) = freejoin((*new), (*output));
}

char	*process_flags(t_arg_list *arg, char **output)
{
	int		len;
	char	*new;
	char	*ret;

	ret = NULL;
	len = ft_strlen((*output));
	if (arg->min_field_width > len)
	{
		len = arg->min_field_width - len;
		if (arg->gap == 1 && ft_atol((*output)) > -1)
			len--;
		new = create_gap(arg, len, output);
		if (arg->alignment == RIGHT_ALIGN)
			process_flags2(arg, output, &ret, &new);
		else
			ret = freejoin((*output), new);
		return (ret);
	}
	return (*output);
}

char	*create_gap(t_arg_list *arg, int len, char **output)
{
	char	*new;

	new = ft_strnew(len + 1);
	if (arg->zeroing == -1 || (arg->zeroing == 1 && arg->alignment ==
		LEFT_ALIGN) || (arg->precision != -1 && (arg->zeroing == 1
		&& arg->precision < arg->min_field_width && ft_atol((*output)) > -1))
		|| (arg->zeroing == 1 && ft_atol((*output)) < 0 &&
		arg->min_field_width - arg->precision > 1 && arg->precision != -1))
		ft_memset(new, ' ', len);
	else
		ft_memset(new, '0', len);
	return (new);
}
