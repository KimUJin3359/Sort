/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:19:40 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:21:36 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		swap(t_node **list)
{
	t_node *tmp;

	tmp = *list;
	if (size(*list) > 1)
	{
		*list = (*list)->next;
		tmp->next = (*list)->next;
		(*list)->next = tmp;
	}
	return (1);
}

int		push(t_node **from, t_node **to)
{
	t_node *tmp;

	if (size(*from) > 0)
	{
		tmp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		*from = tmp;
	}
	return (1);
}

int		shift_up(t_node **list)
{
	t_node *tmp;
	t_node *top;

	if (size(*list) > 1)
	{
		tmp = *list;
		top = *list;
		*list = (*list)->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = top;
		top->next = NULL;
	}
	return (1);
}

int		shift_down(t_node **list)
{
	t_node *tmp;

	if (size(*list) > 1)
	{
		tmp = *list;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next->next = *list;
		*list = tmp->next;
		tmp->next = NULL;
	}
	return (1);
}

int		pop(t_node **list)
{
	int		data;
	t_node	*tmp;

	data = (*list)->data;
	tmp = (*list);
	(*list) = (*list)->next;
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
	return (data);
}
