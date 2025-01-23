/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:11 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/23 09:09:00 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, int w)
{
	t_node	*penultimate;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	penultimate = NULL;
	last = a->top;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	if (penultimate)
		penultimate->next = NULL;
	last->next = a->top;
	a->top = last;
	if (w)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, int w)
{
	t_node	*penultimate;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	penultimate = NULL;
	last = b->top;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	if (penultimate)
		penultimate->next = NULL;
	last->next = b->top;
	b->top = last;
	if (w)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, 0);
	ft_rrb(b, 0);
	write(1, "rrr\n", 4);
}
// penultimate -> avant dernier