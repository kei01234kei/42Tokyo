/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kishigam <kishigam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:17:15 by kishigam          #+#    #+#             */
/*   Updated: 2022/10/21 08:07:47 by kishigam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*next_indexed_elem(t_stack **stack)
{
	int		is_beginning;
	t_stack	*head;
	t_stack	*min; // この変数の存在意義がよくわからない。けどこの変数めっちゃ大切な気がする

	min = NULL;
	is_beginning = 0; // 変数current_minの存在意義がよくわからんし、なぜ初期値に0を設定したのかもわからない。boolean用？？
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->i == -1) // ここからの処理よくわからんから先にすすむ
				&& (!is_beginning || head->value < min->value)) // なぜhead->value < min->valueという条件が必要なのか
			{
				min = head;
				is_beginning = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	stack_indexing(t_stack **stack)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = next_indexed_elem(stack);
	while (head)
	{
		head->i = i++;
		head = next_indexed_elem(stack);
	}
}

void	stack_init(t_stack **stack, int argc, char **argv)
{
	int		i;
	char	**args;
	t_stack	*new;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = create_new_node(ft_atol(args[i]));
		add_node_back(stack, new);
		i++;
	}
	stack_indexing(stack);
	if (argc == 2)
		free(args);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	stack_size(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
