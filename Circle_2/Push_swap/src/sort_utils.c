/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/23 20:52:55 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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

void	ft_push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	chunk_max;
	int	pushed;
	int	current;

	chunk_max = chunk_size;
	pushed = 0;
	while (stack_a->size > 0)
	{
		current = stack_a->top->value;
		if (current <= chunk_max)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
			if (current > chunk_max - (chunk_size / 2))
				ft_rb(stack_b, 1);
		}
		else
			ft_ra(stack_a, 1);
		if (pushed == chunk_size)
		{
			chunk_max += chunk_size;
			pushed = 0;
		}
	}
}
