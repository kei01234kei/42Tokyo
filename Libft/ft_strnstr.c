/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:44:41 by keisuke           #+#    #+#             */
/*   Updated: 2022/03/09 02:52:12 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
haystackとneedleとどっちもnullだった場合、空文字列が返ってきちゃう。lenがどの数値でも想定されるやつが帰ってきていない。
needleが何も入ってないときの返り値はheystackをそのまま返さないといけない。おれのはnullが帰ってきている。これはlen=0のときのみ成り立つ

*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (len == 0 && needle_len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
