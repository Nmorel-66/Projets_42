/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:11 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/01 20:40:37 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node *tmp;
	t_node *current;

	if (!a || !a->top || a->size < 2)
		return ;
	current = a->top;
	while (current->next && current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
}

void	rrb(t_stack *b)
{
	t_node *tmp;
	t_node *current;

	if (!b || !b->top || b->size < 2)
		return ;
	current = b->top;
	while (current->next && current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = b->top;
	b->top = tmp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}