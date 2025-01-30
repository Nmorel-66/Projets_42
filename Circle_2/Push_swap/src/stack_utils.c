/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:56:44 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/30 18:13:27 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_fill_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = ft_create_node(value);
	if (!new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (!tmp)
	{
		write(1, "Empty\n", 6);
		return ;
	}
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack);
}
