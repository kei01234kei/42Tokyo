/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:14:29 by keisuke           #+#    #+#             */
/*   Updated: 2022/02/14 03:13:00 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (j < size - 1 && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	while (src[j] != '\0')
		j++;
	return (j);
}

/*
int	main(void)
{
	char	src[] = "keisuke";
	char	dest[256];
	char	test[256];
	size_t	num;

	num = ft_strlcpy(dest, src, 1);
	printf("src: %s, dest: %s, num: %zu\n", src, dest, num);
	num = strlcpy(test, src, 1);
	printf("src: %s, test: %s, num: %zu\n", src, test, num);
	return (0);
}
*/
