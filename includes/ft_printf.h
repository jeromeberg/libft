/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:03:26 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_int(int nb);
int	ft_print_str(char *str);
int	ft_print_char(int c);
int	ft_print_hex(unsigned int hx, int upper);
int	ft_print_uint(unsigned int nb);
int	ft_print_ptr(unsigned long ptr);

#endif