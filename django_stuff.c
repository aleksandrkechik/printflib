/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   django_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:04:08 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/11 15:21:44 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*freejoin(char *s1, char *s2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

char	*freecopy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (*(src + i) && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	free(src);
	return (dest);
}
