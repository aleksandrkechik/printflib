/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:26:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/29 14:30:33 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_double_mod(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
			s = insert_replacement(s, "", i + 1, 1);
		i++;
	}
	return (s);
}
