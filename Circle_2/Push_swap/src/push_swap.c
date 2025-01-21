/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:50:04 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/21 14:59:57 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->top->value;
	middle = stack_a->top->next->value;
	bottom = stack_a->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		ft_sa(stack_a);
	else if (top > middle && middle > bottom && top > bottom)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_ra(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_rra(stack_a);
}

void	ft_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = ft_find_min(stack_a);
	while (stack_a->top->value != min)
		ft_ra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = ft_find_min(stack_a);
		while (stack_a->top->value != min)
		{
			if (ft_find_position(stack_a, min) <= stack_a->size / 2)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		ft_pb(stack_a, stack_b);
		i++;
	}
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int max_bits;
    int i;
    int j;
    int size;
    int num;
    int min;

    if (!stack_a || !stack_b || stack_a->size == 0)
        return;
    size = stack_a->size;
    min = ft_find_min(stack_a);
    ft_offset(stack_a, -min);
    max_bits = ft_get_max_bits(stack_a);

    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size )
        {
            num = stack_a->top->value;
            if ((num >> i) & 1)
			{
				if (ft_find_position(stack_a, num) <= stack_a->size / 2)
					ft_ra(stack_a);
				else
					ft_rra(stack_a);
				//ft_ra(stack_a);
			}
            else
                ft_pb(stack_a, stack_b);
            j++;
        }
        while (stack_b->size)
           ft_pa(stack_a, stack_b);
		i++;
    }
    ft_offset(stack_a, min);
}
/********************************* */
void ft_tab_sort(int *tab, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int *ft_stack_in_tab(t_stack *stack)
{
	int *tab;
	t_node *current;
	int i;

	tab = (int *)malloc(sizeof(int) * stack->size);
	if (!tab)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return (tab);
}

void ft_faster_rot(t_stack *stack, int index)
{
    if (index < 0 || index >= stack->size)
        return;
    if (index <= stack->size / 2)
    {
        while (index-- > 0)
            ft_ra(stack);
    }
    else
    {
        index = stack->size - index;
        while (index-- > 0)
            ft_rra(stack);
    }
}

void ft_big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int *sorted_tab;
	int chunk_size;
	int total_chunks;
	int i;
	int j;
	int lower_index;
	int upper_index;
	int num;
	int max;

	sorted_tab = ft_stack_in_tab(stack_a);
	ft_tab_sort(sorted_tab, stack_a->size);
	if (stack_a->size <= 100)
		total_chunks = 5;
	else
		total_chunks = 10;
	chunk_size = stack_a->size / total_chunks;
	i = 0;
    while (i < total_chunks)
    {
    	lower_index = i * chunk_size;
    	if (i == total_chunks - 1)
        	upper_index = stack_a->size;
		else
        	upper_index = (i + 1) * chunk_size;
        j = 0;
        while (j < stack_a->size)
        {
            num = stack_a->top->value;
            if (num >= sorted_tab[lower_index] && num < sorted_tab[upper_index])
            {
                ft_pb(stack_a, stack_b);
            }
            else
            {
                ft_ra(stack_a);
            }
            j++;
        }
        i++;
    }
    while (stack_b->size > 0)
    {
        max = ft_find_max(stack_b);
        ft_faster_rot(stack_b, ft_find_position(stack_b, max));
        ft_pa(stack_a, stack_b);
    }
    free(sorted_tab);
}
/*************************************** */

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
		{
			ft_sa(stack_a);
			return ;
		}
	}
	else if (stack_a->size == 3)
		ft_sort_3(stack_a);
	else if (stack_a->size == 4)
		ft_sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_big_sort(stack_a, stack_b);
}
