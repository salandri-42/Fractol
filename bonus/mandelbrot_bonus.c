/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:57:03 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 00:13:26 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	mandelbrot_iteration(t_data *img, t_point c, t_point new_c)
{
	int		i;
	t_point	z;
	float	z_norm;
	float	temp;

	z.x = 0;
	z.y = 0;
	z_norm = 0;
	i = -1;
	while (++i < 200)
	{
		temp = z.x;
		z.x = ((z.x * z.x) - (z.y * z.y)) + new_c.x;
		z.y = (2 * temp * z.y) + new_c.y;
		z_norm = ((z.x * z.x) + (z.y * z.y));
		if (z_norm > 4)
		{
			pixel_put(img, c.x, c.y, i * img->color_m);
			break ;
		}
	}
	if (z_norm <= 4)
		pixel_put(img, c.x, c.y, 0x00000000);
}

void	draw_mandelbrot(t_data *img)
{
	t_point	c;
	t_point	new_c;

	c.x = 0;
	c.y = 0;
	new_c = converting_point(c, img);
	while (c.x < 800)
	{
		while (c.y < 800)
		{
			mandelbrot_iteration(img, c, new_c);
			c.y++;
			new_c = converting_point(c, img);
		}
		c.x++;
		c.y = 0;
		new_c = converting_point(c, img);
	}
}
