/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(va_list ptr, const char format);

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format != '%')
			len += ft_ctoa(*format);
		else
		{
			if (!*++format)
				break ;
			len += ft_eval_format(ptr, *format);
		}
		format++;
	}
	va_end(ptr);
	return (len);
}

static int	ft_eval_format(va_list ptr, const char format)
{
	if (format == 'c')
		return (ft_ctoa(va_arg(ptr, int)));
	if (format == 's')
		return (ft_stoa(va_arg(ptr, char *)));
	if (format == 'p')
		return (ft_ptoa(va_arg(ptr, void *)));
	if (format == 'd' || format == 'i')
		return (ft_itoa(va_arg(ptr, int)));
	if (format == 'u')
		return (ft_utoa(va_arg(ptr, unsigned int)));
	if (format == 'x')
		return (ft_xtoa(va_arg(ptr, unsigned int)));
	if (format == 'X')
		return (ft_bigxtoa(va_arg(ptr, unsigned int)));
	if (format == '%')
		return (ft_percenttoa());
	return (0);
}
