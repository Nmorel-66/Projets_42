/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/15 18:21:23 by nimorel          ###   ########.fr       */
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

void	ft_sort_3(t_stack *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
	}
	else if (stack_a->size == 3)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
		ft_ra(stack_a);
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
		ft_rra(stack_a);
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
	}
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	while (i < 2)
	{
		min = ft_find_min(stack_a);
		max = ft_find_max(stack_a);
		while (stack_a->top->value != min && stack_a->top->value != max)
			ft_ra(stack_a);
		if (stack_a->top->value == min || stack_a->top->value == max)
			ft_pb(stack_a, stack_b);
		i++;
	}
	ft_sort_3(stack_a);
	ft_sort_3(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_ra(stack_a);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;
	int	num;

	size = stack_a->size;
	max_bits = ft_get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->top->value;
			if ((num >> i) & 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size)
			ft_pa(stack_a, stack_b);
		i++;
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
	while (--argc)
		ft_fill_stack(stack_a, ft_atoi(argv[argc]));
	if (is_sorted(stack_a))
		return (0);
	else if (stack_a->size <= 3)
		ft_sort_3(stack_a);
	else if (stack_a->size <= 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
	write(1, "stack a after sort", 19);
	write(1, "\n", 1);
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
