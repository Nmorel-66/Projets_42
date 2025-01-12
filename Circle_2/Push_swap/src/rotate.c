/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:13:34 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/12 16:49:53 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*bottom;

	if (!a || !a->top || !a->top->next)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	bottom = a->top;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*bottom;

	if (!b || !b->top || !b->top->next)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	bottom = b->top;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	write(1, "rr\n", 3);
}
