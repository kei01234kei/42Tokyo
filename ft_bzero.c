/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:25:34 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/04 18:58:56 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)0;
	return (*s);
}

/*
int	main(void)
{
	char buf[] = "ABCDEFGHIJK";
	ft_bzero(buf + 2, 3);
	//表示
	printf("buf文字列→%s\n", buf);
	return 0;
}
*/
