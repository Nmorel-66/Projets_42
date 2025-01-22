/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/22 16:52:31 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	ft_find_min_position(t_stack *stack)
{
	int		min;
	int		min_pos;
	int		current_pos;
	t_node	*current;

	min = stack->top->value;
	min_pos = 0;
	current_pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

int	ft_find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	ft_find_max_position(t_stack *stack)
{
	int		max;
	int		max_pos;
	int		current_pos;
	t_node	*current;

	max = stack->top->value;
	max_pos = 0;
	current_pos = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

int	ft_find_best_move(t_stack *stack)
{
	int	min_pos;
	int	max_pos;
	int	size;
	int	min_operations;
	int	max_operations;

	min_pos = ft_find_min_position(stack);
	max_pos = ft_find_max_position(stack);
	size = stack->size;
	if (min_pos <= size / 2)
		min_operations = min_pos;
	else
		min_operations = size - min_pos;
	if (max_pos <= size / 2)
		max_operations = max_pos;
	else
		max_operations = size - max_pos;
	if (min_operations <= max_operations)
		return (min_pos);
	else
		return (max_pos);
}
