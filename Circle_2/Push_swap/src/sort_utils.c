/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/25 18:08:34 by nimorel          ###   ########.fr       */
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

void	ft_move_to_top(t_stack *stack, int pos)
{
	if (pos == 0)
		return ;
	if (pos <= stack->size / 2)
	{
		while (pos > 0)
		{
			ft_ra(stack, 1);
			pos--;
		}
	}
	else
	{
		while (pos < stack->size)
		{
			ft_rra(stack, 1);
			pos++;
		}
	}
}

void	ft_push_best_to_b(t_stack *stack_a, t_stack *stack_b)
{
	char	best;
	char	next_best;

	best = ft_best_move(stack_a);
	if (best == 'm')
	{
		ft_move_to_top(stack_a, ft_find_min_position(stack_a));
		ft_pb(stack_a, stack_b);
	}
	else
	{
		ft_move_to_top(stack_a, ft_find_max_position(stack_a));
		ft_pb(stack_a, stack_b);
		//ft_rb(stack_b, 1);
		next_best = ft_best_move(stack_a);
		if (next_best == 'm' && stack_a->top->value != ft_find_min(stack_a))
			ft_rr(stack_a, stack_b);
		else
			ft_rb(stack_b, 1);
	}
}

char	ft_best_move(t_stack *stack_a)
{
	int	min_pos;
	int	max_pos;
	int	cost_min;
	int	cost_max;

	min_pos = ft_find_min_position(stack_a);
	max_pos = ft_find_max_position(stack_a);

	if (min_pos <= stack_a->size / 2)
		cost_min = min_pos;
	else
		cost_min = stack_a->size - min_pos;

	if (max_pos <= stack_a->size / 2)
		cost_max = max_pos;
	else
		cost_max = stack_a->size - max_pos;

	if (cost_min <= cost_max)
		return ('m');
	return ('M');
}

