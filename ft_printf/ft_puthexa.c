/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:05:10 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:05:12 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nb, char *base, int *return_value)
{
	unsigned int	mod;

	mod = 0;
	if (nb >= 16)
	{
		mod = nb % 16;
		nb = nb / 16;
		ft_puthexa(nb, base, return_value);
		write (1, &base[mod], 1);
		(*return_value)++;
	}
	else if (nb < 16)
	{
		write (1, &base[nb], 1);
		(*return_value)++;
	}
}
