/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:15:12 by hturkatr          #+#    #+#             */
/*   Updated: 2019/10/30 12:24:10 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_size_base(unsigned long nb, int base)
{
	int		size;

	size = 1;
	while (nb >= (unsigned long)base)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char			*ft_utoa_base(unsigned long long nb, int base)
{
	int		size;
	char	*ret;
	char	*digits;

	digits = "0123456789ABCDEF";
	size = get_size_base(nb, base);
	if (!(ret = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ret[size--] = '\0';
	if (nb == 0)
		ret[0] = '0';
	while (nb >= 1)
	{
		ret[size--] = digits[(nb % base)];
		nb /= base;
	}
	return (ret);
}
