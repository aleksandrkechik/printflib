/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:27:23 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 13:27:34 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_min(int base)
{
	if (base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (base == 8)
		return (ft_strdup("-1000000000000000000000"));
	if (base == 16)
		return (ft_strdup("-8000000000000000"));
	else
		return (ft_strdup(
		"-1000000000000000000000000000000000000000000000000000000000000000"));
}

static int		get_size_base(long long nb, int base)
{
	int		size;

	size = 1;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb >= (long long)base)
	{
		nb /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(long long nb, int base)
{
	int		size;
	char	*ret;
	char	*digits;

	if (nb == MIN_LONG)
		return (handle_min(base));
	digits = "0123456789ABCDEF";
	size = get_size_base(nb, base);
	if (!(ret = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
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
