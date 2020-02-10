/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:01:51 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 14:02:17 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flags(t_arg_list **head, int index, char *flags)
{
	t_arg_list *iter;

	iter = *head;
	while (iter->number != index)
		iter = iter->next;
	iter->flags = ft_strdup(flags);
	free(flags);
}

int		get_arg_number(t_arg_list **head)
{
	t_arg_list	*iter;
	int			i;

	i = 0;
	iter = (*head);
	while (iter->next != iter->tail)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}

void	destroy_elem(t_arg_list *elem)
{
	if (elem->head != elem && elem->tail != elem)
	{
		free(elem->content);
		if (elem->flags != NULL)
			free(elem->flags);
	}
	free(elem);
}

void	destroy_arg_list(t_arg_list **head)
{
	t_arg_list *iter;
	t_arg_list *temp;

	temp = *head;
	while (temp)
	{
		iter = temp;
		temp = temp->next;
		destroy_elem(iter);
	}
}
