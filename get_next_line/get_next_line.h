/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:05:30 by kishigam          #+#    #+#             */
/*   Updated: 2022/06/12 20:32:03 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 5

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char *get_next_line(int fd);

#endif
