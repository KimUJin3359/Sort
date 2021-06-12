/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:19:26 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:22:21 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	merge(int *src, int *dest, int left, int right)
{
	int mid;
	int index_l;
	int index_r;
	int index_b;
	int idx;

	mid = (left + right) / 2;
	index_l = left;
	index_r = mid + 1;
	index_b = left;
	idx = -1;
	while (index_l <= mid && index_r <= right)
	{
		if (src[index_l] < src[index_r])
			dest[index_b++] = src[index_l++];
		else
			dest[index_b++] = src[index_r++];
	}
	while (index_l <= mid)
		dest[index_b++] = src[index_l++];
	while (index_r <= right)
		dest[index_b++] = src[index_r++];
	while (++idx <= (right - left))
		src[left + idx] = dest[left + idx];
}

void	partition(int *src, int *dest, int left, int right)
{
	int mid;

	mid = (left + right) / 2;
	if (left < right)
	{
		partition(src, dest, left, mid);
		partition(src, dest, mid + 1, right);
		merge(src, dest, left, right);
	}
}

int		get_pivot(t_node *list, int len)
{
	int *num;
	int *sorted;
	int i;
	int res;

	num = (int *)malloc(sizeof(int) * len);
	sorted = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		num[i++] = list->data;
		list = list->next;
	}
	partition(num, sorted, 0, len - 1);
	free(num);
	res = sorted[(len / 2) - 1];
	free(sorted);
	return (res);
}

int		get_max(t_node *list)
{
	if (list->data > list->next->data && list->data > list->next->next->data)
		return (1);
	else if (list->next->data > list->data &&
			list->next->data > list->next->next->data)
		return (2);
	else
		return (3);
}

int		get_min(t_node *list)
{
	if (list->data < list->next->data && list->data < list->next->next->data)
		return (1);
	else if (list->next->data < list->data &&
			list->next->data < list->next->next->data)
		return (2);
	else
		return (3);
}
