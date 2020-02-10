/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:36:56 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/12 14:02:17 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "arg_list.h"

void		add_elem(t_arg_list **head, t_arg_list *elem)
{
	t_arg_list *iter;

	iter = (*head);
	while (iter->next != iter->tail)
		iter = iter->next;
	iter->next = elem;
	elem->next = (*head)->tail;
	elem->number = iter->number + 1;
	elem->tail = (*head)->tail;
	elem->head = *head;
}

t_arg_list	*create_arg_list(void)
{
	t_arg_list *head;
	t_arg_list *tail;

	if (!(head = (t_arg_list*)malloc(sizeof(t_arg_list))))
		return (NULL);
	if (!(tail = (t_arg_list*)malloc(sizeof(t_arg_list))))
	{
		free(head);
		return (NULL);
	}
	head->tail = tail;
	head->head = head;
	head->number = -1;
	head->next = tail;
	tail->next = NULL;
	tail->tail = tail;
	return (head);
}

t_arg_list	*get_elem(t_arg_list **head, int index)
{
	t_arg_list *iter;

	iter = *head;
	while (iter->number != index)
	{
		iter = iter->next;
		if (iter->number == index)
			return (iter);
	}
	return (NULL);
}

t_arg_list	*create_elem(void *elem_content, int type, size_t elem_size)
{
	t_arg_list *elem;

	if (!(elem = (t_arg_list*)malloc(sizeof(t_arg_list))))
		return (NULL);
	elem->content_size = elem_size;
	elem->type = type;
	if (elem_content == NULL)
		elem->content = NULL;
	else
		elem->content = ft_memdup(elem_content, elem_size);
	elem->flags = NULL;
	return (elem);
}

void		add_arg(t_arg_list **head, void *elem_content, int type,
			size_t elem_size)
{
	t_arg_list *temp;

	temp = create_elem(elem_content, type, elem_size);
	if (temp == NULL)
		ft_putendl("Could not create element because no.");
	add_elem(head, temp);
}
