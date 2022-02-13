/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:51:13 by keisuke           #+#    #+#             */
/*   Updated: 2022/01/13 23:31:13 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	if (size < j)
		return (i + size);
	else
	{
		while (src[k] != '\0' && k + 1 < size - j)
		{
			dest[j + k] = src[k];
			k++;
		}
		dest[j + k] = '\0';
	}
	return (i + j);
}


int	main(void)
{
	char	first_name[30] = "keisuke";
	char	last_name[] = "ishigami";
	unsigned int	num = ft_strlcat(first_name, last_name, 11);
	printf("%s\n", first_name);
	printf("%d\n", num);
	return (0);
}
