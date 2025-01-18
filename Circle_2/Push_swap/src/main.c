/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:45:23 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/18 12:13:25 by nimorel          ###   ########.fr       */
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
	while (--argc)
		ft_fill_stack(stack_a, ft_atoi(argv[argc]));
	if (is_sorted(stack_a))
		return (0);
	else if (stack_a->size <= 3)
		ft_sort_3(stack_a);
	else if (stack_a->size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (stack_a->size <= 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_sort_beyond(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
/*write(1, "stack a after sort", 19);
	write(1, "\n", 1);
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);*/