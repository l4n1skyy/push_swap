#include "push_swap.h"

static void flush(t_node **stack_a, t_node **stack_b, t_bench *bench);
static int get_bit_count(int max_rank);

void	radix_sort(t_node **head, t_bench *bench)
{
	int	size;
	int	max_bits;

	size = ft_llstsize(*head);
	max_bits = get_bit_count(size - 1);

	t_node *stack_a = *head;
	t_node *stack_b = NULL;

	int i = 0;
	int j = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((stack_a->rank >> i) & 1)
				ra(&stack_a, bench);
			else
				pb(&stack_a, &stack_b, bench);
			j++;
		}
		flush(&stack_a, &stack_b, bench);
		i++;
	}
	*head = stack_a;
}

static void flush(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	while (*stack_b)
		pa(stack_b, stack_a, bench);
}

static int get_bit_count(int max_rank)
{
	int	bits;

	bits = 0;
	while (max_rank)
	{
		bits++;
		max_rank >>= 1;
	}
	return (bits);
}
