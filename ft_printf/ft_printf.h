/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salandri <salandri@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:50 by salandri          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:53 by salandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_for_pointer(long unsigned int address, int *return_value);
void	ft_putchar(char c, int *return_value);
void	ft_putnbr(int nb, int *return_value, int mod);
void	ft_putunsi(unsigned int nb, int *return_value);
void	ft_basicflags(const char *s, int *i, va_list args, int *return_value);
void	ft_puthexa(unsigned int nb, char *base, int *return_value);
void	ft_putstr(char *s, int *return_value);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);

#endif
