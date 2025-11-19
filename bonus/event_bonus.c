/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:55:57 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 01:05:11 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	handle_mouse_zoom(t_point mouse, t_data *img)
{
	float		xnew_range;
	float		ynew_range;
	float		xpercent;
	float		ypercent;

	mouse = converting_point(mouse, img);
	xnew_range = (img->xwin_max - img->xwin_min) * img->zoom;
	ynew_range = (img->ywin_max - img->ywin_min) * img->zoom;
	xpercent = (img->xwin_max - mouse.x) / (img->xwin_max - img->xwin_min);
	ypercent = (img->ywin_max - mouse.y) / (img->ywin_max - img->ywin_min);
	img->xwin_max = img->xwin_max - ((xnew_range / img->zoom) * xpercent)
		+ (xnew_range * xpercent);
	img->xwin_min = img->xwin_max - xnew_range;
	img->ywin_max = img->ywin_max - ((ynew_range / img->zoom) * ypercent)
		+ (ynew_range * ypercent);
	img->ywin_min = img->ywin_max - ynew_range;
}

int	handle_mouse(int button, int x, int y, t_data *img)
{
	t_point	mouse;

	mouse.x = x;
	mouse.y = y;
	if (button == 4)
		img->zoom = 0.9;
	else if (button == 5)
		img->zoom = 1.1;
	if (button == 4 || button == 5)
		handle_mouse_zoom(mouse, img);
	ft_redirecting(img);
	if (button == 4 || button == 5 || button == 1 || button == 2)
		mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,
			img->newim_ptr, 0, 0);
	return (0);
}

void	handle_key_move(int keycode, t_data *img)
{
	if (keycode == 65363)
	{
		img->xwin_min += (0.2 * (img->xwin_max - img->xwin_min)) / 4;
		img->xwin_max += (0.2 * (img->xwin_max - img->xwin_min)) / 4;
	}
	else if (keycode == 65361)
	{
		img->xwin_min -= (0.2 * (img->xwin_max - img->xwin_min)) / 4;
		img->xwin_max -= (0.2 * (img->xwin_max - img->xwin_min)) / 4;
	}
	else if (keycode == 65362)
	{
		img->ywin_min -= (0.2 * (img->ywin_max - img->ywin_min)) / 4;
		img->ywin_max -= (0.2 * (img->ywin_max - img->ywin_min)) / 4;
	}
	else if (keycode == 65364)
	{
		img->ywin_min += (0.2 * (img->ywin_max - img->ywin_min)) / 4;
		img->ywin_max += (0.2 * (img->ywin_max - img->ywin_min)) / 4;
	}
}

void	handle_key_color(int keycode, t_data *img)
{
	if (keycode == 65470)
	{
		img->color_m = 5;
		img->color_b = 5;
		img->color_j = 5;
	}
	else if (keycode == 65471)
	{
		img->color_m = -10000;
		img->color_b = -10000;
		img->color_j = -700;
	}
	else if (keycode == 65472)
	{
		img->color_m = -500;
		img->color_b = 13181600;
		img->color_j = -60000;
	}
	else if (keycode == 65473)
	{
		img->color_m = 192760;
		img->color_b = 192500;
		img->color_j = 330000;
	}
}

int	handle_key(int keycode, t_data *img)
{
	if (keycode == 65307)
		mlx_loop_end(img->mlx_ptr);
	handle_key_move(keycode, img);
	handle_key_color(keycode, img);
	ft_redirecting(img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->newim_ptr, 0, 0);
	return (0);
}
