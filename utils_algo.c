/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:57:37 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 23:22:55 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rank_position(t_node *head, int rank)
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
