/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:16:05 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/25 18:03:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_args(t_stack *stack_a, int argc, char **argv)
{
	char	**splitted_args;
	int		i;

	if (argc == 2)
	{
		splitted_args = ft_split(argv[1], ' ');
		if (!splitted_args)
			return ;
		i = 0;
		while (splitted_args[i] != NULL)
			i++;
		while (--i >= 0)
			ft_fill_stack(stack_a, ft_atoi(splitted_args[i]));
		ft_free(splitted_args);
	}
	else
	{
		while (--argc)
			ft_fill_stack(stack_a, ft_atoi(argv[argc]));
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_arg_checker(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = ft_stack_init();
	stack_b = ft_stack_init();
	if (!stack_a || !stack_b)
		return (0);
	ft_args(stack_a, argc, argv);
	if (stack_a->size < 2 || is_sorted(stack_a))
		return (0);
	ft_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
/* impression des stack
if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
write(1, "stack a after sort", 19);
	write(1, "\n", 1);
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);*/