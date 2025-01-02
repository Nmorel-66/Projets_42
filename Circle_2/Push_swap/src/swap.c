/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:26 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 08:18:20 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a) 
{
	t_node *first;
	t_node *second;
	
	if (a->size < 2) 
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
}

void	sb(t_stack *b) 
{
	t_node *first;
	t_node *second;
	
	if (b->size < 2)	
		return ; 
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}