/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimorel <nimorel <marvin@42.fr> >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:47:31 by nimorel           #+#    #+#             */
/*   Updated: 2025/01/02 10:17:32 by nimorel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

/* Structures */
typedef struct	s_node 
{
	int value;
	struct s_node *next;
}	t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
}	t_stack;

/* Operations */

void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ftrr(t_stack *a, t_stack *b);
void	rr_a(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

/* Stack */
void		ft_fill_stack(t_stack *stack, int value);
t_stack		*ft_stack_init(void);
t_node		*ft_create_node(int value);

/* Utils */
int			ft_atoi(const char *nptr);

/* Push Swap */
void		push_swap(t_stack *stack_a, t_stack *stack_b);


/* Checker */
int ft_arg_checker(int argc, char **argv);
int is_duplicate(int argc, char **argv);
int ft_is_valid_int(char *str);



#endif