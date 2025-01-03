/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:11 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/03 09:30:11 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node *bottom;
	t_node *penultimate;

	if (!a || !a->top || !a->top->next)
		return ;
	penultimate = a->top;
	while (penultimate->next && penultimate->next->next)
		penultimate = penultimate->next;
	bottom = penultimate->next;
	penultimate->next = NULL;
	bottom->next = a->top;
	a->top = bottom;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	t_node *bottom;
	t_node *penultimate;

	if (!b || !b->top || !b->top->next)
		return ;
	penultimate = b->top;
	while (penultimate->next && penultimate->next->next)
		penultimate = penultimate->next;
	bottom = penultimate->next;
	penultimate->next = NULL;
	bottom->next = b->top;
	b->top = bottom;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a);
	ft_rrb(b);
	write(1, "rrr\n", 4);
}
// penultimate -> avant dernier