/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:58:58 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/04 18:04:37 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('~'));
	return (0);
}
*/
