/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/08/30 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n);

char	*ft_itoa(int num)
{
	long	n;
	int		sign;
	int		len;
	char	*dst;

	n = num;
	sign = (n < 0);
	if (sign)
		n = -n;
	len = ft_intlen(n);
	dst = malloc(len + 1 + sign);
	if (!dst)
		return (NULL);
	dst[len + sign] = '\0';
	if (sign)
		dst[0] = '-';
	while (len > 0)
	{
		dst[--len + sign] = n % 10 + '0';
		n /= 10;
	}
	return (dst);
}

static int	ft_intlen(long n)
{
	int	len;

	len = 1;
	while (n > 0)
	{
		n /= 10;
		if (n)
			len++;
	}
	return (len);
}
