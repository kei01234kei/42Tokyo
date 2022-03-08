/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:14:29 by keisuke           #+#    #+#             */
/*   Updated: 2022/02/15 07:14:47 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	if (size == 0)
		return (size);
	else
	{
		if (i < size)
			j = i;
		else
			j = size - 1;
	}
	ft_memcpy(dest, src, j);
	dest[j] = '\0';
	return (i);
}
