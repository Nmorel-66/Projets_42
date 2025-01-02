/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:26 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 10:21:56 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a) 
{
	t_node *first;
	t_node *second;
	
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b) 
{
	t_node *first;
	t_node *second;
	
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

/* Swap functions
 +--+
 |	|<-- 
 +--+	|
 |	|<-- 
 +--+
 |	|
 +--+
*/