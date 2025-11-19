/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:10:16 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 14:00:52 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	burningship_iteration(t_data *img, t_point c, t_point new_c)
{
	int		i;
	t_point	z;
	float	z_norm;
	float	temp;

	z.x = 0;
	z.y = 0;
	z_norm = 0;
	i = -1;
	while (++i < 100)
	{
		z.x = fabsf(z.x);
		z.y = fabsf(z.y);
		temp = z.x;
		z.x = ((z.x * z.x) - (z.y * z.y)) + new_c.x;
		z.y = (2 * temp * z.y) + new_c.y;
		z_norm = ((z.x * z.x) + (z.y * z.y));
		if (z_norm > 4)
		{
			pixel_put(img, c.x, c.y, i * img->color_b);
			break ;
		}
	}
	if (z_norm <= 4)
		pixel_put(img, c.x, c.y, 0x00000000);
}

void	draw_burningship(t_data *img)
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
			burningship_iteration(img, c, new_c);
			c.y++;
			new_c = converting_point(c, img);
		}
		c.x++;
		c.y = 0;
		new_c = converting_point(c, img);
	}
}

void	which_fractol(t_data *img, int ac, char *av[])
{
	if (ft_strncmp(av[1], "julia", 5) == 0 && ac == 2 && av[1][5] == '\0')
	{
		img->which_fract = 1;
		img->cte.x = -1.476;
		img->cte.y = 0;
	}
	else if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac == 2
		&& av[1][10] == '\0')
		img->which_fract = 0;
	else if (ft_strncmp(av[1], "burningship", 11) == 0 && ac == 2
		&& av[1][11] == '\0')
		img->which_fract = 2;
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ac == 4 && av[1][5] == '\0')
	{
		if_not_nbr(av[2]);
		if_not_nbr(av[3]);
		img->which_fract = 1;
		img->cte.x = fract_atoi(av[2]);
		img->cte.y = fract_atoi(av[3]);
	}
	else
		print_error();
}
