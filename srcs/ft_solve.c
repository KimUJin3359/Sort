/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:19:31 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:22:04 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	solve_3_only(t_node **list, int max, int min)
{
	if (max == 1 && min == 2 && shift_down(list) && swap(list))
		write(1, "rra\nsa\n", 7);
	else if (max == 2 && min == 3 && swap(list))
		write(1, "sa\n", 3);
	else if (max == 2 && min == 1 && shift_down(list))
		write(1, "sa\n", 3);
	else if (max == 3 && min == 2 && shift_up(list))
		write(1, "ra\n", 3);
	else if (max == 3 && min == 1 && shift_up(list) && swap(list))
		write(1, "ra\nsa\n", 6);
}

void	solve_3(t_node **list, int max, int min)
{
	if (max == 1 && min == 2 &&
			shift_up(list) && swap(list) && shift_down(list))
		write(1, "ra\nsa\nrra\n", 10);
	else if (max == 2 && min == 3 && swap(list))
		write(1, "sa\n", 3);
	else if (max == 2 && min == 1 &&
			shift_up(list) && swap(list) && shift_down(list) && swap(list))
		write(1, "ra\nsa\nrra\nsa\n", 13);
	else if (max == 3 && min == 2 &&
			swap(list) && shift_up(list) && swap(list) && shift_down(list))
		write(1, "sa\nra\nsa\nrra\n", 13);
	else if (max == 3 && min == 1 && swap(list) &&
			shift_up(list) && swap(list) && shift_down(list) && swap(list))
		write(1, "sa\nra\nsa\nrra\nsa\n", 16);
}

int		solve_less_than_3(t_node **list, int num)
{
	int len;
	int max;
	int min;

	len = size(*list);
	if (num == 2)
	{
		if ((*list)->data > (*list)->next->data && swap(list))
			write(1, "sa\n", 3);
	}
	else if (num == 3)
	{
		max = get_min(*list);
		min = get_max(*list);
		if (len <= 3)
			solve_3_only(list, max, min);
		else
			solve_3(list, max, min);
	}
	return (1);
}

void	divide_in_a(t_node **a, t_node **b, t_node **in_b, int len)
{
	int pivot;
	int cnt;
	int send;

	pivot = get_pivot(*a, len);
	cnt = 0;
	send = 0;
	if (len <= 3 && solve_less_than_3(a, len) && divide_in_b(a, b, in_b))
		return ;
	while (cnt++ < len)
	{
		if ((*a)->data <= pivot && ++send && push(a, b))
			write(1, "pb\n", 3);
		else if ((*a)->data > pivot && shift_up(a))
			write(1, "ra\n", 3);
	}
	cnt = 0;
	if (size(*a) != len - send)
		while (cnt++ < len - send && shift_down(a))
			write(1, "rra\n", 4);
	push_front(in_b, send);
	if (len - send > 3)
		divide_in_a(a, b, in_b, len - send);
	else if (len - send <= 3 && solve_less_than_3(a, len - send))
		divide_in_b(a, b, in_b);
}

int		divide_in_b(t_node **a, t_node **b, t_node **in_b)
{
	int len;
	int send;
	int cnt;

	if (!size(*in_b))
		return (1);
	len = pop(in_b);
	send = 0;
	cnt = 0;
	if (len <= 3)
	{
		while (cnt++ < len && ++send && push(b, a))
			write(1, "pa\n", 3);
		divide_in_a(a, b, in_b, send);
	}
	else
		divide_in_b_case3(a, b, in_b, len);
	while (size(*in_b))
		divide_in_b(a, b, in_b);
	return (1);
}
