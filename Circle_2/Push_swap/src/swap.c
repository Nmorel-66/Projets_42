/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:26 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/25 17:10:15 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, int w)
{
	t_node	*first;
	t_node	*second;

	if (!a || !a->top || !a->top->next)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	if (w == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int w)
{
	t_node	*first;
	t_node	*second;

	if (!b || !b->top || !b->top->next)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	if (w == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a, 0);
	ft_sb(b, 0);
	write(1, "ss\n", 3);
}
