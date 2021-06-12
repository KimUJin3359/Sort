/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojikim <woojikim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 20:54:52 by woojikim          #+#    #+#             */
/*   Updated: 2021/06/12 20:55:12 by woojikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_atoi(const char *str)
{
	long long	sign;
	long long	res;
	int			idx;

	sign = 1;
	res = 0;
	idx = 0;
	if (!str)
		return (res);
	if (str[idx] == '+')
		idx++;
	else if (str[idx] == '-')
	{
		idx++;
		sign = -1;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
		res = res * 10 + (str[idx++] - '0');
	res *= sign;
	if (!ft_strlen(str) || str[idx] != '\0' ||
			res > 2147483647 || res < -2147483648)
		print_error();
	return ((int)res);
}
