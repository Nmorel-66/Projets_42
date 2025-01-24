/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:47:31 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/24 10:46:59 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "../Libft/libft.h"

/* Structures */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

/* Operations */
void	ft_ra(t_stack *a, int w);
void	ft_rb(t_stack *b, int w);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a, int w);
void	ft_rrb(t_stack *b, int w);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a, int w);
void	ft_sb(t_stack *b, int w);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

/* Stack utils */
void	ft_fill_stack(t_stack *stack, int value);
t_stack	*ft_stack_init(void);
t_node	*ft_create_node(int value);
void	ft_print_stack(t_stack *stack);
void	ft_free_stack(t_stack *stack);

/* Sort Utils */
int		ft_find_min(t_stack *stack);
int		ft_find_min_position(t_stack *stack);
int		ft_find_max(t_stack *stack);
int		ft_find_max_position(t_stack *stack);
void	ft_move_to_top(t_stack *stack, int pos);
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk);
void	ft_free(char **str);

/* Main */
int		is_sorted(t_stack *stack);
void	ft_args(t_stack *stack_a, int argc, char **argv);
int		main(int argc, char **argv);

/* Sort */
void	ft_sort_3(t_stack *stack_a);
void	ft_sort_4(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_5(t_stack *stack_a, t_stack *stack_b);
void	ft_big_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_sort(t_stack *stack_a, t_stack *stack_b);

/* Checker */
int		ft_arg_checker(int argc, char **argv);
int		is_duplicate(int argc, char **argv);
int		is_valid_int(char *str);

#endif