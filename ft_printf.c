/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:29:23 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/21 15:35:28 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "arg_list.h"

void	printstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == -2)
			write(1, "\0", 1);
		else
			write(1, &(s[i]), 1);
		i++;
	}
}

char	*create_str(t_arg_list *head)
{
	char	*newstr;

	newstr = ft_strnew(1);
	INIT_COUNTER(j);
	while (j < get_arg_number(&head))
	{
		if (get_elem(&head, j)->type == STR || get_elem(&head, j)->type == CHAR
		|| get_elem(&head, j)->type == PERC || get_elem(&head, j)->type == Z)
			newstr = freejoin(newstr, string_handling(get_elem(&head, j)));
		else if (get_elem(&head, j)->type == INT)
			newstr = freejoin(newstr, int_handling(get_elem(&head, j)));
		else if (get_elem(&head, j)->type == RAW_STR)
			newstr = freejoin(newstr, ft_strdup((get_elem(&head, j))->content));
		else if ((get_elem(&head, j)->type == FLOAT)
		|| (get_elem(&head, j)->type == LONG_FLOAT))
			newstr = freejoin(newstr, float_handling(get_elem(&head, j)));
		else if (get_elem(&head, j)->type == PTR)
			newstr = freejoin(newstr, pointer_handling(get_elem(&head, j)));
		else if (get_elem(&head, j)->type == TIME)
			newstr = freejoin(newstr, timestamp_to_s(get_elem(&head, j)));
		else if (get_elem(&head, j)->type == UNPRINT)
			newstr = freejoin(newstr, print_unprintable(get_elem(&head, j)));
		j++;
	}
	return (newstr);
}

int		count_args(char *s)
{
	INIT_TYPES;
	INIT_COUNTER(i);
	INIT_COUNTER(args);
	INIT_COUNTER(started);
	while (s[i])
	{
		if ((s[i] == '%' && s[i + 1] != '%')
			&& (s[i] == '%' && s[i - 1] != '%')
			&& (size_t)i != ft_strlen(s) - 1)
		{
			args++;
			started = 1;
		}
		if (started == 1 && s[i] == '*')
			args++;
		if (ft_strchr(types, s[i]) != '\0')
			started = 0;
		i++;
	}
	return (args);
}

int		ft_printf(char *to_print, ...)
{
	int			len;
	va_list		valist;
	t_arg_list	*arg_list;
	char		*res;

	va_start(valist, to_print);
	arg_list = make_arg_list(to_print, valist);
	res = create_str(arg_list);
	res = color_handling(res);
	printstr(res);
	va_end(valist);
	destroy_arg_list(&arg_list);
	len = ft_strlen(res);
	free(res);
	return (len);
}
