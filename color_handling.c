/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:49:07 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/19 15:33:17 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_color(char *s, int start)
{
	int i;

	if (s[start] == '}')
		return (ft_strdup(""));
	i = start + 1;
	while (s[i] && s[i] != '}')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	return (ft_strsub(s, start, i - start));
}

int		get_color_size(char *s, int start)
{
	int i;

	i = start + 1;
	while (s[i] != '}')
		i++;
	return (i + 1 - start);
}

char	*is_color(char *s, int start)
{
	char *color;
	char *valid;

	start++;
	color = get_color(s, start);
	valid = is_valid_color(color);
	free(color);
	return (valid);
}

char	*color_handling(char *s)
{
	int		i;
	char	*color;

	i = 0;
	while (s[i])
	{
		if (s[i] == '{')
		{
			color = is_color(s, i);
			if (ft_strlen(color) != 0)
			{
				s = insert_replacement(s, color, i, get_color_size(s, i));
				i += ft_strlen(color) - 1;
			}
			free(color);
		}
		i++;
	}
	return (s);
}
