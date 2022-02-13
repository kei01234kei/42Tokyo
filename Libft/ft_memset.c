/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:14:41 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/04 20:54:49 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

/*
int	main(void)
{
	char buf[] = "ABCDEFGHIJK";
	//先頭から2バイト進めた位置に「１」を3バイト書き込む
	ft_memset(buf + 2, '1', 3);
	//表示
	printf("buf文字列→%s\n", buf);
	return 0;
}
*/
