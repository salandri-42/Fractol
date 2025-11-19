/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basicflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:06 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:10 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_basicflags(const char *s, int *i, va_list args, int *return_value)
{
	if (s[*i] == 'd' || s[*i] == 'i')
		ft_putnbr(va_arg(args, int), return_value, 0);
	else if (s[*i] == 'c')
		ft_putchar(va_arg(args, int), return_value);
	else if (s[*i] == '%')
		ft_putchar('%', return_value);
	else if (s[*i] == 's')
		ft_putstr(va_arg(args, char *), return_value);
	else if (s[*i] == 'x')
		ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef",
			return_value);
	else if (s[*i] == 'X')
		ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF",
			return_value);
	else if (s[*i] == 'u')
		ft_putunsi(va_arg(args, unsigned int), return_value);
	else if (s[*i] == 'p')
		ft_for_pointer(va_arg(args, long unsigned int), return_value);
}
