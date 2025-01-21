/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/21 21:00:20 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->top->value;
	middle = stack_a->top->next->value;
	bottom = stack_a->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		ft_sa(stack_a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_ra(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_rra(stack_a);
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_find_min(stack_a);
	while (stack_a->top->value != min)
		ft_ra(stack_a);
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

void	ft_big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	while (stack_a->size > 0)
	{
		min_pos = ft_find_min_position(stack_a);
		if (min_pos <= stack_a->size / 2)
		{
			while (min_pos--)
				ft_ra(stack_a);
		}
		else
		{
			min_pos = stack_a->size - min_pos;
			while (min_pos--)
				ft_rra(stack_a);
		}
		ft_pb(stack_a, stack_b);
	}
	while (stack_b->size > 0)
		ft_pa(stack_a, stack_b);
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
		{
			ft_sa(stack_a);
			return ;
		}
	}
	else if (stack_a->size == 3)
		ft_sort_3(stack_a);
	else if (stack_a->size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}
