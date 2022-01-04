/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:03:44 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/04 18:07:47 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_isprint(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint('~'));
	return (0);
}
*/
