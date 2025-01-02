/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:13:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 10:22:41 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node *tmp;
	t_node *current;
	
	tmp = a->top; 
	a->top = tmp->next;
	current = a->top;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	t_node *tmp;
	t_node *current;
	
	tmp = b->top;
	b->top = tmp->next;
	current = b->top;
	while (current->next)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}