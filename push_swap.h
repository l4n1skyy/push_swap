/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:33:58 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 23:54:12 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* strategy selector */
# define STRATEGY_ADAPTIVE 0
# define STRATEGY_SIMPLE   1
# define STRATEGY_MEDIUM   2
# define STRATEGY_COMPLEX  3

/* struct */
typedef struct s_node
{
	int				number;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* benchmark struct */
typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

/* make life easier */
typedef struct s_chunk_info
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_bench	*bench;
	int		n_bucket;
	int		n_node;
	int		target;
}	t_chunk_info;

/* algorithms */
void	simple_sort(t_node **head, int limit, t_bench *bench);
void	medium_sort(t_node **head, t_bench *bench);
void	complex_sort(t_node **head, t_bench *bench);
int		sort_small(t_node **a, int limit, t_bench *bench);

/* doubly linked list functions */
t_node	*ft_llstnew(int number);
void	ft_llstaddback(t_node **head, t_node *node);
void	ft_llstclear(t_node **head);
int		ft_llstsize(t_node *head);

/* operations */
void	pa(t_node **b, t_node **a, t_bench *bench);
void	pb(t_node **a, t_node **b, t_bench *bench);
void	ra(t_node **a, t_bench *bench);
void	rb(t_node **b, t_bench *bench);
void	rr(t_node **a, t_node **b, t_bench *bench);
void	sa(t_node **a, t_bench *bench);
void	sb(t_node **b, t_bench *bench);
void	ss(t_node **a, t_node **b, t_bench *bench);
void	rra(t_node **a, t_bench *bench);
void	rrb(t_node **b, t_bench *bench);
void	rrr(t_node **a, t_node **b, t_bench *bench);

/* parsing */
int		parse_strategy(char *arg);
char	**parse_options(char **argv, int *strategy, int *benchmark);
int		select_strategy(t_node **head, int strategy, float disorder,
			t_bench *bench);
int		is_valid_number(char *str);
int		check_duplicate(t_node *head);
int		is_in_range(char *str);
long	ft_atoi_long(char *str);
t_node	*create_struct(char **argv);

/* benchmarking */
float	compute_disorder(t_node *head);
void	print_benchmark(t_bench *bench, float disorder, int strategy,
			int used_strategy);
void	print_disorder(float disorder);
void	print_total_operations(t_bench *bench);
void	print_swap_push(t_bench *bench);
void	print_rotate_rrotate(t_bench *bench);
void	print_strategy(int strategy, int used_strategy);

/* error handling */
int		handle_error(void);
t_node	*handle_fail(t_node **head);

#endif
