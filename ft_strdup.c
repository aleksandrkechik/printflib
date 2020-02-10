/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:11:44 by hturkatr          #+#    #+#             */
/*   Updated: 2019/09/20 14:23:47 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	char	*p;
	int		len;

	len = ft_strlen((char *)s1);
	new_str = (char*)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	p = new_str;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (new_str);
}
