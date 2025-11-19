/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:58 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:00 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *return_value, int mod)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*return_value) = (*return_value) + 11;
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		(*return_value)++;
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		mod = nb % 10 + '0';
		nb = nb / 10;
		ft_putnbr(nb, return_value, 0);
		write (1, &mod, 1);
		(*return_value)++;
	}
	else if (0 <= nb && nb < 10)
	{
		nb = nb + '0';
		write (1, &nb, 1);
		(*return_value)++;
	}
}
