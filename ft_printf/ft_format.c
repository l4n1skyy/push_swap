/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ctoa(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_stoa(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (*s)
	{
		ft_ctoa(*s++);
		len++;
	}
	return (len);
}

int	ft_utoa(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_utoa(n / 10);
	len += ft_ctoa(n % 10 + '0');
	return (len);
}

int	ft_itoa(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_stoa("-2147483648"));
	if (n < 0)
	{
		len += ft_ctoa('-');
		n = -n;
	}
	len += ft_utoa(n);
	return (len);
}

int	ft_percenttoa(void)
{
	ft_ctoa('%');
	return (1);
}
