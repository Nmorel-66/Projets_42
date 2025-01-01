/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:26 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/01 20:30:46 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a) 
{
	t_node *first;
	t_node *tmp;
	
	if (a->size < 2) 
		return ;
	first = a->top;
	tmp = first->next;
	first->next = tmp->next;
	tmp->next = first;
	a->top = tmp;
}

void	sb(t_stack *b) 
{
	t_node *first;
	t_node *tmp;
	
	if (b->size < 2)	
		return ; 
	first = b->top;
	tmp = first->next;
	first->next = tmp->next;
	tmp->next = first;
	b->top = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}