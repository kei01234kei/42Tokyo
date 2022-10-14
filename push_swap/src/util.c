/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:08:18 by kishigam          #+#    #+#             */
/*   Updated: 2022/10/15 07:43:48 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	write_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

int	is_numeric(char *c)
{
	int	i;

	i = 0;
	if (c[i] == '-')
		i++;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (0);
		i++;
	}
	return (1);
}

int	exist_duplicates(char **args, long tmp, size_t i)
{
	i++;
	while (args[i])
	{
		if (ft_atol(args[i] == tmp))
			return (1);
		i++;
	}
	return (0);
}

int	arg_check(int argc, char **argv)
{
	size_t		i;
	char		**args;
	long		tmp;

	i = 0;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		args = ft_split(argv[1], ' '); // なぜ' 'でsplitしているかは未解明
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!is_numeric(args[i]))
			write_error("Error");
		if (exist_duplicates(args, tmp, i))
			write_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			error_message("Error");
		i++;
	}
	if (argc == 2)
		free(args); // なぜargc==のときだけfreeしているのかは未解明
}
