/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:19:45 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:54:17 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		size(t_node *list)
{
	int i;

	i = 0;
	while (list != NULL && ++i)
		list = list->next;
	return (i);
}

void	push_back(t_node **list, int data)
{
	t_node *node;
	t_node *curr;
	t_node *prev;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->data = data;
	node->next = NULL;
	if (!(*list))
		*list = node;
	else
	{
		curr = *list;
		while (curr != NULL)
		{
			if (curr->data == data)
				print_error();
			prev = curr;
			curr = curr->next;
		}
		prev->next = node;
	}
}

void	push_front(t_node **list, int data)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->data = data;
	node->next = NULL;
	if (!(*list))
		*list = node;
	else
	{
		node->next = (*list);
		(*list) = node;
	}
}

void	divide_in_b_case3(t_node **a, t_node **b, t_node **in_b, int len)
{
	int cnt;
	int pivot;
	int send;

	cnt = 0;
	pivot = get_pivot(*b, len);
	send = 0;
	while (cnt++ < len)
	{
		if ((*b)->data > pivot && ++send && push(b, a))
			write(1, "pa\n", 3);
		else if ((*b)->data <= pivot && shift_up(b))
			write(1, "rb\n", 3);
	}
	cnt = 0;
	while (cnt++ < (len - send) && shift_down(b))
		write(1, "rrb\n", 4);
	push_front(in_b, len - send);
	divide_in_a(a, b, in_b, send);
}
