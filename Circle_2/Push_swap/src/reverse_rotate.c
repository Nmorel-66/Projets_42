/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:23:11 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 10:23:01 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	t_node *tmp;
	t_node *current;

	current = a->top;
	while (current->next && current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b)
{
	t_node *tmp;
	t_node *current;

	current = b->top;
	while (current->next && current->next->next)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}