/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:02:14 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/30 18:21:02 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_stack_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		min_value;

	current = stack->top;
	min_node = NULL;
	min_value = INT_MAX;
	while (current)
	{
		if (current->index == 0 && current->value <= min_value)
		{
			min_value = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	ft_give_index(t_stack *stack)
{
	unsigned int	index;
	t_node			*min_node;

	if (!stack || !stack->top)
		return ;
	index = 1;
	min_node = ft_find_stack_min(stack);
	while ((min_node != NULL))
	{
		min_node->index = index++;
		min_node = ft_find_stack_min(stack);
	}
}
