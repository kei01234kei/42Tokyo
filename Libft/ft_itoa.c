/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:21:17 by keisuke           #+#    #+#             */
/*   Updated: 2022/03/09 11:58:19 by keisuke          ###   ########.fr       */
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

static void	change_mark(char *str, long int *nb)
{
	str[0] = '-';
	*nb = *nb * -1;
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = digit_count(nb);
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = 0;
	if (nb == 0)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = 48;
	}
	if (nb < 0)
		change_mark(str, &nb);
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
