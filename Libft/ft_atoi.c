/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:26:37 by keisuke           #+#    #+#             */
/*   Updated: 2022/03/10 09:12:47 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	add_safety(long a, long b)
{
	if ((a > 0) && (b > (LONG_MAX - a)))
		return (LONG_MAX);
	if ((a < 0) && (b < (LONG_MIN - a)))
		return (LONG_MIN);
	return (a + b);
}

static long	mul_safety(long a, long b)
{
	if ((a > 0) && (a > (LONG_MAX / b)))
		return (LONG_MAX);
	if ((a < 0) && (a < (LONG_MIN / b)))
		return (LONG_MIN);
	return (a * b);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = mul_safety(num, 10);
		num = add_safety(num, (str[i++] - '0') * sign);
		if (sign == 1 && num == LONG_MAX)
			return ((int)LONG_MAX);
		if (sign == -1 && num == LONG_MIN)
			return ((int)LONG_MIN);
	}
	return (num);
}
