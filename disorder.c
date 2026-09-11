#include "push_swap.h"

float	compute_disorder(t_node *head)
{
	int		mistakes;
	int		total_pairs;
	t_node	*read;

	mistakes = 0;
	total_pairs = 0;
	while (head)
	{
		read = head->next;
		while (read)
		{
			total_pairs++;
			if (head->number > read->number)
				mistakes++;
			read = read->next;
		}
		head = head->next;
	}
	return (mistakes * 1.0 / total_pairs);
}
