/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/26 19:54:18 by nimorel          ###   ########.fr       */
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
		ft_sa(stack_a, 1);
	else if (top > middle && middle > bottom && top > bottom)
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_ra(stack_a, 1);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_sa(stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_rra(stack_a, 1);
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = ft_find_min_position(stack_a);
	if (min_pos == 1)
		ft_ra(stack_a, 1);
	else if (min_pos == 2)
	{
		ft_ra(stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if (min_pos == 3)
		ft_rra(stack_a, 1);
	if (is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = ft_find_min_position(stack_a);
	if (min_pos == 1)
		ft_ra(stack_a, 1);
	else if (min_pos == 2)
	{
		ft_ra(stack_a, 1);
		ft_ra(stack_a, 1);
	}
	else if (min_pos == 3)
	{
		ft_rra(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	else if (min_pos == 4)
		ft_rra(stack_a, 1);
	if (is_sorted(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_4(stack_a, stack_b);
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
			ft_sa(stack_a, 1);
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
		ft_radix_sort(stack_a, stack_b);
}

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit_pos;
	int	count;
	int	size;
	int	offset;

	offset = ft_find_min(stack_a);
	if (offset < 0)
		offset = -offset;
	else
		offset = 0;
	ft_offset(stack_a, offset, 1);
	size = stack_a->size;
	bit_pos = 1;
	while (is_sorted(stack_a) == 0)
	{
		count = 0;
		while (stack_a != NULL && count++ < size)
		{
			if ((stack_a->top->value & bit_pos) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a, 1);
		}
		while (stack_b->size > 0)
			ft_pa(stack_a, stack_b);
		bit_pos = bit_pos << 1;
	}
	ft_offset(stack_a, offset, 0);
}
