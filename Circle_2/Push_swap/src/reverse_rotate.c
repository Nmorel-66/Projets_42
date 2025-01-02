/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:11 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 17:42:38 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node *last_node;
	t_node *penultimate_node;

	if (!a || !a->top || !a->top->next)
		return ;
	penultimate_node = a->top;
	while (penultimate_node->next && penultimate_node->next->next)
		penultimate_node = penultimate_node->next;
	last_node = penultimate_node->next;
	penultimate_node->next = NULL;
	last_node->next = a->top;
	a->top = last_node;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	t_node *last_node;
	t_node *penultimate_node;

	if (!b || !b->top || !b->top->next)
		return ;
	penultimate_node = b->top;
	while (penultimate_node->next && penultimate_node->next->next)
		penultimate_node = penultimate_node->next;
	last_node = penultimate_node->next;
	penultimate_node->next = NULL;
	last_node->next = b->top;
	b->top = last_node;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
// penultimate -> avant dernier