/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanusri- <lanusri-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by lanusri-          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by lanusri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_ctoa(char c);
int	ft_stoa(char *s);
int	ft_itoa(int n);
int	ft_utoa(unsigned int n);
int	ft_xtoa(unsigned long n);
int	ft_bigxtoa(unsigned long n);
int	ft_ptoa(void *ptr);
int	ft_percenttoa(void);

#endif
