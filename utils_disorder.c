/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-xcho <jia-xcho@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:41:20 by jia-xcho          #+#    #+#             */
/*   Updated: 2026/09/21 22:41:20 by jia-xcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (total_pairs == 0)
		return (0.0f);
	return (mistakes * 1.0 / total_pairs);
}
