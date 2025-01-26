/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/26 19:50:08 by nimorel          ###   ########.fr       */
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

void	ft_offset(t_stack *stack, int offset, int add)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (add)
			current->value = current->value + offset;
		else
			current->value = current->value - offset;
		current = current->next;
	}
}
