/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:56:26 by salandri          #+#    #+#             */
/*   Updated: 2024/08/07 23:01:50 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

float	fract_atoi(const char *nptr)
{
	int		i;
	int		j;
	float	number;
	int		sign;

	i = 0;
	j = 0;
	number = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		number = number * 10 + nptr[i++] - '0';
	if (nptr[i++] == '.')
	{
		while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
			number = number + ((nptr[i++] - '0') / (pow(10, ++j)));
	}
	number = number * sign;
	return (number);
}
