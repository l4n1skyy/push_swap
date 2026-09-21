/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print_benchmark.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:00:17 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:55:04 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	print_disorder(float disorder)
{
	int	percentage;

	percentage = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(percentage / 100, 2);
	ft_putstr_fd(".", 2);
	if (percentage % 100 < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percentage % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(int strategy, int used_strategy)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (used_strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Adaptive / O(n²)\n", 2);
	else if (used_strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

void	print_total_operations(t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss
		+ bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr
		+ bench->rra + bench->rrb + bench->rrr;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
}

void	print_swap_push(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
}

void	print_rotate_rrotate(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

// static char	*get_strategy_name(int strategy)
// {
// 	if (strategy == STRATEGY_SIMPLE)
// 		return ("simple");
// 	if (strategy == STRATEGY_MEDIUM)
// 		return ("medium");
// 	if (strategy == STRATEGY_COMPLEX)
// 		return ("complex");
// 	return ("adaptive");
// }

// static char	*get_complexity(int strategy)
// {
// 	if (strategy == STRATEGY_SIMPLE)
// 		return ("O(n^2)");
// 	if (strategy == STRATEGY_MEDIUM)
// 		return ("O(n*sqrt(n))");
// 	if (strategy == STRATEGY_COMPLEX)
// 		return ("O(n log n)");
// 	return ("adaptive");
// }

// void	print_benchmark(t_bench *bench, float disorder, int strategy)
// {
// }