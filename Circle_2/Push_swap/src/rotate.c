/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:13:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 17:40:53 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node *old_top;
	t_node *last_node;
	
	if (!a || !a->top || !a->top->next)
		return ;
	old_top = a->top; 
	a->top = old_top->next;
	last_node = a->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = old_top;
	old_top->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	t_node *old_top;
	t_node *last_node;
	
	if (!b || !b->top || !b->top->next)
		return ;
	old_top = b->top;
	b->top = old_top->next;
	last_node = b->top;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = old_top;
	old_top->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}