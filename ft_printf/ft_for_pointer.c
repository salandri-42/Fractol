/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:36 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:37 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(long unsigned int nb, char *base, int *return_value)
{
	long unsigned int	mod;

	mod = 0;
	if (nb >= 16)
	{
		mod = nb % 16;
		nb = nb / 16;
		puthexa(nb, base, return_value);
		write (1, &base[mod], 1);
		(*return_value)++;
	}
	else if (nb < 16)
	{
		write (1, &base[nb], 1);
		(*return_value)++;
	}
}

void	ft_for_pointer(long unsigned int address, int *return_value)
{
	if (address == 0)
	{
		write (1, "(nil)", 5);
		(*return_value) = (*return_value + 5);
	}
	else
	{
		write (1, "0x", 2);
		*return_value = *return_value + 2;
		puthexa(address, "0123456789abcdef", return_value);
	}
}
