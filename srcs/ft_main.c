/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:19:10 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:38:37 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		main(int ac, char *av[])
{
	t_node	*a;
	t_node	*b;
	t_node	*in_b;
	int		i;

	a = NULL;
	b = NULL;
	in_b = NULL;
	i = 1;
	if (ac > 1)
		get_input(&a, ac, av);
	else
		print_error();
	if (is_sorted(a))
		return (0);
	divide_in_a(&a, &b, &in_b, size(a));
	free_list(&a);
	free_list(&b);
	free_list(&in_b);
	return (0);
}

void	get_input(t_node **a, int ac, char *av[])
{
	char	**data;
	int		i;

	data = NULL;
	if (ac == 2)
	{
		i = 0;
		data = ft_split(av[1], ' ');
		while (data[i])
			push_back(a, ft_atoi(data[i++]));
		i = 0;
		while (data[i])
			free(data[i++]);
		free(data);
	}
	else
	{
		i = 1;
		while (i < ac)
			push_back(a, ft_atoi(av[i++]));
	}
}

int		is_sorted(t_node *list)
{
	int flag;

	flag = 1;
	while (list->next)
	{
		if (list->data > list->next->data)
			flag = 0;
		list = list->next;
	}
	return (flag);
}

void	free_list(t_node **list)
{
	t_node *tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	(*list) = NULL;
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
