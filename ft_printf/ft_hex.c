/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_puthex(unsigned long n);
static int	ft_hexlen(unsigned long n);

int	ft_ptoa(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_stoa("(nil)"));
	len = ft_stoa("0x");
	len += ft_xtoa((unsigned long)ptr);
	return (len);
}

int	ft_xtoa(unsigned long n)
{
	int		len;
	char	*dst;
	char	*read;

	len = 0;
	dst = ft_puthex(n);
	if (!dst)
		return (0);
	read = dst;
	while (*read)
	{
		*read |= 32;
		ft_ctoa(*read);
		len++;
		read++;
	}
	free(dst);
	return (len);
}

int	ft_bigxtoa(unsigned long n)
{
	int		len;
	char	*dst;
	char	*read;

	len = 0;
	dst = ft_puthex(n);
	if (!dst)
		return (0);
	read = dst;
	while (*read)
	{
		ft_ctoa(*read);
		len++;
		read++;
	}
	free(dst);
	return (len);
}

static char	*ft_puthex(unsigned long n)
{
	char	*map;
	int		len;
	char	*dst;
	char	*write;

	map = "0123456789ABCDEF";
	len = ft_hexlen(n);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	write = dst + len;
	*write-- = '\0';
	while (len > 0)
	{
		*write-- = map[n % 16];
		n /= 16;
		len--;
	}
	return (dst);
}

static int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}
