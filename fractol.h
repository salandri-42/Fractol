/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 20:55:44 by salandri          #+#    #+#             */
/*   Updated: 2024/08/08 13:31:08 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "fractol.h"
# include <unistd.h>
# include <math.h>
# include "ft_printf/ft_printf.h"

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*newim_ptr;
	char	*addr;
	int		which_fract;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	xwin_min;
	float	xwin_max;
	float	ywin_min;
	float	ywin_max;
	float	zoom;
	float	zoom_ite;
	t_point	cte;
}					t_data;

t_point	converting_point(t_point toconvert, t_data *img);
void	ft_redirecting(t_data *img);
void	draw_mandelbrot(t_data *img);
void	pixel_put(t_data *img, int x, int y, int color);
void	mandelbrot_iteration(t_data *img, t_point c, t_point new_c);
void	draw_julia(t_data *img);
void	julia_iteration(t_data *img, t_point z, t_point new_z);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	handle_zoom(t_point mouse, t_data *img);
int		handle_mouse(int button, int x, int y, t_data *img);
int		handle_key(int keycode, t_data *img);
float	fract_atoi(const char *nptr);
float	fract_atoi(const char *nptr);
void	print_error(void);
void	if_not_nbr(char *s2);
void	which_fractal(t_data *img, int ac, char *av[]);

#endif
