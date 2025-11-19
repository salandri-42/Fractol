/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:56:11 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 13:31:00 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_minilibx(t_data *img, int ac, char *av[])
{
	which_fractal(img, ac, av);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 800, 800, "Fractol");
	if (!(img->win_ptr))
	{
		mlx_destroy_display(img->mlx_ptr);
		free (img->mlx_ptr);
	}
	img->newim_ptr = mlx_new_image(img->mlx_ptr, 800, 800);
	if (!(img->newim_ptr))
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free (img->mlx_ptr);
	}
	img->addr = mlx_get_data_addr(img->newim_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!(img->addr))
	{
		mlx_destroy_image(img->mlx_ptr, img->newim_ptr);
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		mlx_destroy_display(img->mlx_ptr);
		free (img->mlx_ptr);
	}
}

void	ft_destroy(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->newim_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free (img->mlx_ptr);
}

void	ft_redirecting(t_data *img)
{
	if (img->which_fract == 1)
		draw_julia(img);
	else if (img->which_fract == 0)
		draw_mandelbrot(img);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc == 2 || argc == 4)
	{
		init_minilibx(&img, argc, argv);
		img.xwin_min = -2;
		img.xwin_max = 2;
		img.ywin_min = -2;
		img.ywin_max = 2;
		ft_redirecting(&img);
	}
	else
	{
		print_error();
		return (0);
	}
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.newim_ptr, 0, 0);
	mlx_mouse_hook(img.win_ptr, handle_mouse, &img);
	mlx_key_hook(img.win_ptr, handle_key, &img);
	mlx_hook(img.win_ptr, 17, 0, &mlx_loop_end, img.mlx_ptr);
	mlx_loop(img.mlx_ptr);
	ft_destroy(&img);
	return (0);
}
