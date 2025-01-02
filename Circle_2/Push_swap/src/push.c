/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:02:49 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 10:22:12 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	tmp = b->top;
	b->top = tmp->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	t_node *tmp;

	tmp = a->top;
	a->top = tmp->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	write(1, "pb\n", 3);
}