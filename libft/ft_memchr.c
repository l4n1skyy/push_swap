/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;

	if (n == 0)
		return (NULL);
	mem = (unsigned char *)s;
	while (n-- && *mem++ != (unsigned char)c)
		;
	if (*--mem == (unsigned char)c)
		return (mem);
	return (NULL);
}
