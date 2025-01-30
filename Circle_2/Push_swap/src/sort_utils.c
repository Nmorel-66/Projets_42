/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:06:54 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/30 18:36:10 by nimorel          ###   ########.fr       */
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

void	ft_sort_process(t_stack *a, t_stack *b, int bit_pos, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if ((a->top->index & bit_pos) == 0)
			ft_pb(a, b);
		else
			ft_ra(a, 1);
	}
	while (b->size > 0)
		ft_pa(a, b);
}
