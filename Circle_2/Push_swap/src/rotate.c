/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:13:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/01 18:29:46 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node *tmp;
	t_node *current;
	
	if (!a || !a->top || a->size < 2)
		return;
	tmp = a->top; 
	a->top = tmp->next;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}

void	rb(t_stack *b)
{
	t_node *tmp;
	t_node *current;
	
	if (!b || !b->top || b->size < 2)
		return;
	tmp = b->top;
	b->top = tmp->next;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}