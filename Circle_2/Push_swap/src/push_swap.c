/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/03 10:52:17 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	t_node *current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!ft_arg_checker(argc, argv))
	{
		write(2,"Error\n", 6);
		return (1);
	}
	stack_a = ft_stack_init();
	stack_b = ft_stack_init();
	if (!stack_a || !stack_b)
		return (0);
	while (--argc)
		ft_fill_stack(stack_a, ft_atoi(argv[argc]));
	return (0);
}*/
// programme de test-----------------------------------------
int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	(void)argv;
	(void)argc;
	a = ft_stack_init();
	b = ft_stack_init();
	ft_fill_stack(a, 5);
	ft_fill_stack(a, 10);
	ft_fill_stack(a, 15);
	ft_fill_stack(a, 20);
	ft_fill_stack(b, 30);
	ft_fill_stack(b, 35);
	write(1, "Stack A before operations:\n", 26);
	ft_print_stack(a);
	write(1, "Stack B before operations:\n", 26);
	ft_print_stack(b);
	ft_ra(a);
	write(1, "\nAfter ft_ra (rotate A):\n", 24);
	write(1, "Stack A:\n", 9);
	ft_print_stack(a);
	write(1, "Stack B:\n", 9);
	ft_print_stack(b);
	return 0;
}