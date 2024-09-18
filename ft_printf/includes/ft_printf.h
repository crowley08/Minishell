/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:06:57 by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 01:25:50 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef CONV_CHARS
#  define CONV_CHARS "cspdiuxX%"
# endif

# ifndef BASE_DEC
#  define BASE_DEC "0123456789"
# endif

# ifndef BASE_HEX_LOW
#  define BASE_HEX_LOW "0123456789abcdef"
# endif

# ifndef BASE_HEX_UP
#  define BASE_HEX_UP "0123456789ABCDEF"
# endif

int		ft_printf(const char *s, ...);
void	ft_putchar_pf(int *count, const char c);
void	ft_putstr_pf(int *count, const char *s);
void	ft_putnbr_pf(int *count, int n);
void	ft_putnbr_base_pf(int *count, size_t n, const char *base);
void	ft_putaddress_pf(int *count, void *p);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
#endif