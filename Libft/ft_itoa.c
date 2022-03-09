/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:21:17 by keisuke           #+#    #+#             */
/*   Updated: 2022/03/09 11:41:03 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	digit;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	digit = ft_get_digit(n);
	str = (char *)malloc((digit + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[digit - 1] = n % 10 * sign + '0';
		n /= 10;
		digit --;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
