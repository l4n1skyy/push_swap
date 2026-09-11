#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* struct */
typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* main functions */
t_node *create_struct(char **argv);
float	compute_disorder(t_node *head);

/* doubly linked list functions */
t_node	*ft_llstnew(int number);
void	ft_llstaddback(t_node **head, t_node *node);
void	ft_llstclear(t_node **head);
int		ft_llstsize(t_node *head);

/* operations */
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* other utils */
t_node *handle_fail(t_node **head);

#endif
