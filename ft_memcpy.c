/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:58:37 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/04 19:09:12 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	while (n--)
		*p++ = *q++;
	return (dst);
}

/*
int main(void)
{
	char buf[] = "ABCDDEFG";
	char buf2[] = "123456789";
	// 3バイトだけコピー
	ft_memcpy(buf, buf2, 3);
	//表示
	printf("コピー後のbuf文字列→%s\n", buf);
	return (0);
}
*/
