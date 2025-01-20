/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/20 09:11:28 by nimorel          ###   ########.fr       */
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

int	ft_find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	ft_get_max_bits(t_stack *stack)
{
	int		max_bits;
	int		max;

	max = ft_find_max(stack);
	max_bits = 0;
	while (max)
	{
		max_bits++;
		max >>= 1;
	}
	return (max_bits);
}

void	ft_shift_stack(t_stack *stack, int shift)
{
	t_node	*current;

    if (!stack || !stack->top)
        return;
    current = stack->top;
    while (current)
    {
        current->value += shift;
        current = current->next;
    }
}