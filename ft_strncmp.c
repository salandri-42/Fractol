/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:56:38 by salandri          #+#    #+#             */
/*   Updated: 2024/08/07 20:56:39 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		while (str1[i] && str2[i] && i < n)
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			if (str1[i + 1] == '\0' && str2[i + 1] == '\0')
				return (0);
			i++;
		}
		if (i < n)
			return (str1[i] - str2[i]);
	}
	return (0);
}
