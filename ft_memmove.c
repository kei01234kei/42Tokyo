/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:10:40 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/05 18:04:27 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)dst;
	q = (unsigned char *)src;
	if (p < q)
		while (n--)
			*p++ = *q++;
	else
		while (n--)
			*(p + n) = *(q + n);
	return (dst);
}

/*
int main(void)
{
	char buf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// bufの先頭から3バイト進めた位置にbufの先頭から3バイトコピー
	ft_memmove(buf + 3, buf, 8);
	//表示
	printf("コピー後のbuf文字列→%s\n", buf);
	return (0);
}
*/
