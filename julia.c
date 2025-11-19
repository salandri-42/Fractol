/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:56:49 by salandri          #+#    #+#             */
/*   Updated: 2024/08/07 21:09:23 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_iteration(t_data *img, t_point z, t_point new_z)
{
	int		i;
	float	z_norm;
	float	temp;

	i = -1;
	while (++i < 150)
	{
		temp = new_z.x;
		new_z.x = new_z.x * new_z.x - new_z.y * new_z.y + img->cte.x;
		new_z.y = 2 * temp * new_z.y + img->cte.y;
		z_norm = new_z.x * new_z.x + new_z.y * new_z.y;
		if (z_norm > 4)
		{
			pixel_put(img, z.x, z.y, i * 330000);
			break ;
		}
		if (z_norm < 4)
			pixel_put(img, z.x, z.y, 0xffffff);
	}
}

void	draw_julia(t_data *img)
{
	t_point	z;
	t_point	new_z;

	z.x = 0;
	z.y = 0;
	new_z = converting_point(z, img);
	while (z.x < 800)
	{
		while (z.y < 800)
		{
			julia_iteration(img, z, new_z);
			z.y++;
			new_z = converting_point(z, img);
		}
		z.x++;
		z.y = 0;
		new_z = converting_point(z, img);
	}
}
