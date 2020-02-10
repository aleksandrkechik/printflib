/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:55:38 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 13:56:22 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*is_valid_color2(char *color)
{
	if (ft_strequ(color, "cyan") == 1)
		return (ft_strdup("\e[0;36m"));
	if (ft_strequ(color, "light cyan") == 1)
		return (ft_strdup("\e[1;36m"));
	if (ft_strequ(color, "red") == 1)
		return (ft_strdup("\e[0;31m"));
	if (ft_strequ(color, "light red") == 1)
		return (ft_strdup("\e[1;31m"));
	if (ft_strequ(color, "eoc") == 1)
		return (ft_strdup("\e[0m"));
	if (ft_strequ(color, "purple") == 1)
		return (ft_strdup("\e[0;35m"));
	if (ft_strequ(color, "light purple") == 1)
		return (ft_strdup("\e[1;35m"));
	if (ft_strequ(color, "brown") == 1)
		return (ft_strdup("\e[0;33m"));
	if (ft_strequ(color, "yellow") == 1)
		return (ft_strdup("\e[1;33m"));
	if (ft_strequ(color, "gray") == 1)
		return (ft_strdup("\e[0;30m"));
	if (ft_strequ(color, "light gray") == 1)
		return (ft_strdup("\e[0;37m"));
	else
		return (ft_strnew(0));
}

char	*is_valid_color(char *color)
{
	if (ft_strequ(color, "white") == 1)
		return (ft_strdup("\e[1;37m"));
	if (ft_strequ(color, "black") == 1)
		return (ft_strdup("\e[0;30m"));
	if (ft_strequ(color, "blue") == 1)
		return (ft_strdup("\e[0;34m"));
	if (ft_strequ(color, "purple") == 1)
		return (ft_strdup("\e[0;35m"));
	if (ft_strequ(color, "purple") == 1)
		return (ft_strdup("\e[0;35m"));
	if (ft_strequ(color, "light blue") == 1)
		return (ft_strdup("\e[1;34m"));
	if (ft_strequ(color, "green") == 1)
		return (ft_strdup("\e[0;32m"));
	if (ft_strequ(color, "light green") == 1)
		return (ft_strdup("\e[1;32m"));
	else
		return (is_valid_color2(color));
}
