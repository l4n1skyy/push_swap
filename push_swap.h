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

/* doubly linked list functions */
t_node	*ft_llstnew(int number);
void	ft_llstaddback(t_node **head, t_node *node);
void	ft_llstclear(t_node **head);

/* other utils */
t_node *handle_fail(t_node **head);

#endif
