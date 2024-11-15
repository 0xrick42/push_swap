/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhomsi <ykhomsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:57:17 by ykhomsi           #+#    #+#             */
/*   Updated: 2024/11/08 23:57:44 by ykhomsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	handle_spaces_sign(const char *str, int *sign)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		sign_count++;
		if (sign_count > 1)
			error_exit();
		i++;
	}
	if (!str[i])
		error_exit();
	return (i);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;
	int		digit_count;

	sign = 1;
	result = 0;
	digit_count = 0;
	i = handle_spaces_sign(str, &sign);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit();
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			error_exit();
		digit_count++;
		if (digit_count > 10)
			error_exit();
		i++;
	}
	return (result * sign);
}
