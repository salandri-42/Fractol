/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:21 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:25 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		return_value;
	va_list	args;

	i = 0;
	return_value = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &return_value);
		else if (s[i] == '%')
		{
			i++;
			ft_basicflags(s, &i, args, &return_value);
		}
		i++;
	}
	va_end(args);
	return (return_value);
}
