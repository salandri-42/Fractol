/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:15 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:25 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsi(unsigned int nb, int *return_value)
{
	unsigned int	mod;

	if (nb >= 10)
	{
		mod = nb % 10 + '0';
		nb = nb / 10;
		ft_putunsi(nb, return_value);
		write (1, &mod, 1);
		(*return_value)++;
	}
	else
	{
		nb = nb + '0';
		write (1, &nb, 1);
		(*return_value)++;
	}
}
