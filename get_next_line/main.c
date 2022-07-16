/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:22:35 by kishigam          #+#    #+#             */
/*   Updated: 2022/07/12 12:33:34 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		rc;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 100);
	fd = open("./text.txt", O_RDONLY);
	// rc = read(fd, buf, 100);
	// printf("%d文字読む(改行文字含む)\n", rc);
	// printf("%s\n", buf);
	// rc = read(fd, buf, 100);
	// printf("%d\n", rc);
	// printf("%s\n", buf);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
