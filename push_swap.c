#include "push_swap.h"

static void	bench_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
}

static void	bench_putnbr(int number)
{
	char	*str;

	str = ft_itoa(number);
	if (!str)
		return ;
	bench_putstr(str);
	free(str);
}

static void	bench_put_disorder(float disorder)
{
	int	percentage;

	percentage = (int)(disorder * 10000.0f + 0.5f);
	bench_putnbr(percentage / 100);
	write(2, ".", 1);
	if (percentage % 100 < 10)
		write(2, "0", 1);
	bench_putnbr(percentage % 100);
	write(2, "%", 1);
}

static char	*strategy_name(int strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("simple");
	if (strategy == STRATEGY_MEDIUM)
		return ("medium");
	if (strategy == STRATEGY_COMPLEX)
		return ("complex");
	return ("adaptive");
}

static char	*strategy_complexity(int strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n^2)");
	if (strategy == STRATEGY_MEDIUM)
		return ("O(nsqrt(n))");
	return ("O(nlog(n))");
}

void	print_disorder(float disorder)
{
	bench_putstr("disorder: ");
	bench_put_disorder(disorder);
	bench_putstr("\n");
}

void	print_strategy(int strategy, int used_strategy)
{
	bench_putstr("strategy: ");
	bench_putstr(strategy_name(used_strategy));
	bench_putstr(" (requested ");
	bench_putstr(strategy_name(strategy));
	bench_putstr(")\ncomplexity: ");
	bench_putstr(strategy_complexity(used_strategy));
	bench_putstr("\n");
}

void	print_total_operations(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb;
	total += bench->ra + bench->rb + bench->rr;
	total += bench->rra + bench->rrb + bench->rrr;
	bench_putstr("total operations: ");
	bench_putnbr(total);
	bench_putstr("\n");
}

void	print_swap_push(t_bench *bench)
{
	bench_putstr("sa: ");
	bench_putnbr(bench->sa);
	bench_putstr(" sb: ");
	bench_putnbr(bench->sb);
	bench_putstr(" ss: ");
	bench_putnbr(bench->ss);
	bench_putstr(" pa: ");
	bench_putnbr(bench->pa);
	bench_putstr(" pb: ");
	bench_putnbr(bench->pb);
	bench_putstr("\n");
}

void	print_rotate_rrotate(t_bench *bench)
{
	bench_putstr("ra: ");
	bench_putnbr(bench->ra);
	bench_putstr(" rb: ");
	bench_putnbr(bench->rb);
	bench_putstr(" rr: ");
	bench_putnbr(bench->rr);
	bench_putstr(" rra: ");
	bench_putnbr(bench->rra);
	bench_putstr(" rrb: ");
	bench_putnbr(bench->rrb);
	bench_putstr(" rrr: ");
	bench_putnbr(bench->rrr);
	bench_putstr("\n");
}

void	print_benchmark(t_bench *bench, float disorder, int strategy,
	int used_strategy)
{
	print_disorder(disorder);
	print_strategy(strategy, used_strategy);
	print_total_operations(bench);
	print_swap_push(bench);
	print_rotate_rrotate(bench);
}

int	main(int argc, char **argv)
{
	t_node	*head;
	char	**numbers;
	t_bench	bench = {0};
	int		strategy;
	int		benchmark;
	int		used_strategy;
	float	disorder;

	if (argc <= 1)
		return (0);
	numbers = parse_options(argv, &strategy, &benchmark);
	if (!numbers)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	head = create_struct(numbers);
	if (!head)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	disorder = compute_disorder(head);
	used_strategy = select_strategy(&head, strategy, disorder, &bench);
	if (used_strategy < 0)
	{
		ft_llstclear(&head);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (benchmark)
		print_benchmark(&bench, disorder, strategy, used_strategy);
	ft_llstclear(&head);
	return (0);
}

t_node	*handle_fail(t_node **head)
{
	ft_llstclear(head);
	return (NULL);
}
