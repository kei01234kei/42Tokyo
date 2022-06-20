/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:15:22 by kishigam          #+#    #+#             */
/*   Updated: 2022/06/16 17:47:35 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 3);
	fd = open("./text.txt", O_RDONLY);
	close(fd);
}
