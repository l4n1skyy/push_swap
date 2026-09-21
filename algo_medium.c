#include "push_swap.h"

static int	find_rank_position(t_node *head, int rank);
static void	distribute_bucket(t_chunk_info *info, int lower, int upper);
static void	sort_bucket(t_chunk_info *info, int lower, int upper);
static int	ft_sqrt(int n);

void	medium_sort(t_node **head, t_bench *bench)
{
	t_chunk_info	info;
	t_node			*stack_b;
	int				chunk_size;
	int				upper;
	int				lower;

	stack_b = NULL;
	info.stack_a = head;
	info.stack_b = &stack_b;
	info.bench = bench;
	info.n_node = ft_llstsize(*head);
	info.n_bucket = ft_sqrt(info.n_node) / 2;
	if (info.n_bucket < 1)
		info.n_bucket = 1;
	chunk_size = (info.n_node + info.n_bucket - 1) / info.n_bucket;
	upper = info.n_node;
	while (upper > 0)
	{
		lower = upper - chunk_size;
		if (lower < 0)
			lower = 0;
		distribute_bucket(&info, lower, upper);
		sort_bucket(&info, lower, upper);
		upper = lower;
	}
}

static void	distribute_bucket(t_chunk_info *info, int lower, int upper)
{
	int	size;

	size = ft_llstsize(*info->stack_a);
	while (size-- > 0)
	{
		if ((*info->stack_a)->rank >= lower
			&& (*info->stack_a)->rank < upper)
			pb(info->stack_a, info->stack_b, info->bench);
		else
			ra(info->stack_a, info->bench);
	}
}

static void	sort_bucket(t_chunk_info *info, int lower, int upper)
{
	int	rank;
	int	position;
	int	size;

	rank = upper - 1;
	while (rank >= lower)
	{
		size = ft_llstsize(*info->stack_b);
		position = find_rank_position(*info->stack_b, rank);
		if (position >= 0)
		{
			if (position <= size / 2)
			{
				while (position-- > 0)
					rb(info->stack_b, info->bench);
			}
			else
			{
				position = size - position;
				while (position-- > 0)
					rrb(info->stack_b, info->bench);
			}
			pa(info->stack_b, info->stack_a, info->bench);
		}
		rank--;
	}
}

static int	find_rank_position(t_node *head, int rank)
{
	int	position;

	position = 0;
	while (head)
	{
		if (head->rank == rank)
			return (position);
		head = head->next;
		position++;
	}
	return (-1);
}

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}
