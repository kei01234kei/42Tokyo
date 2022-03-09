/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisuke <keisuke.130@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:07:47 by keisuke           #+#    #+#             */
/*   Updated: 2022/03/09 08:16:17 by keisuke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	div_counter(char const *s, char c)
{
	int i;
	int counter;

	counter = 0;
	if (s[0] && s[0] != c)
		counter++;
	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			counter++;
		i++;
	}
	return (counter);
}

static char *segmentator(char const *s, char c, int i)
{
	int		j;
	int		k;
	char	*str;

	j = i;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * ((i - j) + 1));
	if (!str)
		return (NULL);
	k = 0;
	while (j != i)
	{
		str[k] = s[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (div_counter(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (i <= (int)ft_strlen(s) && div_counter(s, c))
	{
		if (ft_strlen(segmentator(s, c, i)))
		{
			array[j] = segmentator(s, c, i);
			i += (ft_strlen(array[j]) + 1);
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
