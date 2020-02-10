/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_replacement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:34:28 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/19 15:24:20 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insert_replacement(char *s, char *replacement, int loc, int size)
{
	char *first;
	char *last;
	char *ret;
	char *ret1;

	first = ft_strsub(s, 0, loc);
	last = ft_strsub(s, loc + size, ft_strlen(s) - (loc + 1) + 1);
	ret = ft_strjoin(first, replacement);
	free(first);
	ret1 = freejoin(ret, last);
	free(s);
	return (ret1);
}
