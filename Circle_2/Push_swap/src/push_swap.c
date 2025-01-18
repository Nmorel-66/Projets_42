/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/18 12:21:58 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			ft_sa(stack_a);
	}
	top = stack_a->top->value;
	middle = stack_a->top->next->value;
	bottom = stack_a->top->next->next->value;
	if (top > middle && middle > bottom)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top > middle && top > bottom && middle < bottom)
		ft_ra(stack_a);
	else if (top > middle && top > bottom && middle > bottom)
		ft_sa(stack_a);
	else if (top < middle && top < bottom && middle > bottom)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (top < middle && top > bottom)
		ft_rra(stack_a);
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_find_min(stack_a);
	while (stack_a->top->value != min)
	{
		if (ft_find_position(stack_a, min) <= stack_a->size / 2)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = ft_find_min(stack_a);
		while (stack_a->top->value != min)
		{
			if (ft_find_position(stack_a, min) <= stack_a->size / 2)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		ft_pb(stack_a, stack_b);
		i++;
	}
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_beyond(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;
	int	median;
	int	i;
	int	size;

	i = 0;
	size = stack_a->size;
	median = size / 2;
	while (i < median)
	{
		min = ft_find_min(stack_a);
		max = ft_find_max(stack_a);
		while (stack_a->top->value != min && stack_a->top->value != max)
		{
			if (ft_find_position(stack_a, min) <= stack_a->size / 2)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		if (stack_a->top->value == min)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		i++;
	}
	ft_sort_3(stack_a);
	while (stack_b->size)
		ft_pa(stack_a, stack_b);
}
