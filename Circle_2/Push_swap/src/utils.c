/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:52:18 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/23 10:01:58 by nimorel          ###   ########.fr       */
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

void	ft_move_to_top(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
	{
		while (pos--)
			ft_ra(stack, 1);
	
	}
	else
	{
		pos = stack->size - pos;
		while (pos--)
			ft_rra(stack, 1);
	}
}