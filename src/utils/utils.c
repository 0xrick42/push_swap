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

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
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
	if (!str[i])
		error_exit();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		digit_count++;
		if (digit_count > 10 || (sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			error_exit();
		i++;
	}
	if (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
		error_exit();
	return (result * sign);
}
