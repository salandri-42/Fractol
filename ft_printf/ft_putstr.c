/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:05:26 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:05:29 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *return_value)
{
	if (!s)
	{
		write (1, "(null)", 6);
		(*return_value = *return_value + 6);
	}
	while (s && *s)
	{
		write(1, &(*s), 1);
		s++;
		(*return_value)++;
	}
}
