/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <hturkatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:02:14 by hturkatr          #+#    #+#             */
/*   Updated: 2019/11/18 14:58:05 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_LIST_H
# define ARG_LIST_H

# include "ft_printf.h"

typedef struct s_arg_list	t_arg_list;

void						add_elem(t_arg_list **head, t_arg_list *elem);
t_arg_list					*create_arg_list();
t_arg_list					*get_elem(t_arg_list **head, int index);
t_arg_list					*create_elem(void *elem_content,
							int type, size_t elem_size);
void						add_arg(t_arg_list **head, void *elem_content,
						int type, size_t elem_size);
void						add_flags(t_arg_list **head, int index, char
						*flags);
int							get_arg_number(t_arg_list **head);
t_arg_list					*get_elem_by_index(t_arg_list **head, int index);
void						print_arg_list_types(t_arg_list **head);

struct						s_arg_list
{
	t_arg_list	*next;
	t_arg_list	*head;
	t_arg_list	*tail;
	int			number;
	void		*content;
	size_t		content_size;
	int			type;
	char		*flags;
	int			index;
	int			precision;
	int			uns;
	int			width;
	int			base;
	int			plus;
	int			min_field_width;
	int			alignment;
	int			zeroing;
	int			gap;
	int			hash;
	int			exp;
	int			large_e;
	int			indexed;
	int			valid_ind;
};

#endif
