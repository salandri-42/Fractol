/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:55:33 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 00:58:27 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_point	converting_point(t_point toconvert, t_data *img)
{
	t_point	new_pt;

	new_pt.x = (img->xwin_max - img->xwin_min) * (toconvert.x - 0);
	new_pt.x = new_pt.x / 800 + img->xwin_min;
	new_pt.y = (img->ywin_max - img->ywin_min) * (toconvert.y - 0);
	new_pt.y = new_pt.y / 800 + img->ywin_min;
	return (new_pt);
}

void	pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_error(void)
{
	ft_printf("Invalid input ...\nTry with :\n");
	ft_printf("./fractol_bonus mandelbrot\n");
	ft_printf("./fractol_bonus julia\n");
	ft_printf("./fractol_bonus julia 0.285 0.01\n");
	ft_printf("./fractol_bonus burningship\n");
	exit (EXIT_FAILURE);
}

void	if_not_nbr(char *s2)
{
	int	i;
	int	test;

	i = -1;
	test = 0;
	if (s2[0] == '\0')
		print_error();
	if (s2[0] == '.' && s2[1] == '\0')
		print_error();
	while (s2[++i])
	{
		if ((s2[i] < '0' && s2[i] != '-' && s2[i] != '.')
			|| (s2[i] > '9' && s2[i] != '-' && s2[i] != '.')
			|| (s2[i] == '-' && i != 0))
			print_error();
		if (s2[i] == '.' && test == 1)
			print_error();
		if (s2[i] == '.')
			test = 1;
		if (s2[i] == '.' && (s2[i - 1] == '.' || s2[i - 1] == '.'))
			print_error();
	}
}

void	initialize_data(t_data *img)
{
	img->xwin_min = -2;
	img->xwin_max = 2;
	img->ywin_min = -2;
	img->ywin_max = 2;
	img->color_b = 192500;
	img->color_j = 330000;
	img->color_m = 192760;
}
